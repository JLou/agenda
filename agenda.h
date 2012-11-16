#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

#include "rendez_vous.h"
#include "date.h"

typedef struct agenda
{
    struct rendez_vous **events; //MESUPERBUSY
    int nb_elems;
    int length;
} t_agenda;

#endif // AGENDA_H_INCLUDED
