#include "complete_f_op.h"
#include <assert.h>

void test_rewrite_speed(int& cnt){
    FILE* fp = fopen("../test/resources/medium_size_file", "r");
    FILE* fp2 = fopen("../test/resources/medium_size_file_copy", "w");

    cnt = 0;
    char c;
    while((c = getc(fp)) != EOF){
        cnt++;
        putc(c, fp2);
    }
    assert(fflush(fp2) != -1);
    assert(fclose(fp) != -1);
    assert(fclose(fp2) != -1);
    assert(fp->cnt == 0);
    assert(fp->base == NULL);
    assert(fp->ptr == NULL);
    assert(fp->flag == 0);
    assert(fp2->cnt == 0);
    assert(fp2->base == NULL);
    assert(fp2->ptr == NULL);
    assert(fp2->flag == 0);
}