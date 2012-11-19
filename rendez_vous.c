#include "biblio.h"

struct rendez_vous* create_rdv(char* label, struct date* date, struct time* start, struct time* end)
{
    struct rendez_vous* rdv;
    rdv = (t_rdv*) malloc(sizeof(t_rdv));

    rdv->label = label;
    rdv->date  = date;
    rdv->end   = end;
    rdv->start = start;

    return rdv;
}
