#include "biblio.h"

void fprintf_date(FILE* fp, struct date* d)
{
    fprintf(fp, "%d %d %d", d->d, d->m, d->y);
}
void fprintf_time(FILE* fp, struct time* t)
{
    fprintf(fp, "%d %d", t->m, t->h);
}
void save_rdv(FILE* fp, struct linked_list* e)
{
    //not the end of the list
    if(e != NULL)
    {
        struct rendez_vous* rdv = ((struct rendez_vous*)e->data);

        fputc('|', fp); // Delimiter
        fputc('\n', fp);

        fprintf(fp, "%d\n", strlen(rdv->label));
        fprintf(fp, "%s\n", rdv->label);

        fprintf_date(fp, rdv->date);
        fprintf(fp, "\n");
        fprintf_time(fp, rdv->start);
        fprintf(fp, "\n");
        fprintf_time(fp, rdv->end);
        fprintf(fp, "\n");
        save_rdv(fp, e->next);
        fprintf(fp, "\n");
    }
}
void save_agenda(char* filename, struct agenda* a)
{
    FILE* fp;

    fp = fopen(filename, "w+");
    if(fp != NULL)
    {
        save_rdv(fp, a->events->next);
        fclose(fp);
    }
    else
    {
        printf("The file %s could not be opened, saving aborted", filename);
    }
}


void fscanf_date(FILE* fp, struct date* d)
{
    fscanf(fp, "%d %d %d", &d->d, &d->m, &d->y);
}
void fscanf_time(FILE* fp, struct time* t)
{
    fscanf(fp, "%d %d", &t->m, &t->h);
}
struct linked_list* load_rdv(FILE* fp)
{
    int length = 12;
    char* label;
    struct time *start, *end;
    struct date *date;
    struct rendez_vous* rdv = NULL;
    struct linked_list* l;

    char c;
    c = fgetc(fp);
    //not the end of the file
    if(c != EOF)
    {

        while(c != '|' && c != EOF)
        {
            c = fgetc(fp);
        }
        if(c == EOF)
            return NULL;

        start = create_time(0, 0);
        end = create_time(0, 0);
        date = create_date(0, 0, 0);

        fscanf(fp, "%d\n", &length);
        label = (char*) malloc((length+1) * sizeof(char));
        fgets(label, length+1, fp);

        fscanf_date(fp, date);

        fscanf_time(fp, start);
        fscanf_time(fp, end);

        rdv = create_rdv(label, date, start, end);


        show_event(3, rdv);
        l = create_list_element((void*) rdv);
        l->next = load_rdv(fp);
    }
    return l;
}

struct agenda* load_agenda(char* filename)
{
    FILE* fp;
    struct agenda* a = create_agenda();

    fp = fopen(filename, "r");
    if(fp != NULL)
    {
        a->events->next = load_rdv(fp);
        fclose(fp);
    }
    else
    {
        printf("The file %s could not be opened, loading aborted", filename);
    }

    return a;
}
