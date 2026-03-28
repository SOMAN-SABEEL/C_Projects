#include <stdio.h>
#include <time.h>
#include<unistd.h>
#include<stdlib.h>
void fill_time(char *, size_t, int);
void fill_date(char *, size_t);
int input_format();
void clear_screen();

int main()
{
    char time[50], date[100];
    int format = input_format();
    while(1){
    fill_time(time, sizeof(time), format);
    fill_date(date, sizeof(date));
    clear_screen();
    printf("\n\nCurrent Time : %s", time);
    printf("\nDate : %s", date);
    sleep(1);

    }

    return 0;
}
int input_format()
{
    int format;
    printf("\nChoose the time format :");
    printf("\n1. 24 Hour Format");
    printf("\n2. 12 Hour Format (Default)");
    printf("\nMake a choice(1/2) : ");
    scanf("%d", &format);
    return format;
}
void fill_time(char *buffer, size_t size, int format)
{
    time_t raw_time;
    struct tm *current_time;
    time(&raw_time);
    current_time = localtime(&raw_time);
    if (format == 1)
    {
        strftime(buffer, size, "%H:%M:%S", current_time);
    }
    else
    {
        strftime(buffer, size, "%I:%M:%S %p", current_time);
    }
    // return buffer;
}

void fill_date(char * buffer, size_t size){
    time_t raw_date;
    struct tm *current_date;
    time(&raw_date);
    current_date = localtime(&raw_date);
    strftime(buffer, size, "%A %B %d %Y", current_date);
}

void clear_screen(){
    #ifdef _WIN
    system("cls");
    #else
    system("clear");
    #endif
}