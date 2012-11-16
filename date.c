t_date* create_date(int d, int m, int y)
{
    t_date* d = (t_date*) malloc(sizeof(t_date));

    d->d = d;
    d->m = m;
    d->y = y;

    return d;
}

t_time* create_time(int h, int m)
{
    t_time* t = (t_time*) malloc(sizeof(t_time));

    t->h = h;
    t->m = m;

    return t;
}
