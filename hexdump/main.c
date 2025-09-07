#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE* pFile = fopen(argv[1], "r");
    unsigned char buffer[16] = {0};
    size_t n;
    size_t address = 0;

    if (pFile == NULL)
    {
        printf("Failed opening file!\n");
        return 1;
    }

    while ((n = fread(buffer, 1, sizeof(buffer), pFile)) > 0)
    {
        printf("%07zx ", address);
        address +=16;
        for (int i = 0; i < n; i +=2)
        {
            printf("%02x%02x ", buffer[i], buffer[i + 1]);
        }
        putchar('\n');
    }

    fclose(pFile);

    return 0;
}
