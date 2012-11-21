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

int datecmp(struct date* a, struct date* b)
{
    //LOLILOL
    //Stupid but does the job more or less
    return 365 * (a->y - b->y) + 30 * (a->m - b->m) + (a->d - b->d);
}
