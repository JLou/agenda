#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED
#include "biblio.h"


struct agenda
{
    struct rendez_vous **events; //MESUPERBUSY
    int nb_elems;
    int length;
};

struct match
{
    struct rendez_vous* rdv;
    int index;
};
struct agenda* create_agenda(int);

void add_rdv(struct agenda*, struct rendez_vous*);

void del_rdv(struct agenda*, int);

struct match** search_by_label(struct agenda*, char*);

struct match** search_by_date(struct agenda*, struct date*);


#endif // AGENDA_H_INCLUDED
