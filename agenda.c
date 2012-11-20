#include "biblio.h"

struct agenda* create_agenda(int n)
{
    struct agenda* agenda;

    agenda = (struct agenda*) malloc(sizeof(struct agenda));

    // pas cohérent
    agenda->events = (struct rendez_vous**) malloc(n * sizeof(struct rendez_vous*));
    agenda->length = n;
    agenda->nb_elems = 0;
    return agenda;
}

void add_rdv(struct agenda* a, struct rendez_vous* rdv)
{
    //Overflow
    if(a->length <= a->nb_elems)
    {
        printf("La capacité maximale est atteinte");
        return;
    }
    a->events[a->nb_elems] = rdv;
    a->nb_elems++;
}

void del_rdv(struct agenda* a, int index)
{
    struct rendez_vous* tmp = a->events[index];

    a->events[index] = a->events[a->nb_elems-1];
    a->events[a->nb_elems-1] = tmp;
    free(tmp->date);
    free(tmp->end);
    free(tmp->start);
    free(tmp);
    a->events[a->nb_elems-1] = 0;
    a->nb_elems--;
}

struct match* create_match(struct rendez_vous* rdv, int index)
{
    struct match* m = (struct match*) malloc(sizeof(struct match));
    m->rdv = rdv;
    m->index = index;
}

struct match** search_by_label(struct agenda* agenda, char* label)
{
    int i, j;
    j = 0;
    struct match** matches = (struct match**) malloc(agenda->nb_elems * sizeof(struct match*));
    for(i=0; i<agenda->nb_elems; i++)
    {
        if(strcmp(agenda->events[i]->label, label) == 0)
        {
            matches[j] = create_match(agenda->events[i], i);
            j++;
        }
    }
    if(j != i)
    {
        matches[j] = 0;
    }

    return matches;
}

struct match** search_by_date(struct agenda* agenda, struct date* date)
{
    int i, j;
    j = 0;
    struct match** matches = (struct match**) malloc(agenda->nb_elems * sizeof(struct match*));
    for(i=0; i<agenda->nb_elems; i++)
    {
        if(datecmp(agenda->events[i]->date, date) == 0)
        {
            matches[j] = create_match(agenda->events[i], i);
            j++;
        }
    }
    if(j != i)
    {
        matches[j] = 0;
    }

    return matches;
}

