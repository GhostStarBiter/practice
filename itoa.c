#define STR_LEN 5
void itoa(int num, char string[STR_LEN]){
    char x;
    char tmp[STR_LEN];
    memset(tmp, 0, STR_LEN);
    short i = 0;
    do{
        x = num%10;
        tmp[i] = x + 48;
        ++i;
        tmp[i] = '\0';
    }
    while((num /= 10) != 0);
    short k = 0;
    for(short j = 0; j <= STR_LEN; j++){
        if(tmp[STR_LEN-j]!=0){
            string[k] = tmp[STR_LEN-j];
            ++k;
            string[k] = '\0';
        }
    }
    return;
}
