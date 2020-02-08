#include "year_month_day_conversion.h"

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day){
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    int day_of_month = daytab[leap][month];
    if(year < 0 || month <= 0 || month > 12 || day <= 0 || day > day_of_month)
        return -1;

    for(i = 1; i < month; ++i)
        day += daytab[leap][i];
    return day;
}

void month_day(int year, int yearday, int* pmonth, int* pday){
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    int max_yearday = leap == 0? 365: 366;
    if(year < 0 || yearday > max_yearday){
        *pmonth = -1;
        *pday = -1;
        return;
    }

    for(i = 1; yearday > daytab[leap][i]; ++i)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}