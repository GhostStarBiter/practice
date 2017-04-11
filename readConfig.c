#include <stdlib.h>
#include <stdio.h>


int readConfig(char* array[]){
    FILE *cnfg;
    if((cnfg = fopen(CONFIG_FILE, "r")) == NULL){
        printf("Could not open config file: %s",strerror(errno));
        return -1;
    };
    char buf[ADDR_NAME_LEN] = {0};
    int c, i=0, j=0, slash_count = 0;
    while(i < N_LOCKED_ADDR &&
          j < ADDR_NAME_LEN &&
          (c = getc(cnfg)) != EOF){
        if(c == '\n'){
            array[i] = calloc(j+1, sizeof(char));
            for(int k=0; k < j+1; k++){
                array[i][k] = buf[k];
                array[i][k+1] = '\0';
            };
            i++;
            j=0;
            slash_count = 0;
            int n = 0;
            while(n < ADDR_NAME_LEN)
                buf[n++] = 0;
        }
        else
        {
            if( c == 47 ){ // ASCII code of '/'
                slash_count++;
                continue;
            }
            if(slash_count == 2){
                buf[j] = (char) c;
                j++;
            }
        }
    }
    fclose(cnfg);
    return 0;
}
