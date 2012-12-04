#ifndef SAVE_H_INCLUDED
#define SAVE_H_INCLUDED

void fprintf_date(FILE*, struct date*);

void fprintf_time(FILE*, struct time*);

void save_rdv(FILE*, struct linked_list*);

void save_agenda(char*, struct agenda*);


#endif // SAVE_H_INCLUDED
