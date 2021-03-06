#include <iostream>

//Stru
//
//struct imageHeader {
//    //54 bytes header image
//
//};
//struct colorTable {
//    //1028 color table
//};
//struct imageBody {
//    //raw image data values
//};
//struct Image {
//    imageHeader header;
//    colorTable table;
//    imageBody body;
//};


int main() {
    FILE *streamIn = fopen("C:\\Users\\paulkokos\\CLionProjects\\ImageProcessingLibrary\\images\\input\\lena512.bmp","rb");
    FILE *output = fopen("C:\\Users\\paulkokos\\CLionProjects\\ImageProcessingLibrary\\images\\output\\lena512_output.bmp","wb");
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