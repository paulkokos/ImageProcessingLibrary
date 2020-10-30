#include <iostream>
#include "ImageProcessing.hpp"

using namespace std;

int main() {
    int imgWidth, imgHeight, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char imgInBuffer[IMAGE_SIZE_512_BY_512];
    unsigned char imgOutBuffer[IMAGE_SIZE_512_BY_512];

    const char imgName[] = "./../images/lena512.bmp";
    const char newImgName[] = "./../images/lena_eqz.bmp";

    auto *myImage = new ImageProcessing(imgName,
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

    myImage->equalizeHistogram(imgInBuffer, imgOutBuffer, imgHeight, imgWidth);
    myImage->writeImage("./../images/lena_eqz.bmp");

    myImage->minimumFilter(imgInBuffer, imgOutBuffer, imgWidth, imgHeight);
    myImage->writeImage("./../images/lena_min.bmp");

    cout << "Success !" << endl;
    cout << "Image Height : " << imgHeight << endl;
    cout << "Image Width  : " << imgWidth << endl;

    return 0;
}
