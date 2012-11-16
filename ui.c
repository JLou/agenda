void main_menu(t_agenda* agenda)
{
    printf("Welcome to the new cOS calendar APP\n");
    printf("1. See your events\n");
    printf("2. Add an event\n");
    printf("3. Search an event\n");

    main_handle_input(agenda);
}

void show_events(t_agenda* agenda)
{
    int i;
    for(i=0; i < agenda->nb_elems; i++)
    {
        show_event(i+1, agenda->events[i]);
    }
}

void show_event(int n, t_rdv* rdv)
{
    printf("%d. %s\n", n, rdv->label);
    char t[5]; char d[8];
    strftime(t, 5, "%H:%M", rdv->start);
    strftime(d, 8, "%x", rdv->start)
    printf("Le %s a %s" , d, t);

    strftime(t, 5, "%H:%M", rdv->end);
    printf(" à %s", t);
}

void add_event_menu(t_agenda* agenda)
{
    char label[1000];
    int d; int m; int y;
    int hs; int ms; int he; int me;

    printf("\nName of the event :");
    fflush(stdin);
    gets(label);

    printf("\nDate (dd/mm/yyyy) :");
    scanf("%d/%d/%d", &d, &m, &y);

    printf("\nStart time (HH:mm) : ")
    scanf("%d:%d", &hs; &ms);

    printf("\nEnd time (HH:mm) : ")
    scanf("%d:%d", &he; &me);
}

void main_handle_input(t_agenda* agenda)
{
    char choix;
    char keeplooping = 1;
    do
    {
        keeplooping = 0;
        choix = getchar();
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
            default:
                keeplooping = 1;
        }

    } while(keeplooping);
}
