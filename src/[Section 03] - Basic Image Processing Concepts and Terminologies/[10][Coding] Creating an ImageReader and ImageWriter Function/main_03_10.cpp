#include <iostream>


#define BMP_HEADER_SIZE         54
#define BMP_COLOR_TABLE_SIZE    1024
#define CUSTOM_IMG_SIZE         1024*1024

void imageWriter(const char *imageName,
                 unsigned char *header,
                 unsigned char* colorTable,
                 unsigned char* buffer,
                 int bitDepth);

void imageReader(const char* imgName,
                 int *height,
                 int *width,
                 int * bitDepth,
                 unsigned char* header,
                 unsigned char* colorTable,
                 unsigned char* buffer);
int main() {
    int imgWidth;
    int imgHeight;
    int imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char imgBuffer[CUSTOM_IMG_SIZE];

    const char imgName[] = "C:\\Users\\paulkokos\\CLionProjects\\ImageProcessingLibrary\\images\\input\\lena_color.bmp";

    const char newImgName[] = "C:\\Users\\paulkokos\\CLionProjects\\ImageProcessingLibrary\\images\\output\\lena_color_output.bmp";

    imageReader(imgName,&imgHeight,&imgWidth,&imgBitDepth,&imgHeader[0],&imgColorTable[0],&imgBuffer[0]);

    imageWriter(newImgName,imgHeader,imgColorTable,imgBuffer,imgBitDepth);

    printf("Success\n");
    return 0;
}

void imageReader(const char* imgName,
                 int *height,
                 int *width,
                 int * bitDepth,
                 unsigned char* header,
                 unsigned char* colorTable,
                 unsigned char* buffer) {
    int i;
    FILE * streamIn;
    streamIn = fopen(imgName,"rb");
    if (streamIn == (FILE* )0) {
        printf("Unable to read image\n");
    }
    for (int i=0; i<54; i++) {
        header[i] = getc(streamIn);
    }
    *width = *(int *)&header[18];
    *height = *(int* )&header[22];
    *bitDepth = *(int* )&header[28];

    if (*bitDepth <=8) {
        fread(colorTable,sizeof (unsigned char), 1024, streamIn);
    }

    fread(buffer,sizeof (unsigned char),CUSTOM_IMG_SIZE,streamIn);

    fclose(streamIn);
}

void imageWriter(const char *imageName,
                 unsigned char *header,
                 unsigned char* colorTable,
                 unsigned char* buffer,
                 int bitDepth) {

    FILE *fileOutput = fopen(imageName,"wb");
    fwrite(header,sizeof (unsigned char ),54,fileOutput);

    if (bitDepth <=8) {
        fwrite(colorTable,sizeof (unsigned char),1024,fileOutput);
    }

    fwrite(buffer,sizeof (unsigned char),CUSTOM_IMG_SIZE,fileOutput);
    fclose(fileOutput);
}