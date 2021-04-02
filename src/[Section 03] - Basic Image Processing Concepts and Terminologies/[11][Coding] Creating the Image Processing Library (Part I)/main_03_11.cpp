#include <iostream>
#include "libs\\ImageProcessing.h"

using namespace std;

int main()
{
    int imgWidth, imgHeight, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char imgInBuffer[_512by512_IMG_SIZE];
    unsigned char imgOutBuffer[_512by512_IMG_SIZE];

    const char imgName[] ="C:\\Users\\paulkokos\\CLionProjects\\ImageProcessingLibrary\\images\\input\\girlface.bmp";
    const char newImgName[] ="C:\\Users\\paulkokos\\CLionProjects\\ImageProcessingLibrary\\images\\output\\girlface_copy.bmp";

    ImageProcessing *myImage  = new ImageProcessing(imgName,
                                                    newImgName,
                                                    &imgHeight,
                                                    &imgWidth,
                                                    &imgBitDepth,
                                                    &imgHeader[0],
                                                    &imgColorTable[0],
                                                    &imgInBuffer[0],
                                                    &imgOutBuffer[0]
    );

    myImage->readImage();
    myImage->copyImgData(imgInBuffer,imgOutBuffer,_512by512_IMG_SIZE);
    myImage->writeImage();

    cout<<"Success !"<<endl;
    cout<<"Image Height : "<<imgHeight<<endl;
    cout<<"Image Width  : "  <<imgWidth<<endl;

    return 0;
}
