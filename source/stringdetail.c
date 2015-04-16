#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 200
#define BUFFER_LETTER 50

size_t string_words_count(char *string);
char **to_words(char *string, size_t words_count);
size_t letter_count(char *string);
char **sort(char *words[]);


int main(int argc, char const *argv[])
{
        char *input = NULL;

        switch (argc) {
        case 1:
                input = (char *)calloc(1, sizeof(char) * BUFFER_SIZE);
                if (input == NULL) {
                        printf("Memery allocation failure\n");
                        exit(1);
                }

                printf("Type a paragraph:\n\n");
                fgets(input, BUFFER_SIZE, stdin);
                if (string_words_count(input) == 0) {
                        printf("No words found\nExit");
                }
                break;
        case 2: {
                size_t strlenth = strlen(argv[1]);
                printf("%zu\n", strlenth);
                input = (char *)malloc(sizeof(char) * (strlenth + 1));
                printf("%zu\n", strlen(input));
                for (size_t i = 0; i < strlenth; i++)
                        *(input + i) = *(argv[1] + i);
                *(input + strlenth) = '\n';
                *(input + strlenth + 1) = '\0';
                break;
        }

        default:
                printf("Too much str!\n");
                exit(1);
        }

        printf("%zu\n", string_words_count(input));
        printf("%zu\n", letter_count(input));

        return 0;
}

// How many words in the string
size_t string_words_count(char *string)
{
        size_t string_words_count = 0;
        bool prev_isletter = false;

        for (size_t i = 0, strlenth = strlen(string); i < strlenth; i++) {
                if (isalpha((int)*(string + i))) {
                        prev_isletter = true;
                } else if(prev_isletter) {
                        string_words_count++;
                        prev_isletter = false;
                }
        }

        return string_words_count;
}

// Turn paragraph to words
char **to_words(char *string, size_t words_count)
{
        char **pWords = (char **)calloc(words_count, sizeof(char *));
        if (pWords == NULL) {
                printf("Memery allocation failure\n");
                exit(1);
        }
        bool new_word = false;



        for (size_t i = 0, j = 0, strlenth = strlen(string); i < strlenth; i++) {
                if (isalpha((int)*(string + i))) {
                } else {
                }
        }

        return pWords;
}

// How many letters in the string
size_t letter_count(char *string)
{
        size_t letter_count = 0;
        int i = 0;
        while (*(string + i) != '\0') {
                if (isalpha((int)*(string + i)))
                        letter_count++;
                i++;
        }
        return letter_count;
}

char **sort(char **words) {

        return words;
}
