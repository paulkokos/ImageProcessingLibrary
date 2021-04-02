//
// Created by paulkokos on 4/2/2021.
//

#ifndef IMAGEPROCESSINGLIBRARY_IMAGEPROCESSING_H
#define IMAGEPROCESSINGLIBRARY_IMAGEPROCESSING_H


class ImageProcessing {
public:
    ImageProcessing(const char* _inImgName,
                    const char* _outImgName,
                    int * _height,
                    int * _width,
                    int * _bitDepth,
                    unsigned char* _header,
                    unsigned char* _colorTable,
                    unsigned char* _outBuffer);

    ImageProcessing();

    ~ImageProcessing();

private:
    const char* inImgName;
    const char* outImgName;
    int * height;
    int * width;
    int * bitDepth;
    unsigned char* header;
    unsigned char* colorTable;
    unsigned char* outBuffer;
};


#endif //IMAGEPROCESSINGLIBRARY_IMAGEPROCESSING_H
