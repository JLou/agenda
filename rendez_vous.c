#include "biblio.h"

struct rendez_vous* create_rdv(char* label, struct date* date, struct time* start, struct time* end)
{
    struct rendez_vous* rdv;
    rdv = (struct rendez_vous*) malloc(sizeof(struct rendez_vous));
    rdv->label = (char*) malloc(strlen(label) * sizeof(char));
    strcpy(rdv->label, label);
    rdv->date  = date;
    rdv->end   = end;
    rdv->start = start;

    return rdv;
}
