#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playMontyHall();

int main() {
    srand(time(0)); 

    char playAgain;
    do {
        playMontyHall();

        printf("Do you want to play again? (Y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'Y' || playAgain == 'y');

    return 0;
}

void playMontyHall() {
    int carDoor = rand() % 3; 
    int playerChoice;

    printf("Choose a door (0, 1, or 2): ");
    scanf("%d", &playerChoice);

    int montyOpens;
    do {
        montyOpens = rand() % 3;
    } while (montyOpens == carDoor || montyOpens == playerChoice);

    printf("Monty opens door %d and there is a goat.\n", montyOpens);

    char switchChoice;
    printf("Do you want to switch your choice? (Y/n): ");
    scanf(" %c", &switchChoice);

    // If the player chooses to switch
    if (switchChoice == 'Y' || switchChoice == 'y') {
        int newChoice;
        do {
            newChoice = rand() % 3;
        } while (newChoice == playerChoice || newChoice == montyOpens);

        playerChoice = newChoice;
    }

    if (playerChoice == carDoor) {
        printf("Congratulations! You won! The car was behind door %d.\n", carDoor);
    } else {
        printf("Sorry, you lost. The car was behind door %d.\n", carDoor);
    }
}
