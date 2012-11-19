#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED
#include "agenda.h"
#include "biblio.h"

void main_menu();

void show_events(struct agenda*);

void show_event(int, struct rendez_vous*);

void add_event_menu(struct agenda*);

char main_handle_input(struct agenda*);

#endif // UI_H_INCLUDED
