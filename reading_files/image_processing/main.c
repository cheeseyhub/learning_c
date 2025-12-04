#include <stdio.h>
#include "ppm.h"

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    ppmimage *image =ppm_readimage(argv[0]);
    ppm_writeimage(argv[2], image);
     ppm_destroyimage(image);



    return 0;
}
