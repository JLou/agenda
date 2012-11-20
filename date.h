#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include "biblio.h"


struct time
{
    int h;
    int m;
};

struct date
{
    int d;
    int m;
    int y;
};

struct time* create_time(int, int);

struct date* create_date(int, int, int);

#endif // DATE_H_INCLUDED
