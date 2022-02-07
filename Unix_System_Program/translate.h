#ifndef TRANSLATE_H
#define TRANSLATE_H

#define TRUE (1)
#define FALSE (0)

typedef enum error_code {
    ERROR_CODE_WRONG_ARGUMENTS_NUMBER = 1,
    ERROR_CODE_INVALID_FLAG,
    ERROR_CODE_INVALID_FORMAT,
    ERROR_CODE_ARGUMENT_TOO_LONG,
    ERROR_CODE_INVALID_RANGE
} error_code_t;

int translate(int argc, const char** argv);
void change_letters(char* str1, char* str2);
void check_repeatition(char* str1, char* str2);
void check_case_insensitive(char* str1, char* str2);
int escape_character(char* str1);
int check_range(char* str);
#endif /* TRANSLATE_H */

