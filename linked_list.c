#include "biblio.h"

struct linked_list* create_list_element(void* data)
{
    struct linked_list* head = (struct linked_list*) malloc(sizeof(struct linked_list));
    head->data = data;
    head->next = 0;
    return head;
}

struct linked_list* create_linked_list()
{
    return create_list_element((void *)0);
}

void list_add(struct linked_list* head, struct linked_list* e)
{
    e->next = head->next;
    head->next = e;
}
