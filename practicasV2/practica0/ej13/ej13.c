#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <ctype.h>
#define WORD_SIZE 30

void isItPalindrome(char *word, bool palindrome, int endOfWord, int lastPosition);

int main() {
    char *word;
    int lastPosition, endOfWord;
    bool palindrome;

    word = (char *)malloc(WORD_SIZE * sizeof(char));

    printf("A continuacion ingrese una palabra de hasta %d caracteres\n", WORD_SIZE);
    fgets(word, WORD_SIZE, stdin);

    endOfWord = (strlen(word)) - 1;
    lastPosition = endOfWord - 1;
    palindrome = true;

    for (int i = 0; i < endOfWord; ++i) {
        word[i] = tolower(word[i]);
    }

    isItPalindrome(word, palindrome, endOfWord, lastPosition);

    free(word);
    return 0;
}

void isItPalindrome(char *word, bool palindrome, int endOfWord, int lastPosition) {
    for(int i = 0; i < endOfWord; i++) {
        if(word[i] != word[lastPosition]) {
            palindrome = false;
            printf("No es palindromo.\n");
            break;
        }
        lastPosition--;
    }

    if(palindrome == true) {
        printf("Es un palindromo.\n");
    }
}
