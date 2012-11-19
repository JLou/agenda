#ifndef RENDEZ_VOUS_H_INCLUDED
#define RENDEZ_VOUS_H_INCLUDED

#include "biblio.h"

typedef struct rendez_vous
{
    char *label;
    struct date* date;
    struct time* start;
    struct time* end;
} t_rdv;

struct rendez_vous* create_rdv(char*, struct date*, struct time*, struct time*);

#endif // RENDEZ_VOUS_H_INCLUDED
