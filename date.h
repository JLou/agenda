#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include "biblio.h"


typedef struct time
{
    int h;
    int m;
} t_time;

typedef struct date
{
    int d;
    int m;
    int y;
} t_date;

struct time* create_time(int, int);

struct date* create_date(int, int, int);

#endif // DATE_H_INCLUDED
