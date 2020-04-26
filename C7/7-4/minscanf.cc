#include <stdarg.h>
#include <stdio.h>

void minscanf(const char* fmt, ...);
void getsubfmt(char p, char* subfmt);

int main(){
    int day, year;
    char monthname[20];
    minscanf("%d %s %d", &day, monthname, &year);
    printf("%d %s %d\n", day, monthname, year);
}

void minscanf(const char* fmt, ...){
    va_list ap;
    const char* p;
    char* cp;
    int* ip;
    double* dp;
    char outstr[3];

    va_start(ap, fmt);
    for(p = fmt; *p; p++){
        if(*p != '%'){
            getchar();
            continue;
        }

        switch (*++p)
        {
        case 'd': 
        case 'i':
        case 'o':
        case 'x':
        case 'c':
        case 'u':
            ip = va_arg(ap, int*);
            getsubfmt(*p, outstr);
            scanf(outstr, ip);
            break;

        case 'f':
        case 'e':
        case 'g':
            dp = va_arg(ap, double*);
            getsubfmt(*p, outstr);
            scanf(outstr, dp);
            break;
 
        case 's':
            cp = va_arg(ap, char*);
            getsubfmt(*p, outstr);
            scanf(outstr, cp);
            break;

        default:
            getchar();
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