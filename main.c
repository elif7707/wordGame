//
//  main.c
//  wordGame
//
//  Created by Elif Zeynep Çetinkaya on 24.05.2024.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    
    int i, j, k, selection_index;
    char guess[6];
    char words[4][10] = {"water", "hello", "shell", "zebra"};
    
    printf("Welcome to Comple!\n");
    printf("Please select a word (1-4): ");
    scanf(" %d", &selection_index);
    
    // Attempt Loop
    for(i = 1; i < 4; i++){
        int totalGuessedWordCount = 0;
        printf("---Attempt #%d of 3---\n",i);
        printf("Your guess: ");
        scanf(" %s",guess);
        
        // To store the result
        char result[6];
        
        // Calculate the Result
        for(j = 0; j < 5; j++){
            int condition = 0;
            char guessedChar  = guess[j];
            // Calculate the Condition
            // 0 -> GuessedChar is not in the word.
            // 1 -> GuessedChar is in the word but in wrong place
            // 2 -> GuessedChar is in the word and in correct place
            for(k = 0; k < 5; k++){
                if(words[selection_index][k] == guessedChar){
                    if(k == j){
                        condition = 2;
                        // If we find the correct position, then break the for loop.
                        break;
                    } else {
                        condition = 1;
                    }
                }
            }

            // Put chars in the result
            if(condition == 0){
                result[j] = '_';
            } else if(condition == 1) {
                result[j] = tolower(guessedChar);
            } else if (condition == 2) {
                totalGuessedWordCount += 1;
                result[j] = toupper(guessedChar);
            }
            
        }
       
        
        if (totalGuessedWordCount == 5) {
            printf("You Win! \n");
            printf("The word was: %s \n", result);
        } else {
            printf("Result: %s\n", result);
        }
    }
    

    return 0;
}
