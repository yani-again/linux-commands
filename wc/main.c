#include <stdio.h>

int main(int argc, char* argv[])
{
    char* flags = "";
    FILE* pFile;
    char buffer[1024] = {0};

    int i;
    int lines = 0;
    int words = 0;
    int chars = 0;
    int inside_word = 0;
    char previous_char = ' ';

    if (argc == 2)
    {
        pFile = fopen(argv[1], "r");

        if (pFile == NULL)
        {
            printf("Couldn't open file\n");
            return 1;
        }
    }
    else
    {
        flags = argv[1];
        pFile = fopen(argv[2], "r");

        if (pFile == NULL)
        {
            printf("Couldn't open file\n");
            return 1;
        }
    }

    while (fgets(buffer, sizeof(buffer), pFile))
    {
        for (i = 0; i < sizeof(buffer) && (buffer[i] != '\0'); ++i)
        {
            ++chars;
            if (buffer[i] == '\n') ++lines;
            
            if (buffer[i] != ' ' && buffer[i] != '\n' && !inside_word)
            {
                inside_word = 1;
                ++words;
            }
            else if ((buffer[i] == ' ' || buffer[i] == '\n') && inside_word)
            {
                inside_word = 0;
            }

            // neccessary to keep track of trailing \n character at end of file
            previous_char = buffer[i];
        }
    }

    // if last char in the file isn't \n, count an extra line
    if (previous_char != '\n') ++lines;

    int j = 0;
    while (flags[j] != '\0')
    {
        if (flags[j] == 'l') printf("%d  ", lines);
        else if (flags[j] == 'w') printf("%d  ", words);
        else if (flags[j] == 'c') printf("%d  ", chars);
        ++j;
    }

    if (j == 0) printf("%d  %d  %d", lines, words, chars);
    putchar('\n');

    fclose(pFile);
    
    return 0;
}

