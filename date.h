#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include "rendez_vous.h"
#include "agenda.h"
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

#endif // DATE_H_INCLUDED
