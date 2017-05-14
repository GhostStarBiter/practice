#define STR_LEN 5
static void custom_itoa(int num, char string[STR_LEN]){
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
    while(((num /= 10) != 0) && (i < STR_LEN));
    short k = 0;
    for(; k < i; k++){
        string[k] = tmp[i-k-1];
    }
    string[k+1] = tmp[i];
    return;
}
