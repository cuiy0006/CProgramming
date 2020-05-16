#include <stdio.h>
#include <unistd.h>
#include "malloc_2.h"
#include <stdio.h>

#define NALLOC 1024
#define MAXALLOC 10000000

typedef long Align;
union header {
    struct {
        union header* ptr;
        unsigned size;
    } s;
    Align x;
};

typedef union header Header;

static Header base;
static Header* freep = NULL;


static Header* morecore(unsigned nu){
    char* cp;
    Header* up;

    if(nu < NALLOC)
        nu = NALLOC;
    cp = (char*)sbrk(nu * sizeof(Header));
    if(cp == (char*) -1)
        return NULL;
    
    up = (Header*) cp;
    up->s.size = nu;
    free_2((void*)(up + 1));
    return freep;
}

void* malloc_2(unsigned nbytes){
    if(nbytes > MAXALLOC){
        printf("Requested size %d exceeds max alloc size %d\n", nbytes, MAXALLOC);
        return NULL;
    }

    Header* p;
    Header* prevp;
    unsigned nunits;
    nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;

    if((prevp = freep) == NULL){
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }

    for(p = prevp->s.ptr;; prevp = p, p = p->s.ptr){
        if(p->s.size >= nunits){
            if(p->s.size == nunits)
                prevp->s.ptr = p->s.ptr;
            else{
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
            freep = prevp;
            return (void*)(p + 1);
        }

        if(p == freep)
            if((p = morecore(nunits)) == NULL)
                return NULL;
    }
}

void free_2(void* ap){
    Header* bp;
    Header* p;

    bp = (Header*)ap - 1;

    unsigned byte_size = (bp->s.size - 1) * sizeof(Header); 

    if(byte_size > MAXALLOC){
        printf("Requested to free size %d exceeds max alloc size %d\n", byte_size, MAXALLOC);
        return;
    }

    if(byte_size == 0){
        printf("Requested to free size is 0\n");
        return;
    }

    // break when
    //      p --------------- p->s.ptr
    //              |
    //              bp
    // OR
    //      p->s.ptr ---------- p
    // |                            |
    // bp                           bp
    for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
        if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
            break;
    
    if(bp + bp->s.size == p->s.ptr){
        //printf("merge with next----------------------\n");
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    } else
        bp->s.ptr = p->s.ptr;

    if(p + p->s.size == bp){
        //printf("merge with last----------------------\n");
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    } else
        p->s.ptr = bp;
    freep = p;
}