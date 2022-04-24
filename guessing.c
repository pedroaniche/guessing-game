#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    printf("\n\n");    
    printf("              +                               \n");
    printf("              A                               \n");
    printf("           __/_\\__                           \n");
    printf("          /\\-'o'-/\\            Welcome to   \n");
    printf("         _||:<_>:||_         Guessing Game!   \n");
    printf("        /\\_/=====\\_/\\                      \n");
    printf("       _|:_:_[I]_:_:|_                        \n");
    printf("    _/::::::::::::::::\\_                     \n");
    printf("  _/::::::::::::::::::::\\_                   \n");
    printf("\n\n");

    srand(time(0));
    int secretnumber = rand() % 100;
    int guess = 0;
    int hit = 0;
    int bigger = 0;
    int tries = 0;
    int difficulty = 0;
    int trieslimit = 0;
    double score = 1000;

    while(difficulty < 1 || difficulty > 3) {  
        printf("Difficulty...\n\n");
        printf("\t(1) Easy\n\t(2) Normal\n\t(3) Hard\n\n");
        printf("What is difficulty level? ");
        scanf("%d", &difficulty);
        printf("\n");

        switch(difficulty) {
            case 1:
                trieslimit = 20;
                break;
            case 2:
                trieslimit = 12;
                break;
            case 3:
                trieslimit = 6;
                break;
            default:
                printf("...invalid option, try again...\n\n");
                break;
        }
    }
    
    printf("You have %d tries, let's go!\n\n", trieslimit);

    for(tries = 1; tries <= trieslimit; tries++) {
        printf("What's your guess about the number? ");
        scanf("%d", &guess);
        printf("\nYour guess was %d\n", guess);
        
        hit = guess == secretnumber;
        bigger = guess > secretnumber;
        int remaining = trieslimit - tries;
        
        if(guess < 0) {
            printf("You can't to guess negative numbers\n");
            tries--;
            continue;
        } else if(hit) {
            printf("...\n\n");
            break;
        } else if(bigger) {
            printf("You were wrong, the number is smaller\n");
            printf("You have %d more tries\n\n", remaining);
        } else {
            printf("You were wrong, the number is bigger\n");
            printf("You have %d more tries\n\n", remaining);
        }
        score -= abs(guess-secretnumber)/(double)2;
    }

    if(hit) {
        printf("       .     '     ,      \n");
        printf("         _________        \n");
        printf("      _ /_|_____|_\\ _    \n");
        printf("        '. \\   / .'      \n");
        printf("          '.\\ /.'        \n");
        printf("            '.'           \n");
        printf("\n");
        printf("You hit the nail on the head!\n");
        printf("You got it right in %d tries\n", tries);
        printf("You scored %.1f points\n", score);
    } else {
        printf("      .-.                   \n");
        printf("     (o o)   End the Game!  \n");
        printf("     | O \\     You Lose!   \n");
        printf("      \\   \\               \n");
        printf("       `~~~'                \n");
        printf("\n");
        printf("Try again!\n");
    }

    return 0;
}