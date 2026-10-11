/*
The following function supposedly creates an identical copy of a string. What's wrong with the function?

char *duplicate(const char *p)
{
    char *q
    
    strcpy(q,p);
    return q;
}

pointer q is not initialized. Thus, the statement copies the string pointed to by p into some unknown area of memory


*/