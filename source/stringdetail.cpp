#include <stdio.h>
#include <string.h>
#include <cctype>
#include <stdlib.h>

#define BUFFER_SIZE 200
#define BUFFER_LETTER 50

int string_words_count(char *string);
char *to_words(char *string);
int letter_count(char *string);

int main(int argc, char const *argv[])
{
        char *input = reinterpret_cast<char *>(calloc(1, sizeof(char) * BUFFER_SIZE));
        if (input == NULL) {
                printf("Memery allocation failure\n");
                exit(1);
        }

        printf("Type a paragraph:\n\n");
        fgets(input, BUFFER_SIZE, stdin);

        if (string_words_count(input) == 0) {
                printf("No words found\nExit");
        }
        printf("%d\n", string_words_count(input));

        return 0;
}

// How many words in the string
int string_words_count(char *string)
{
        unsigned int  string_words_count = 0;
        bool prev_is_letter = false;

        for (size_t i = 0; i < strlen(string); i++) {
                if (!isalpha(static_cast<int>(*(string + i)))) {
                        if (prev_is_letter) {
                                string_words_count++;
                                prev_is_letter = false;
                        }
                } else {
                        prev_is_letter = true;
                }
        }

        return string_words_count;
}

// Turn paragraph to words
char *to_words(char *string,unsigned int words_count)
{
        char *words;
        words = reinterpret_cast<char *>(calloc(words_count, sizeof(char) * BUFFER_LETTER));
        if (words == NULL) {
                printf("Memery allocation failure\n");
                  exit(1);
        }

        return words;
}

// How many letters in the string
int letter_count(char *string)
{
        int letter_count = 0;
        return letter_count;
}
