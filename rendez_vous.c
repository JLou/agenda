t_rdv* create_rdv(char* label, time_t* start, time_t* end)
{
    t_rdv* rdv;
    rdv = (t_rdv*) malloc(sizeof(t_rdv));

    rdv->label = label;
    rdv->end   = end;
    rdv->start = start;

    return rdv;
}
