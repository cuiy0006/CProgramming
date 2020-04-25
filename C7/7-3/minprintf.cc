#include <stdarg.h>
#include <stdio.h>

void minprintf(const char* fmt, ...);
void getsubfmt(char p, char* subfmt);

int main(){
    int a = -12345678;
    unsigned int ua = 12345678;
    float b = 1.2345678;
    double c = 123.4567890123;
    const char* s = "abcdefghijk";
    int* pa = &a;
    char v = 'v';

    minprintf("%d %i %o %x %c %u\n", a, a, a, a, v, ua);
    minprintf("%f %e %g\n", b, c, c);
    minprintf("%s %p\n", s, pa);
}

void minprintf(const char* fmt, ...){
    va_list ap;
    const char* p;
    char* sval;
    void* pval;
    int ival;
    double dval;
    char outstr[3];

    va_start(ap, fmt);
    for(p = fmt; *p; p++){
        if(*p != '%'){
            putchar(*p);
            continue;
        }

        switch (*++p)
        {
        case 'd': 
        case 'i':
        case 'o':
        case 'x':
        case 'X':
        case 'c':
        case 'u':
            ival = va_arg(ap, int);
            getsubfmt(*p, outstr);
            printf(outstr, ival);
            break;

        case 'f':
        case 'e':
        case 'E':
        case 'g':
        case 'G':
            dval = va_arg(ap, double);
            getsubfmt(*p, outstr);
            printf(outstr, dval);
            break;

        case 's':
            sval = va_arg(ap, char*);
            getsubfmt(*p, outstr);
            printf(outstr, sval);
            break;
        
        case 'p':
            pval = va_arg(ap, void*);
            getsubfmt(*p, outstr);
            printf(outstr, pval);
            break;

        default:
            putchar(*p);
            break;
        }
    }
    va_end(ap);
}

void getsubfmt(char p, char* subfmt){
    subfmt[0] = '%';
    subfmt[1] = p;
    subfmt[2] = '\0';
}