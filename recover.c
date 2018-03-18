#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover infile\n" );
        return 1;
    }
    // open infile
    char* infile = argv[1];
    FILE* inptr = fopen(infile, "r");
    FILE* img;
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 1;
    }
    uint8_t buffer[512];
    fread(buffer, 512, 1, inptr);
    int z = 0;
    int j = 0;

    while(fread(buffer, 512, 1, inptr) > 0)
    {
        // if JPEG found
        if(buffer[0] == 0xff &&
           buffer[1] == 0xd8 &&
           buffer[2] == 0xff &&
           (buffer[3] & 0xf0) == 0xe0)
        {
            char filename[8];
            sprintf(filename, "%03i.jpg", j);
            if(z == 0)
            {
                img = fopen(filename, "w");
                fwrite(buffer, 512, 1, img);
                z = 1;
            }
            if(z == 1)
            {
                fclose(img);
                img = fopen(filename, "w");
                fwrite(buffer, 512, 1, img);
                j++;
            }
        }
        else if(z == 1)
        {
            fwrite(buffer, 512, 1, img);
        }
    }
    // close infile
    fclose(inptr);

    // success
    return 0;
}
