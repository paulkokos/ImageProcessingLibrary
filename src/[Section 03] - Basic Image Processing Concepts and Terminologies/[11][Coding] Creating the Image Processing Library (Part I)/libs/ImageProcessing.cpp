//
// Created by paulkokos on 4/2/2021.
//

#include "ImageProcessing.h"

ImageProcessing::ImageProcessing(const char* _inImgName,
                                 const char* _outImgName,
                                 int * _height,
                                 int * _width,
                                 int * _bitDepth,
                                 unsigned char* _header,
                                 unsigned char* _colorTable,
                                 unsigned char* _outBuffer) {
    this->inImgName = _inImgName;
    this->outImgName = _outImgName;
    this->height = _height;
    this->width = _width;
    this->bitDepth = _bitDepth;
    this->header = _header;
    this->colorTable = _colorTable;
    this->outBuffer = _outBuffer;

}
