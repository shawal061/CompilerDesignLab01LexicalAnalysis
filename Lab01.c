#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *fptr, *outptr;
    char ch;
    char *code;

    fptr = fopen("input.txt", "r");
    if (fptr == NULL)
    {
        printf("File failed to open.");
        return 1;
    }

    outptr = fopen("output.txt", "w");
    if (outptr == NULL)
    {
        printf("Failed to open output file.");
        fclose(fptr);
        return 1;
    }

    code = (char *)malloc(100 * sizeof(char));
    if (code == NULL)
    {
        printf("Memory allocation failed.");
        fclose(fptr);
        fclose(outptr);
        return 1;
    }

    code[0] = '\0';

    while ((ch = fgetc(fptr)) != EOF)
    {
        strncat(code, &ch, 1);
    }

    int i = 0;

    while (code[i] != '\0')
    {
        if (isspace(code[i]))
        {
            i++;
            continue;
        }

        if (isalpha(code[i]) || code[i] == '_')
        {
            char token[50];
            int j = 0;
            while (isalnum(code[i]) || code[i] == '_')
            {
                token[j++] = code[i++];
            }
            token[j] = '\0';
            fprintf(outptr, "%s\n", token);
        }

        else if (isdigit(code[i]))
        {
            char number[20];
            int j = 0;
            while (isdigit(code[i]))
            {
                number[j++] = code[i++];
            }
            number[j] = '\0';
            fprintf(outptr, "%s\n", number);
        }

        else if (code[i] == '+' || code[i] == '-' || code[i] == '=' || code[i] == ';' || code[i] == '{' || code[i] == '}' || code[i] == '(' || code[i] == ')')
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