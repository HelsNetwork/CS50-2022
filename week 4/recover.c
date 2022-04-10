#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", argv[1]);
        return 1;
    }

    FILE *img;
    char filename[7];
    unsigned char *bf = malloc(512);
    int counter = 0;

    while (fread(bf, 512, 1, file))
    {
        if (bf[0] == 0xff && bf[1] == 0xd8 && bf[2] == 0xff && (bf[3] & 0xf0) == 0xe0)
        {
            if (counter > 0)
            {
                fclose(img);
            }

            // create filename
            sprintf(filename, "%03d.jpg", counter);
            // open new image file
            img = fopen(filename, "w");

            if (img == NULL)
            {
                fclose(file);
                free(bf);
                fprintf(stderr, "Could not create output JPG %s", filename);
                return 3;
            }

            counter++;
        }
        if (counter > 0)
        {
            fwrite(bf, 512, 1, img);
        }
    }

    fclose(img);
    fclose(file);
    free(bf);
    return 0;
}
