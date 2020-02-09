#include "year_month_day_conversion_p.h"

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year_p(int year, int month, int day){
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    char* months = daytab[leap];
    char* final = months + month;
    while(months < final){
        day += *months;
        ++months;
    }
    return day;
}

void month_day_p(int year, int yearday, int* pmonth, int* pday){
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    char* months = daytab[leap];
    while(yearday > *months){
        yearday -= *months;
        ++months;
    }

    *pmonth = months - daytab[leap];
    *pday = yearday;
}