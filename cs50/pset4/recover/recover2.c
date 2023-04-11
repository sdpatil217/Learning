#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    //check for proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Proper usage: ./recover file\n");
        return 1;
    }

    //Remember name of file
    char *infile = argv[1];

    //open infile
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s, please try again\n", infile);
        return 2;
    }

    //INIT block size and buffer
    int blockSize = 512;
    unsigned char buffer[blockSize];

    //Storage for file name and file
    char fileBuffer[8];
    FILE *outptr = NULL;

    //count how many images have been found
    int imageCount = 0;

    //iterate over the infile 512 bytes at a time
    while (fread(buffer, blockSize, 1, inptr) == 1)
    {
        //look for jpeg header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //close output file if its open
            if (outptr != NULL)
            {
                fclose(outptr);
            }
            //create the new file name and open that file
            sprintf(fileBuffer, "%03d.jpg", imageCount);
            outptr = fopen(fileBuffer, "w");
            if (outptr == NULL)
            {
                fprintf(stderr, "Could not create %s", fileBuffer);
                return 3;
            }
            //INCREMENT Image count
            imageCount++;
        }
        //write to out file if an image was found
        if (outptr != NULL)
        {
            fwrite(buffer, blockSize, 1, outptr);
        }
    }
    //close last photo
    fclose(outptr);
    //close input file
    fclose(inptr);
    //success
    return 0;
}