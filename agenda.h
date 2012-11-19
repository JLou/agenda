#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED
#include "agenda.h"


struct agenda
{
    struct rendez_vous **events; //MESUPERBUSY
    int nb_elems;
    int length;
};

struct agenda* create_agenda(int);

void add_rdv(struct agenda*, struct rendez_vous*);


#endif // AGENDA_H_INCLUDED
