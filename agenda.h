#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED
#include "biblio.h"


struct agenda
{
    struct linked_list *events; //MESUPERBUSY
};

struct agenda* create_agenda();

void add_rdv(struct agenda*, struct rendez_vous*);

void del_rdv(struct agenda*, struct linked_list*);

struct linked_list* search_by_label(struct agenda*, char*);

struct linked_list* search_by_date(struct agenda*, struct date*);


#endif // AGENDA_H_INCLUDED
