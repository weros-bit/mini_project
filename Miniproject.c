#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void playNumberGuess() {
    int secret = (rand() % 100) + 1, guess, tries = 0;
    printf("\n[Number Guess] I'm thinking of 1-100.\n");

    do {
        printf("Your guess: ");
        if (scanf("%d", &guess) != 1) {
            printf("Please enter a number!\n");
            clearInputBuffer();
            continue;
        }
        tries++;
        if (guess > secret) printf("lower!\n");
        else if (guess < secret) printf("higher!\n");
    } while (guess != secret);

    printf("Bingo! You got it in %d tries.\n", tries);
}

void playRPS() {
    int user, computer = (rand() % 3) + 1;
    printf("\n[RPS] 1:Rock, 2:Paper, 3:Scissors: ");

    if (scanf("%d", &user) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        return;
    }

    if (user < 1 || user > 3) {
        printf("Invalid choice! Pick 1, 2, or 3.\n");
        return;
    }

    char *choices[] = {"", "Rock", "Paper", "Scissors"};
    printf("You: %s | Computer: %s\n", choices[user], choices[computer]);

    if (user == computer) printf("Draw!\n");
    else if ((user == 1 && computer == 3) ||
             (user == 2 && computer == 1) ||
             (user == 3 && computer == 2))
        printf("You Win!\n");
    else
        printf("Computer Wins!\n");
}

void playGuessWord() {
    char *words[] = {
        "apple", "banana", "orange", "grape", "mango",
        "cherry", "peach", "lemon", "berry", "melon"
    };

    char *hints[] = {
        "A common red fruit",
        "A long yellow fruit",
        "A citrus fruit that's also a color",
        "Small fruits that grow in bunches",
        "A tropical fruit with orange flesh",
        "Small red fruits used on desserts",
        "A fuzzy fruit with a pit",
        "A sour yellow citrus fruit",
        "A small sweet fruit (generic)",
        "Large fruit with green rind"
    };

    int count = sizeof(words) / sizeof(words[0]);
    int index = rand() % count;

    char guess[20];
    printf("\n[Guess the Word]\nHint: %s\n", hints[index]);
    printf("Enter word: ");
    scanf("%19s", guess);

    for (int i = 0; guess[i]; i++)
        guess[i] = tolower(guess[i]);

    if (strcmp(guess, words[index]) == 0)
        printf("Correct! 🎉 It was %s.\n", words[index]);
    else
        printf("Wrong! The answer was %s.\n", words[index]);

    clearInputBuffer();
}

int main() {
    int choice;
    srand(time(NULL));

    while (1) {
        printf("\n=====================");
        printf("\n   THE C GAME HUB");
        printf("\n=====================");
        printf("\n1. Number Guessing");
        printf("\n2. Rock Paper Scissors");
        printf("\n3. Guess the Word");
        printf("\n4. Exit");
        printf("\nPick a game: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Enter a number.\n");
            clearInputBuffer();
            continue;
        }

        if (choice == 4) break;

        switch (choice) {
            case 1: playNumberGuess(); break;
            case 2: playRPS(); break;
            case 3: playGuessWord(); break;
            default: printf("Try again (1-4).\n");
        }
    }

    printf("Goodbye!\n");
    return 0;
}