#include "biblio.h"

void main_menu()
{
    int n; char loop;
    struct agenda* agenda;
    printf("Welcome to the new cOS calendar APP\n");
    printf("First you need to set the maximum of event the calendar can handle\n");
    scanf("%d", &n);

    agenda = create_agenda(n);


    do
    {
        printf("\n\n1. See your events\n");
        printf("2. Add an event\n");
        printf("3. Search an event\n");
        loop = main_handle_input(agenda);
    } while (loop == 0);
}

void show_events(struct agenda* agenda)
{
    printf("\n\n\n");
    int i;
    if(agenda->nb_elems == 0)
        printf("No event found");
    for(i=0; i < agenda->nb_elems; i++)
    {
        show_event(i+1, agenda->events[i]);
    }
}

void show_event(int n, struct rendez_vous* rdv)
{
    printf("%d. %s\n", n, rdv->label);

    printf("Le %d/%d/%d a %d:%d" , rdv->date->d, rdv->date->m,
           rdv->date->y, rdv->start->h, rdv->start->m);

    printf(" jusqu'a %d:%d", rdv->end->h, rdv->end->m);
}

void add_event_menu(struct agenda* agenda)
{
    char label[1000];
    int d, m, y, hs, ms, he, me;

    struct time *begin, *end;
    struct date *date;

    printf("\nName of the event :");
    fflush(stdin);
    gets(label);

    printf("\nDate (dd/mm/yyyy) :");
    scanf("%d/%d/%d", &d, &m, &y);

    printf("\nStart time (HH:mm) : ");
    scanf("%d:%d", &hs, &ms);

    printf("\nEnd time (HH:mm) : ");
    scanf("%d:%d", &he, &me);

    date  = create_date(d, m, y);

    begin = create_time(hs, ms);
    end   = create_time(he, me);

    struct rendez_vous* rdv = create_rdv(label, date, begin, end);

    add_rdv(agenda, rdv);
}

char main_handle_input(struct agenda* agenda)
{
    char choix, quit = 0;
    char keeplooping = 1;
    do
    {
        keeplooping = 0;
        choix = getch();
        switch(choix)
        {
        case '1':
            show_events(agenda);
            break;
        case '2':
            add_event_menu(agenda);
            break;
        case '3':
            //search_event_menu(agenda);
            break;
        case '4':
            quit = 1;
        default:
            keeplooping = 1;
        }
    }
    while(keeplooping);

    return quit;
}
