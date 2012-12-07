#include <gtk/gtk.h>
#include "popup.h"

void create_popup(GtkWindow *w, guint y, guint m, guint d)
{
    struct popup p;
    GtkWidget* hbox;
    int i;

    p.window = gtk_dialog_new_with_buttons("Create a rendez-vous",
        GTK_WINDOW(w),
        GTK_DIALOG_MODAL,
        GTK_STOCK_OK,GTK_RESPONSE_OK,
        GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,
        NULL);

        /* Creation de la zone de saisie */
    p.label_entry = gtk_entry_new();
    gtk_container_set_border_width(GTK_DIALOG(p.window), 10);
    gtk_box_set_spacing(GTK_DIALOG(p.window)->vbox, 15);
    hbox = gtk_hbox_new(FALSE, 5);

    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(p.window)->vbox), gtk_label_new("Label:"), TRUE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(p.window)->vbox), p.label_entry, TRUE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(p.window)->vbox), hbox, TRUE, FALSE, 0);

    p.date_entries[0] = gtk_spin_button_new_with_range(1, 31, 1);
    p.date_entries[1] = gtk_spin_button_new_with_range(1, 12, 1);
    p.date_entries[2] = gtk_spin_button_new_with_range(0, 4242, 1);
    gtk_spin_button_set_value(p.date_entries[0], d);
    gtk_spin_button_set_value(p.date_entries[1], m);
    gtk_spin_button_set_value(p.date_entries[2], y);

    p.start_time_entries[0] = gtk_spin_button_new_with_range(0, 24, 1);
    p.start_time_entries[1] = gtk_spin_button_new_with_range(0, 59, 1);

    p.end_time_entries[0] = gtk_spin_button_new_with_range(0, 24, 1);
    p.end_time_entries[1] = gtk_spin_button_new_with_range(0, 59, 1);


    for(i=0; i<3;i++)
    {
        gtk_box_pack_start(GTK_BOX(hbox), p.date_entries[i], TRUE, FALSE, 0);
        if(i < 2)
        {
            GtkWidget *slash = gtk_label_new("/");
            gtk_box_pack_start(GTK_BOX(hbox), slash, TRUE, FALSE, 0);
        }
    }

    hbox = gtk_hbox_new(FALSE, 5);
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(p.window)->vbox), hbox, TRUE, FALSE, 0);

    //GtkWidget* startLabel = gtk_label_new("Start time:");
    gtk_box_pack_start(GTK_BOX(hbox), gtk_label_new("Start time:"), TRUE, FALSE, 0);
    for(i=0; i<2;i++)
    {
        gtk_box_pack_start(GTK_BOX(hbox), p.start_time_entries[i], TRUE, FALSE, 0);
        if(i < 1)
        {
            GtkWidget *slash = gtk_label_new(":");
            gtk_box_pack_start(GTK_BOX(hbox), slash, TRUE, FALSE, 0);
        }
    }


    hbox = gtk_hbox_new(FALSE, 5);
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(p.window)->vbox), hbox, TRUE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(hbox), gtk_label_new("End time:"), TRUE, FALSE, 0);
    for(i=0; i<2;i++)
    {
        gtk_box_pack_start(GTK_BOX(hbox), p.end_time_entries[i], TRUE, FALSE, 0);
        if(i < 1)
        {
            GtkWidget *slash = gtk_label_new(":");
            gtk_box_pack_start(GTK_BOX(hbox), slash, TRUE, FALSE, 0);
        }
    }

    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(p.window)->vbox), hbox, TRUE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(p.window)->vbox), hbox, TRUE, FALSE, 0);



    /* Affichage des elements de la boite de dialogue */
    gtk_widget_show_all(GTK_DIALOG(p.window)->vbox);

    /* On lance la boite de dialogue et on recupere la reponse */
    switch (gtk_dialog_run(GTK_DIALOG(p.window)))
    {
        /* L utilisateur valide */
        case GTK_RESPONSE_OK:
            //sNom = gtk_entry_get_text(GTK_ENTRY(p.label_entry));
            break;
        /* L utilisateur annule */
        case GTK_RESPONSE_CANCEL:
        case GTK_RESPONSE_NONE:
        default:
            break;
    }

    /* Destruction de la boite de dialogue */
    gtk_widget_destroy(p.window);
}
