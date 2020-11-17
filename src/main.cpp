#include "ImageProcessing.hpp"

using namespace std;

int main()
{


    int imgWidth, imgHeight, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char imgInBuffer[_512by512_IMG_SIZE];
    unsigned char imgOutBuffer[_512by512_IMG_SIZE];



    const char imgName[] ="../images/lena512.bmp";
    const char newImgName[] ="../images/lena512_out.bmp";
    const char imgNameColored[]="../images/lena_color.bmp";
    const char newImgNameColored[]="../images/lena_color_out.bmp";

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
    myImage->getImageNegative(reinterpret_cast<char *>(imgInBuffer), reinterpret_cast<char *>(imgOutBuffer), 512, 512);
//          myImage->minimumFilter(imgInBuffer,imgOutBuffer,imgWidth,imgHeight);
     myImage->writeImage();
     cout<<"Success !"<<endl;
     cout<<"Image Height : "<<imgHeight<<endl;
     cout<<"Image Width  : "  <<imgWidth<<endl;

    return 0;
}
