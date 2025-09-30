#include <stdio.h>

int main(int argc, char* argv[])
{
    char option_order[3];

    FILE* pFile;
    char buffer[1024] = {0};
    int file_index = 1;

    int lines = 0;
    int words = 0;
    int chars = 0;

    // for logic
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

        option_order[0] = 'l';
        option_order[1] = 'w';
        option_order[2] = 'c';
    }
    else
    {
        int option_count = 0;

        // duplicate option prevention variables
        int w_check = 0;
        int l_check = 0;
        int c_check = 0;       

        for (int i = 1; i < argc; ++i)
        {
            if (argv[i][0] == '-')
            {
                int j = 1;
                while (argv[i][j] != '\0')
                {
                    if (argv[i][j] == 'w' && !w_check)
                    {
                        w_check = 1;
                        option_order[option_count] = 'w';
                        ++option_count;
                    }
                    else if (argv[i][j] == 'l' && !l_check)
                    {
                        l_check = 1;
                        option_order[option_count] = 'l';
                        ++option_count;
                    }
                    else if (argv[i][j] == 'c' && !c_check)
                    {
                        c_check = 1;
                        option_order[option_count] = 'c';
                        ++option_count;
                    }
                    ++j;
                }
            }
            else
            {
                file_index = i;
                pFile = fopen(argv[i], "r");
            }
        }
        
        if (pFile == NULL)
        {
            printf("Couldn't open file\n");
            return 1;
        }
    }

    while (fgets(buffer, sizeof(buffer), pFile))
    {
        for (int i = 0; i < sizeof(buffer) && (buffer[i] != '\0'); ++i)
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

    fclose(pFile);

    // if last char in the file isn't \n, count an extra line
    if (previous_char != '\n') ++lines;

    for (int i = 0; i < 3; ++i)
    {
        switch (option_order[i])
        {
            case 'w':
                printf("%d ", words);
                break;
            case 'l':
                printf("%d ", lines);
                break;
            case 'c':
                printf("%d ", chars);
                break;
        }
    }

    printf("%s\n", argv[file_index]);

    return 0;
}

