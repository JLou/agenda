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
        printf("4. Quit this awesomium software\n");
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

    printf(" jusqu'a %d:%d\n", rdv->end->h, rdv->end->m);
}

void show_event_menu(struct agenda* agenda, int index)
{
    printf("\n\n\n INDEX #%d", index);

    char choix, loop;
    printf("%s\n", agenda->events[index]->label);

    printf("Le %d/%d/%d a %d:%d" , agenda->events[index]->date->d, agenda->events[index]->date->m,
           agenda->events[index]->date->y, agenda->events[index]->start->h, agenda->events[index]->start->m);

    printf(" jusqu'a %d:%d\n", agenda->events[index]->end->h, agenda->events[index]->end->m);

    do
    {
        loop = 0;
        printf("\n\n1. Delete this event\n");
        printf("\n\n2. Back to main menu");

        choix = getch();
        switch(choix)
        {
            case '1':
                del_rdv(agenda, index);
                break;
            case '2':
                break;
            default:
                loop = 1;
        }
    }while(loop);
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

void search_event_menu(struct agenda* agenda)
{
    char loop;

    do
    {
        printf("\n\n Search Mode by\n");
        printf("1. Label\n");
        printf("2. Date\n");
        printf("4. Back to main menu\n");
        loop = search_handle_input(agenda);
    } while (loop == 0);

}

void search_by_label_menu(struct agenda* agenda)
{
    char label[1000];
    int i, choice;

    printf("Label a rechercher ? ");
    fflush(stdin);

    gets(label);
    printf("\n\n");

    struct match** matches = search_by_label(agenda, label);
    for(i=0; i<agenda->nb_elems; i++)
    {
        if(matches[i] == 0)
            break;

        show_event(i+1, matches[i]->rdv);
    }

    printf("\nSelect a event by his number\n");
    printf("or press <0> to return to main menu\n\n");
    scanf("%d", &choice);
    if(choice == 0)
        return;
    show_event_menu(agenda, matches[choice-1]->index);

}

void search_by_date_menu(struct agenda* agenda)
{
    int d, m, y, i, choice;

    struct date *date;

    printf("Date to search (dd/mm/yyyy) ? ");
    scanf("%d/%d/%d", &d, &m, &y);

    date  = create_date(d, m, y);

    printf("\n\n");
    struct match** matches = search_by_date(agenda, date);
    for(i=0; i<agenda->nb_elems; i++)
    {
        if(matches[i] == 0)
            break;

        show_event(i+1, matches[i]->rdv);
    }

    printf("\nSelect a event by his number\n");
    printf("or press <0> to return to main menu\n\n");
    scanf("%d", &choice);
    if(choice == 0)
        return;
    show_event_menu(agenda, matches[choice-1]->index);
}

char search_handle_input(struct agenda* agenda)
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
            search_by_label_menu(agenda);
            break;
        case '2':
            search_by_date_menu(agenda);
            break;
        case '3':
            search_event_menu(agenda);
            break;
        case '4':
            quit = 1;
            break;
        default:
            keeplooping = 1;
        }
    } while(keeplooping);

    return quit;
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
            search_event_menu(agenda);
            break;
        case '4':
            quit = 1;
            break;
        default:
            keeplooping = 1;
        }
    }
    while(keeplooping);

    return quit;
}
