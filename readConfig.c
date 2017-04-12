#include <stdlib.h>
#include <stdio.h>
#define CONFIG_FILE "/path/to/configuration/file/"
//static const char CONFIG_FILE[] = "/path/to/configuration/file/"

static int readFile(char forbidden[][ADDR_NAME_LEN]){
    FILE *cnfg;

    if((cnfg = fopen(CONFIG_FILE, "r")) == NULL){
        printf("Could not open config file: %s",strerror(errno));
        return -1;
    };
    char buf[ADDR_NAME_LEN] = {0};
    addr_count=0;
    int c, j=0;
    int char_count = 0, slash_count = 0;
    while(addr_count < N_LOCKED_ADDR &&
          j < ADDR_NAME_LEN &&
          (c = getc(cnfg)) != EOF){
        char_count++;
        if(c == '\n'){
            /** this is the case then newline appears before 8 characters have been read ( https:// )
             * it causes no internet address in variable buf **/
            if(buf[0] == 0 && char_count < 9)
                return -1;
            /** delete string "www" if it present on the beginning of the address**/
            if(strstr(buf, "www.") != NULL){
                int n = 0;
                while(buf[n+4] != 0){
                    buf[n] = buf[n+4];
                    n++;
                }
                for(int m = 1; m < 4+1; m++)
                    buf[n+4-m] = 0;
            }
            int buf_len = 0;
            while(buf[buf_len] != 0)
                buf_len++;
            /*
            if(buf[0] != '.'){
                int temp = buf_len;
                for(;temp >= 0; temp--)
                    buf[temp+1] = buf[temp];
                buf[0] = '.';
            }
            */
            while(buf[buf_len] != '.'){
                buf[buf_len] = 0;
                buf_len--;
            }
            buf[buf_len] = 0;

            for(int k=0; k < j+1; k++){
                forbidden[addr_count][k] = buf[k];
                forbidden[addr_count][k+1] = '\0';
            };
            addr_count++;
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

