#include <iostream>


#define BMP_HEADER_SIZE         g54
#define BMP_COLOR_TABLE_SIZE    1024
#define CUSTOM_IMG_SIZE         1024*1024
int main() {
    FILE *streamIn = fopen("C:\\Users\\paulkokos\\CLionProjects\\"
                           "ImageProcessingLibrary\\images\\input\\"
                           "lena512.bmp","rb");
    FILE *output = fopen("C:\\Users\\paulkokos\\CLionProjects\\"
                         "ImageProcessingLibrary\\images\\output\\"
                         "lena512_output.bmp","wb");

    if (streamIn == (FILE*)0) {
        printf("Unable to open");
    }

    unsigned char header[54];
    unsigned char colorTable[1024];

    for (int i =0; i < 54; i++) {
        header[i]= getc(streamIn);
    }

    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int bitDepth = *(int *)&header[28];

    if (bitDepth <=8) {
        fread(colorTable,sizeof(unsigned char),1024,streamIn);
    }
    fwrite(header,sizeof (unsigned char),54,output);

    //buffer

    unsigned char buffer[height *width];
    fread(buffer,sizeof (unsigned char),(height*width),streamIn);

    if (bitDepth <=8) {
        fwrite(colorTable,sizeof (unsigned char),1024,output);
    }
    fwrite(buffer,sizeof (unsigned char),(height*width),output);
    fclose(output);
    fclose(streamIn);
    printf ("Success!\n");
    printf ("Width is %d\n",width);
    printf ("Height is %d\n",height);
    return 0;
}

void imageHeader(const char* imgName, int *height, int *width, int * bitDepth, unsigned char* header, unsigned char* buffer) {
    int i;
    FILE * streamIn;
    streamIn = fopen(imgName,"rb");
    if (streamIn == (FILE* )0) {
        printf("Unable to read image\n");
    }
}