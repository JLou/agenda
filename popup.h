#ifndef POPUP_H_INCLUDED
#define POPUP_H_INCLUDED

struct popup
{
    GtkWidget *window;
    GtkWidget *label_entry;
    GtkSpinButton *date_entries[3];
    GtkSpinButton *start_time_entries[2];
    GtkSpinButton *end_time_entries[2];
} t_popup;

#endif // POPUP_H_INCLUDED
