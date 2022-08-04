#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

void DMY_MonthDY(char *buffer, const char *str){
    printf("%s\n", str);
    char day[3];
    char month[3];
    char year[5];
    //char buffer_day[];
    char buffer_month[15];
    //char buffer_year[];
    
    strncpy(day, str, 2);
    day[2] = '\0';
    strncpy(month, str+3, 2);
    month[2] = '\0';
    strncpy(year, str+6, 4);
    year[4] = '\0';

    if(day[0] == '0'){
        day[0] = ' ';
    }

    //printf(": %s %s %s\n", day, month, year);
    
    if(strcmp(month,"01") == 0){
        strcpy(buffer_month, "Janurary  ");
    }else if(strcmp(month,"02") == 0){
        strcpy(buffer_month, "February  ");
    }else if(strcmp(month,"03") == 0){
        strcpy(buffer_month, "March     ");
    }else if(strcmp(month,"04") == 0){
        strcpy(buffer_month, "April     ");
    }else if(strcmp(month,"05") == 0){
        strcpy(buffer_month, "May       ");
    }else if(strcmp(month,"06") == 0){
        strcpy(buffer_month, "June      ");
    }else if(strcmp(month,"07") == 0){
        strcpy(buffer_month, "July      ");
    }else if(strcmp(month,"08") == 0){
        strcpy(buffer_month, "August    ");
    }else if(strcmp(month,"09") == 0){
        strcpy(buffer_month, "September ");
    }else if(strcmp(month,"10") == 0){
        strcpy(buffer_month, "October   ");
    }else if(strcmp(month,"11") == 0){
        strcpy(buffer_month, "November  ");
    }else if(strcmp(month,"12") == 0){
        strcpy(buffer_month, "December  ");
    }
    
    //printf("%s.\n", buffer_month);

    strcpy(buffer, buffer_month);
    strcat(buffer, day);
    strcat(buffer, ", ");
    strcat(buffer, year);
    //printf("! %s\n", buffer);

}
void MonthDY_DMY(char *buffer, const char *str){
    char day[4];
    char month[15];
    char year[6];
    int section = 0;
    int position = 0;
    char buffer_month[4];
    int i = 0;
    while(str[i] != '\0'){
        if(isalpha(str[i]) == 0 && i>1 && section == 0){
            section = 1;
            month[position] = '\0';
            position = 0;
        }
        if(str[i] == ','){
            section = 2;
            day[position] = '\0';
            position = 0;
        }
        if(section == 0){
            month[position] = str[i];
            position+=1;
        }
        
        if(section == 1 && isdigit(str[i])){
            day[position] = str[i];
            position+=1;
        }
        if(section == 2 && isdigit(str[i])){
            year[position] = str[i];
            position+=1;
        }
        i+=1;
        if(str[i] == '\0'){
            year[position+1] = '\0';
        }
    }
    //printf("%s %s %s\n", month, day, year);

    if(day[1] == '\0'){
        day[2] = '\0';
        day[1] = day[0];
        day[0] = '0';
    }

    if(strcmp(month,"Janurary") == 0){
        strcpy(buffer_month, "01");
    }else if(strcmp(month,"February") == 0){
        strcpy(buffer_month, "02");
    }else if(strcmp(month,"March") == 0){
        strcpy(buffer_month, "03");
    }else if(strcmp(month,"April") == 0){
        strcpy(buffer_month, "04");
    }else if(strcmp(month,"May") == 0){
        strcpy(buffer_month, "05");
    }else if(strcmp(month,"June") == 0){
        strcpy(buffer_month, "06");
    }else if(strcmp(month,"v") == 0){
        strcpy(buffer_month, "07");
    }else if(strcmp(month,"August") == 0){
        strcpy(buffer_month, "08");
    }else if(strcmp(month,"September") == 0){
        strcpy(buffer_month, "09");
    }else if(strcmp(month,"October") == 0){
        strcpy(buffer_month, "10");
    }else if(strcmp(month,"November") == 0){
        strcpy(buffer_month, "11");
    }else if(strcmp(month,"December") == 0){
        strcpy(buffer_month, "12");
    }

    
    strcpy(buffer, day);
    strcat(buffer, "/");
    strcat(buffer, buffer_month);
    strcat(buffer, "/");
    strcat(buffer, year);
    
}

int main(){
char format1[12][11] = { "01/01/1970"
                       , "10/02/1763"
                       , "15/03/0044"
                       , "18/04/1982"
                       , "05/05/1789"
                       , "06/06/1944"
                       , "01/07/1867"
                       , "03/08/1492"
                       , "02/09/1945"
                       , "24/10/1917"
                       , "11/11/1918"
                       , "08/12/1980"
                       };
char format2[12][19] = { "January    1, 1970" // First Day of History (according to computers)
                       , "February  10, 1763" // France cedes Canada to England
                       , "March     15,   44" // Assassination of Julius Caesar
                       , "April     18, 1982" // Canada Achieves Sovereignty 
                       , "May        5, 1789" // French Revolution
                       , "June       6, 1944" // D-Day Landings of WWII
                       , "July       1, 1867" // Confederation of Canada
                       , "August     3, 1492" // Christopher Columbus Sets Sail for the Americas
                       , "September  2, 1945" // WWII Surrender of Japan
                       , "October   24, 1917" // October Revolution (Julian Calendar)
                       , "November  11, 1918" // WWI Armistice
                       , "December   8, 1980" // Murder of John Lennon
                       };
    
    char buffer1[12][11];
    char buffer2[12][19];
    
    printf ("-- DD\\MM\\YY to Month DD, YYYY\n");
    for (int i = 0; i < 12; i++) {
        printf("%s\n", format1[i]);
        DMY_MonthDY(buffer2[i], format1[i]);
        printf("-> \"%s\"\n", buffer2[i]);
    }
    
    
    printf ("\n\n-- Month DD, YYYY to DD\\MM\\YY\n");
    for (int i = 0; i < 12; i++) {
        printf("%s\n", format2[i]);
        MonthDY_DMY(buffer1[i], format2[i]);
        printf("-> \"%s\"\n", buffer1[i]);
    }
}

