t_agenda* create_agenda(int n)
{
    t_agenda* agenda;

    agenda = (t_agenda*) malloc(sizeof(t_agenda));

    // pas cohérent
    agenda->events = (struct rendez_vous**) malloc(n * sizeof(t_rdv*));
    agenda->length = n;
    agenda->nb_elems = 0;
    return agenda;
}

void add_rdv(t_agenda* a, t_rdv* rdv)
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
