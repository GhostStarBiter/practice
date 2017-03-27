void itoa(uint32_t num, char string[10]){
    char x;
    char tmp[10];
    short i = 0;
    do{
        x = num%10;
        tmp[i] = x + 48;
        ++i;
        tmp[i] = '\0';
    }
    while((num /= 10) != 0);
    short k = 0;
    for(short j = 0; j <= 10; j++){
        if(tmp[10-j]!=0){
            string[k] = tmp[10-j];
            ++k;
            string[k] = '\0';
        }
    }
    return;
}
