#include <stdio.h>

int print(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    return print(argc, argv);
}

int print(int argc, char* argv[])
{
    FILE* pFiles[argc - 1];
    char buffer[1024] = {0};

    for (size_t i = 0; i < argc - 1; ++i)
    {
        pFiles[i] = fopen(argv[i + 1], "r");
        if (pFiles[i] == NULL)
        {
            printf("Couldn't open file \"%s\"\n", argv[i + 1]);
            
            // close all open files before exiting
            if (i > 0)
            {
                for (size_t j = 0; j < i; ++j)
                {
                    fclose(pFiles[j]);
                }
            }

            return 1;
        }
    }

    for (size_t i = 0; i < argc - 1; ++i)
    {
        while (fgets(buffer, sizeof(buffer), pFiles[i]))
        {
            printf("%s", buffer);
        }
    }

    for (size_t i = 0; i < argc - 1; ++i)
    {
        fclose(pFiles[i]);
    }

    return 0;
}
