#include "agenda.h"

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
