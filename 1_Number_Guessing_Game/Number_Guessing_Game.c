#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){

    int random, guess, attempt = 0;
    printf("\nWelcome to the world of guessing : ");
    srand(time(NULL));
    random = rand() % 100 ;
    do {
        printf("\nGuess the number between (1 - 100) : ");
        scanf("%d", &guess);
        attempt++;
        if(guess > random){
            printf("\nThe number is smaller.");
        } else if (guess < random){
            printf("\nThe number is greater.");
        } else if(guess == random){
            printf("\nCongrats, u guessed the number in %d attempts", attempt);
        }
    }while(random != guess);

    printf("\nGuess game developed by : Soman Sabeel");
    return 0;
}