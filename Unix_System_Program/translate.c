#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "translate.h"

#define ARGUMENT_LENGTH (512)

void change_letters(char* str1, char* str2)
{
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    size_t count = 0;
    int c;
    char* p = NULL;
    char* q = NULL;
    char* temp_p = NULL;
    char* temp_q = NULL;
    p = str1;
    q = str2;
    i = strlen(p);
    j = strlen(q);
    temp_p = p;
    temp_q = q;
    c = getchar();
    while (c != EOF) {
        if (i <= j) {
            for (k = 0; k < i; ++k) {
                if (c == *p) {
                    c = *q;
                    goto print_out;
                }
                p++;
                q++;
            }
        } else {
            for (k = 0; k < i; ++k) {
                if (c == *p) {
                    c = *q;
                    goto print_out;
                }
                p++;
                count++;
                if (count < j) {
                    q++;
                }
            }
        }
    print_out:
        putchar(c);
        c = getchar();
        p = temp_p;
        q = temp_q;
        count = 0;
    }
}

void check_repeatition(char* str1, char* str2)
{
    size_t i;
    size_t j;
    size_t k;
    size_t count = 0;
    char* p = NULL;
    char* q = NULL;
    p = str1;
    q = str2;
    k = strlen(str1);
    for (i = 0; i < k; ++i) {
        if (*str1 == 92) {
            continue;
        }
        for (j = 1; j < k; ++j) {
            if (*str1 == *(str1 + j)) {
                count++;
            }
        }
        if (count != 0) {
            while (*str1 != 0) {
                *str1 = *(str1 + 1);
                str1++;
                *str2 = *(str2 + 1);
                str2++;
            }
            str1 = p;
            str2 = q;
            count = 0;
        } else {
            str1++;
            str2++;
        }
    }
    str1 = p;
    str2 = q;
}

void check_case_insensitive(char* str1, char* str2)
{
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    size_t count = 0;
    int c;
    char* p = NULL;
    char* q = NULL;
    char* temp_p = NULL;
    char* temp_q = NULL;
    char temp_character;
    p = str1;
    q = str2;
    i = strlen(p);
    j = strlen(q);
    temp_p = p;
    temp_q = q;
    c = getchar();
    while (c != EOF) {
        if (c == '\\') {
            c = getchar();
            continue;
        }
        if (i <= j) {
            for (k = 0; k < i; ++k) {
                temp_character = c;
                c = tolower(c);
                if (c == *p) {
                    c = *q;
                    goto print_out;
                }
                p++;
                q++;
                c = temp_character;
            }
        } else {
            for (k = 0; k < i; ++k) {
                temp_character = c;
                c = tolower(c);
                if (c == *p) {
                    c = *q;
                    goto print_out;
                }
                p++;
                count++;
                if (count < j) {
                    q++;
                }
                c = temp_character;
            }
        }
    print_out:
        putchar(c);
        c = getchar();
        p = temp_p;
        q = temp_q;
        count = 0;
    }
    
}

int escape_character(char* str)
{
    size_t str_len = 0;
    char* p = str;
    char* q = NULL;
    str_len = strlen(str);
    while (*str != '\0') {
        if (*str == '\\') {
            if (*(str + 1) == '\\') {
                *str = '\\';
                q = str + 1;
                while (*q != '\0') {
                    *q = *(q + 1);
                    q++;
                }
                str++;
            } else if (*(str + 1) == 'a') {
                *str = '\a';
                q = str + 1;
                while (*q != '\0') {
                    *q = *(q + 1);
                    q++;
                }
                str++;
            } else if (*(str + 1) == 'b') {
                *str = '\b';
                q = str + 1;
                while (*q != '\0') {
                    *q = *(q + 1);
                    q++;
                }
                str++;
            } else if (*(str + 1) == 'f') {
                *str = '\f';
                q = str + 1;
                while (*q != '\0') {
                    *q = *(q + 1);
                    q++;
                }
                str++;
            } else if (*(str + 1) == 'n') {
                *str = '\n';
                q = str + 1;
                while (*q != '\0') {
                    *q = *(q + 1);
                    q++;
                }
                str++;
            } else if (*(str + 1) == 'r') {
                *str = '\r';
                q = str + 1;
                while (*q != '\0') {
                    *q = *(q + 1);
                    q++;
                }
                str++;
            } else if (*(str + 1) == 't') {
                *str = '\t';
                q = str + 1;
                while (*q != '\0') {
                    *q = *(q + 1);
                    q++;
                }
                str++;
            } else if (*(str + 1) == 'v') {
                *str = '\v';
                q = str + 1;
                while (*q != '\0') {
                    *q = *(q + 1);
                    q++;
                }
                str++;
            } else if (*(str + 1) == '\'') {
                *str = '\'';
                q = str + 1;
                while (*q != '\0') {
                    *q = *(q + 1);
                    q++;
                }
                str++;
            } else if (*(str + 1) == '\"') {
                *str = '\"';
                q = str + 1;
                while (*q != '\0') {
                    *q = *(q + 1);
                    q++;
                }
                str++;
            } else {
                fprintf(stderr, "%d", ERROR_CODE_INVALID_FORMAT);
                return -1;
            }
        } else {
            str++;
        }
    }
    str = p;
    return 0;
}

int check_range(char* str)
{
    int i = 0;
    int a = 0;
    int b = 0;
    int count = 0;
    int is_first_time = TRUE;
    size_t string_length = strlen(str);
    char* p = NULL;
    char* string_end = str + string_length;
    char* temp = NULL;
    temp = str;
    if (*str == '-') {
        str++;
    }
    while (*str != 0) {
        if (*str != '-') {
            str++;
            continue;
        }
        if (is_first_time == FALSE) {
            is_first_time = TRUE;
            str++;
            continue;
        }
        if (*(str + 1) == '\0') {
            str++;
            continue;
        }
        a = *(str - 1);
        b = *(str + 1);
        if (a > b) {
            fprintf(stderr, "%d", ERROR_CODE_INVALID_RANGE);
            return -1;
        }
        if (b - a > ARGUMENT_LENGTH - 1) {
            fprintf(stderr, "%d", ERROR_CODE_ARGUMENT_TOO_LONG);
            return -2;
        }
        if (a == b) {
            p = str;
            while (*p != 0) {
                *p = *(p + 2);
                p++;
            }
            if (*str == '-') {
                is_first_time = FALSE;
            }
        }
        if (b - a == 1) {
            p = str;
            while (*p != 0) {
                *p = *(p + 1);
                p++;
            }
            if (*(str + 1) == '-') {
                is_first_time = FALSE;
            }
        }
        if (b - a >= 2) {
            count = b - a - 2;
            p = string_end + count;
            while (string_end != str) {
                *(string_end + count) = *string_end;
                string_end--;
            }
            string_end = p;
            for (i = a + 1; i < b; ++i) {
                *str = i;
                str++;
            }
            if (*(str + 1) == '-') {
                is_first_time = FALSE;
            }
            str++;
        }
    }
    return 0;
}

int translate(int argc, const char** argv)
{
    char argument1[ARGUMENT_LENGTH];
    char argument2[ARGUMENT_LENGTH];
    char* set1 = NULL;
    char* set2 = NULL;
    set1 = argument1;
    set2 = argument2;
    if (argc != 4 && argc != 3) {
        fprintf(stderr, "%d", ERROR_CODE_WRONG_ARGUMENTS_NUMBER);
        return ERROR_CODE_WRONG_ARGUMENTS_NUMBER;
    }
    if (argc == 3) {
        if (strlen(argv[1]) == 0 || strlen(argv[2]) == 0) {
            fprintf(stderr, "%d", ERROR_CODE_INVALID_FORMAT);
            return ERROR_CODE_INVALID_FORMAT;
        }
        if (strlen(argv[1]) > ARGUMENT_LENGTH - 1 || strlen(argv[2]) > ARGUMENT_LENGTH - 1) {
            fprintf(stderr, "%d", ERROR_CODE_ARGUMENT_TOO_LONG);
            return ERROR_CODE_ARGUMENT_TOO_LONG;
        }
        strncpy(set1, argv[1], ARGUMENT_LENGTH);
        strncpy(set2, argv[2], ARGUMENT_LENGTH);
        if (escape_character(set1) != 0) {
            return ERROR_CODE_INVALID_FORMAT;
        }
        if (escape_character(set2) != 0) {
            return ERROR_CODE_INVALID_FORMAT;
        }
        if (check_range(set1) == -1) {
            return ERROR_CODE_INVALID_RANGE;
        }
        if (check_range(set2) == -2) {
            return ERROR_CODE_ARGUMENT_TOO_LONG;
        }
        check_repeatition(set1, set2);
        change_letters(set1, set2);
        return 0;
    }
    
    if (argc == 4) {
        if (strlen(argv[2]) == 0 || strlen(argv[3]) == 0) {
            fprintf(stderr, "%d", ERROR_CODE_INVALID_FORMAT);
            return ERROR_CODE_INVALID_FORMAT;
        }
        if (strlen(argv[2]) > ARGUMENT_LENGTH - 1 || strlen(argv[3]) > ARGUMENT_LENGTH - 1) {
            fprintf(stderr, "%d", ERROR_CODE_ARGUMENT_TOO_LONG);
            return ERROR_CODE_ARGUMENT_TOO_LONG;
        }
        if (strncmp(argv[1], "-i", strlen(argv[1])) != 0) {
            fprintf(stderr, "%d", ERROR_CODE_INVALID_FLAG);
            return ERROR_CODE_INVALID_FLAG;
        }
        strncpy(set1, argv[2], ARGUMENT_LENGTH);
        strncpy(set2, argv[3], ARGUMENT_LENGTH);
        if (escape_character(set1) != 0) {
            return ERROR_CODE_INVALID_FORMAT;
        }
        if (escape_character(set2) != 0) {
            return ERROR_CODE_INVALID_FORMAT;
        }
        if (check_range(set1) == -1) {
            return ERROR_CODE_INVALID_RANGE;
        }
        if (check_range(set2) == -2) {
            return ERROR_CODE_ARGUMENT_TOO_LONG;
        }
        check_repeatition(set1, set2);
        check_case_insensitive(set1, set2);
        return 0;
    }

    return 0;
}
