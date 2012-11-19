#include "biblio.h"

struct date* create_date(int d, int m, int y)
{
    struct date* date = (struct date*) malloc(sizeof(struct date));

    date->d = d;
    date->m = m;
    date->y = y;

    return date;
}

struct time* create_time(int h, int m)
{
    struct time* time = (struct time*) malloc(sizeof(struct time));

    time->h = h;
    time->m = m;

    return time;
}
