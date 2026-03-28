#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
const int Bar_Length = 50;

typedef struct {
    int id;
    int progress;
    int step;
}Task;

const int Max_Tasks = 5;
void print_bar(Task task);
void clear_screen();

int main()
{
    srand(time(NULL));
    Task tasks[Max_Tasks];

    for ( int i = 0; i < Max_Tasks; i++){
        tasks[i].id = i+1;
        tasks[i].progress = 0;
        tasks[i].step  = rand() % 5 + 1; 
    }
    int tasks_incomplete = 1;
    while(tasks_incomplete) {
        tasks_incomplete = 0;
        clear_screen();
        for (int i = 0; i < Max_Tasks; i++){
            tasks[i].progress += tasks[i].step;
            if (tasks[i].progress > 100){
                tasks[i].progress = 100;
            } else if(tasks[i].progress < 100){
              tasks_incomplete =  1;
            }
            print_bar(tasks[i]);
            
        }
        
        sleep(1);
    }

    printf("\nAll tasks completed");

    return 0;
}

void print_bar(Task task)
{
    int bars_to_show = (task.progress * Bar_Length / 100);
    printf("\nTask %d: [", task.id);
    for (int i = 0; i < Bar_Length; i++)
    {
        if (i < bars_to_show)
        {
            printf("=");
        }
        else
        {
            printf(" ");
        }
    }
    printf("] %d%%", task.progress);
}

void clear_screen(){
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

}