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
    fflush(fp2);
    fclose(fp);
    fclose(fp2);
    assert(fp->cnt == 0);
    assert(fp->base == NULL);
    assert(fp->ptr == NULL);
    assert(fp->flag == 0);
    assert(fp2->cnt == 0);
    assert(fp2->base == NULL);
    assert(fp2->ptr == NULL);
    assert(fp2->flag == 0);
}