#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 200

int string_words_count(char *string);
char *to_words(char *string, char *words);
int letter_count(char *string);
bool is_separator(char character);

static const char separator[] = " ,.?:";

int main(int argc, char const *argv[])
{
        char input[BUFFER_SIZE] = ":,,,,,,,,,";

        printf("Type a paragraph:\n\n");
        // fgets(input, BUFFER_SIZE, stdin);

        printf("%d\n", string_words_count(input));

        return 0;
}

// How many words in the string
int string_words_count(char *string)
{
        int  string_words_count = 0;
        bool prev_is_separator = false;

        for (size_t i = 0; i < strlen(string); i++) {
                for (size_t j = 0; j < strlen(separator); j++) {
                        if (*(string+i) == *(separator+j)) {
                                if (i == 0)
                                        break;
                                if (prev_is_separator == true) {
                                        prev_is_separator = false;
                                        string_words_count--;
                                        break;
                                } else {
                                        prev_is_separator = true;
                                        string_words_count++;
                                        break;
                                }
                        } else if (i == strlen(string)) {
                                string_words_count++;
                        }
                }
        }

        return string_words_count;
}

// Turn paragraph to words
char *to_words(char *sting, char *words)
{
        return words;
}

// How many letters in the string
int letter_count(char *string)
{
        int letter_count = 0;
        return letter_count;
}

// Is separator
// bool is_separator(char character)
// {
//         char separator[] = SEPARATOR;
//
//         for (size_t i = 0; i < strlen(separator); i++) {
//                 if (!strcmp(character, separator[i])) {
//                         return true;
//                 }
//         }
//
//         return false;
// }
