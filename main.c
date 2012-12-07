#include <gtk/gtk.h>
#include "popup.h"

void add(GtkWidget *widget,
                  gpointer  data)
{
    GtkWidget *label = (GtkWidget*) data;
    guint d, m, y;
    gtk_calendar_get_date(widget, &y, &m, &d);
    printf("%d/%d/%d", d, m, y);
    gchar l[100];
    sprintf(l, "%d/%d/%d", d, m, y);

    gtk_label_set_text(data, l);


}
void sig_create_popup(GtkWidget *widget,
                  gpointer  data)
{
    guint d, m, y;
    gtk_calendar_get_date(widget, &y, &m, &d);
    create_popup(data, y, m, d);
}
static gboolean delete_event( GtkWidget *widget,
                              GdkEvent  *event,
                              gpointer   data )
{
    gtk_main_quit ();
    return TRUE;
}
int main (int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *label;
    GtkCalendar *calendar;
    GtkWidget *box;

    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(window, "Awesome calendar");
    gtk_window_set_default_size(window, 500, 300);


    gtk_signal_connect (GTK_OBJECT (window), "destroy",
              GTK_SIGNAL_FUNC (delete_event), NULL);

    calendar = gtk_calendar_new();


    label = gtk_label_new("void");

    gtk_signal_connect (GTK_OBJECT (calendar), "day_selected_double_click",
                GTK_SIGNAL_FUNC (add), label);

    g_signal_connect (GTK_OBJECT (calendar), "day_selected_double_click",
                GTK_SIGNAL_FUNC (sig_create_popup), window);

    box = gtk_vbox_new (FALSE, 0);

    gtk_box_pack_start (GTK_BOX (box), calendar, FALSE, FALSE, 0);
    gtk_box_pack_start (GTK_BOX (box), label, FALSE, FALSE, 0);

    gtk_container_add (GTK_CONTAINER (window), box);
    gtk_widget_show (calendar);
    gtk_widget_show (label);
    gtk_widget_show (box);

    gtk_widget_show (window);

    gtk_main ();

    return 0;
}
