#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INIT_CAPACITY 100

int main()
{
    FILE *fptr, *outptr;
    char ch, *code;
    size_t capacity = INIT_CAPACITY, length = 0;

    fptr = fopen("inputx.txt", "r");
    if (fptr == NULL)
    {
        printf("File failed to open.\n");
        return 1;
    }

    outptr = fopen("outputx.txt", "w");
    if (outptr == NULL)
    {
        printf("Failed to open output file.\n");
        fclose(fptr);
        return 1;
    }

    code = (char *)malloc(capacity * sizeof(char));
    if (code == NULL)
    {
        printf("Memory allocation failed.\n");
        fclose(fptr);
        fclose(outptr);
        return 1;
    }

    while ((ch = fgetc(fptr)) != EOF)
    {
        if (length + 1 >= capacity)
        {
            capacity *= 2;
            char *temp = realloc(code, capacity);
            if (temp == NULL)
            {
                printf("Memory reallocation failed.\n");
                free(code);
                fclose(fptr);
                fclose(outptr);
                return 1;
            }
            code = temp;
        }
        code[length++] = ch;
    }
    code[length] = '\0';

    size_t i = 0;
    while (code[i] != '\0')
    {
        if (isspace(code[i]))
        {
            i++;
            continue;
        }

        if (isalpha(code[i]) || code[i] == '_')
        {
            char token[50] = {0};
            size_t j = 0;
            while ((isalnum(code[i]) || code[i] == '_') && j < sizeof(token) - 1)
            {
                token[j++] = code[i++];
            }
            token[j] = '\0';
            fprintf(outptr, "%s\n", token);
        }
        else if (isdigit(code[i]))
        {
            char number[20] = {0};
            size_t j = 0;
            while (isdigit(code[i]) && j < sizeof(number) - 1)
            {
                number[j++] = code[i++];
            }
            number[j] = '\0';
            fprintf(outptr, "%s\n", number);
        }
        else if (strchr("+-=*/;{}()", code[i]))
        {
            fprintf(outptr, "%c\n", code[i]);
            i++;
        }
        else
        {
            fprintf(outptr, "%c\n", code[i]);
            i++;
        }
    }

    free(code);
    fclose(fptr);
    fclose(outptr);
    return 0;
}
