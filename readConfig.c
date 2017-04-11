#include <stdlib.h>
#include <stdio.h>
#define CONFIG_FILE "/path/to/configuration/file/"
//static const char CONFIG_FILE[] = "/path/to/configuration/file/"

int readFile(char *array[]){
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
            /** if present delete string "www." from the beginning of the address**/
            if(strstr(buf, "www.") != NULL){
                int n = 0;
                while(buf[n+4] != 0){
                    buf[n] = buf[n+4];
                    n++;
                }
                for(int m = 1; m < 5; m++)
                    buf[n+4-m] = 0;
            }
            address[i] = calloc(j+1, sizeof(char));
            for(int k=0; k < j+1; k++){
                address[i][k] = buf[k];
                address[i][k+1] = '\0';
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
            //ignore characters before "//" and "//" itself
            if( c == 47 ){ // ASCII code of '/'
                slash_count++;
                continue;
            }
            //place in buf characters after "//"
            if(slash_count == 2){
                buf[j] = (char) c;
                j++;
            }
        }
    }
    fclose(cnfg);
}

