#ifndef RENDEZ_VOUS_H_INCLUDED
#define RENDEZ_VOUS_H_INCLUDED

#include "date.h"
#include "agenda.h"
#include <time.h>

typedef struct rendez_vous
{
    char *label;
    time_t* start;
    time_t* end;
} t_rdv;

#endif // RENDEZ_VOUS_H_INCLUDED
