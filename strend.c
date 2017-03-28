/*
Function searches for find string f at the end of string s.
If it finds it - return 1, otherwise - return 0.
*/


int strend(char* s, char* f) {
    int s_length = 0;
    int f_length = 0;
    for (; *(s + s_length) != '\0'; s_length++);
    for (; *(f + f_length) != '\0'; f_length++);
    if (s_length < f_length)
        return 0; //can't perform operation. s string too small!
    s += s_length;
    f += f_length;
    while (*--s == *--f)
        --f_length;
    if(f_length)
        return 0;
    else
        return 1;
}
