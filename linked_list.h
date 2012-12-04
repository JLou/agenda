#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

struct linked_list
{
    void* data;
    struct linked_list* next;
};

struct linked_list* create_list_element(void*);

struct linked_list* create_linked_list();

void list_add(struct linked_list*, struct linked_list*);

#endif // LINKED_LIST_H_INCLUDED
