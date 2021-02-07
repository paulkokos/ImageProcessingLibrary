#include <iostream>
#include "ImageProcessing.hpp"

using namespace std;

int main() {
    int imgWidth, imgHeight, imgBitDepth,imgBitDepthRGB;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char imgInBuffer[IMAGE_SIZE_512_BY_512];
    unsigned char imgOutBuffer[IMAGE_SIZE_512_BY_512];

    unsigned char imgHeaderRGB[BMP_HEADER_SIZE_COLORED];
    unsigned char imgColorTableRGB[BMP_COLOR_TABLE_SIZE_COLORED];
    unsigned char imgInBufferRGB[IMAGE_SIZE_512_BY_512_COLORED];
    unsigned char imgOutBufferRGB[IMAGE_SIZE_512_BY_512_COLORED];

    const char imgName[] = "./../images/lena512.bmp";
    const char newImgName[] = "./../images/lena_eqz.bmp";

    const char imgNameRGB[] = "./../images/lena_color.bmp";
    const char newImgNameRGB[] = "./../images/lena_eqz.bmp";

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
//    auto *myImage_color = new ImageProcessing(imgNameRGB,
//                                        newImgNameRGB,
//                                        &imgHeight,
//                                        &imgWidth,
//                                        &imgBitDepthRGB,
//                                        &imgHeaderRGB[0],
//                                        &imgColorTableRGB[0],
//                                        &imgInBufferRGB[0],
//                                        &imgOutBufferRGB[0]
//    );

    myImage->readImage();
    //myImage_color->readImageRGB();
    //myImage->generateGaussNoise(imgInBuffer,imgWidth,imgHeight,0,1);
   // myImage->writeImage("./../images/lena_Gaussian_noise.bmp");
    //myImage_color->RGBtoRed(imgInBufferRGB,imgOutBufferRGB,imgWidth,imgHeight);
    //myImage_color->writeImageRGB("./../images/lena_RED.bmp");

    myImage->saltAndPepper(imgInBuffer,imgHeight,imgWidth,0);
    myImage->writeImage("./../images/lena_saltAndPepper.bmp");

    myImage->getImageNegative(imgInBuffer,imgOutBuffer,imgWidth,imgHeight);
    myImage->writeImage("./../images/lena_Negative.bmp");

    myImage->binarizeImage(imgInBuffer,imgOutBuffer,IMAGE_SIZE_512_BY_512,128);
    myImage->writeImage("./../images/lena_binarized.bmp");

    myImage->equalizeHistogram(imgInBuffer, imgOutBuffer, imgHeight, imgWidth);
    myImage->writeImage("./../images/lena_eqz.bmp");

    myImage->minimumFilter(imgInBuffer, imgOutBuffer, imgWidth, imgHeight);
    myImage->writeImage("./../images/lena_min.bmp");

    cout << "Success !" << endl;
    cout << "Image Height : " << imgHeight << endl;
    cout << "Image Width  : " << imgWidth << endl;
//    system("gnuplot");

    return 0;
}
