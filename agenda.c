#include "biblio.h"

struct agenda* create_agenda()
{
    struct agenda* agenda;

    agenda = (struct agenda*) malloc(sizeof(struct agenda));

    agenda->events = create_linked_list();
    return agenda;
}

 /**
  * Add rendez_vous to the agenda
  */
void add_rdv(struct agenda* a, struct rendez_vous* rdv)
{
    struct linked_list* e;

    e = create_list_element(rdv);
    list_add(a->events, e);
}

void del_rdv(struct agenda* a, struct linked_list* e)
{
    struct linked_list *pt, *prev;
    pt = a->events;
    while(pt->next != NULL)
    {
        prev = pt;
        pt = pt->next;

        if(pt->data == e->data)
        {
            prev->next = pt->next;
            free(((struct rendez_vous*)pt->data)->start);
            free(((struct rendez_vous*)pt->data)->end);
            free(((struct rendez_vous*)pt->data)->date);
            free(((struct rendez_vous*)pt->data)->label);
            free(pt->data);
            free(pt);
        }
    }
}

struct linked_list* search_by_label(struct agenda* agenda, char* label)
{
    struct linked_list *pt, *matches;

    matches = create_linked_list();
    pt = agenda->events;
    while (pt->next != 0)
    {
        pt = pt->next;
        if(strcmp(((struct rendez_vous*)pt->data)->label, label) == 0)
        {
            list_add(matches, create_list_element(pt->data));
        }

    }
    return matches;
}

struct linked_list* search_by_date(struct agenda* agenda, struct date* date)
{
    struct linked_list *pt, *matches;

    matches = create_linked_list();

    while (pt != NULL)
    {
        if(datecmp(((struct rendez_vous*)pt->data)->date, date) == 0)
        {
            list_add(matches, create_list_element(pt->data));
        }
        pt = pt->next;
    }
    return matches;
}
