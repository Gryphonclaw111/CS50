#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    int n = atoi(argv[1]);
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize resize# infile outfile\n");
        return 1;
    }
    else if (n > 100)
    {
        fprintf(stderr, "Please chose a number less than 100\n");
        return 1;
    }
    else if (n < 1)
    {
        fprintf(stderr, "Please chose a number greater than 1\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    BITMAPINFOHEADER out_bi;
    BITMAPFILEHEADER out_bf;
    out_bi = bi;
    out_bf = bf;
    out_bi.biWidth = (n * bi.biWidth);
    out_bi.biHeight = (n * bi.biHeight);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // write outfile's BITMAPFILEHEADER
    fwrite(&out_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&out_bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int in_padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int out_padding = (4 - (out_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // resize image
    out_bi.biSizeImage = (((sizeof(RGBTRIPLE) * bi.biWidth) + out_padding)) * abs(bi.biHeight);
    out_bf.bfSize = (bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER));

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // stretch vertically
        for(int g = 0; g < n; g++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                 // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile
                for(int f = 0; f < n; f++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            //skip over infile padding
            fseek(inptr, in_padding, SEEK_CUR);

            // write outfile's padding
            for (int k = 0; k < out_padding; k++)
            {
                fputc(0x00, outptr);
            }

            // write outfile's padding
            fseek(inptr, -(bi.biWidth * 3 + in_padding), SEEK_CUR);
        }

        //skip over infile padding
        fseek(inptr, bi.biWidth*3 + in_padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
