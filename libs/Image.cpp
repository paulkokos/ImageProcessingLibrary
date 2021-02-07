//
// Created by paulkokos on 7/2/21.
//

#include "Image.hpp"

Image::Image(int width, int height, const string &name, const string &extension, const string &absoluteLocation)
        : width(width), height(height), name(name), extension(extension), absoluteLocation(absoluteLocation) {}

int Image::getWidth() const {
    return width;
}

void Image::setWidth(int width) {
    Image::width = width;
}

int Image::getHeight() const {
    return height;
}

void Image::setHeight(int height) {
    Image::height = height;
}

const string &Image::getName() const {
    return name;
}

void Image::setName(const string &name) {
    Image::name = name;
}

const string &Image::getExtension() const {
    return extension;
}

void Image::setExtension(const string &extension) {
    Image::extension = extension;
}

const string &Image::getAbsoluteLocation() const {
    return absoluteLocation;
}

void Image::setAbsoluteLocation(const string &absoluteLocation) {
    Image::absoluteLocation = absoluteLocation;
}

const string &Image::getRelativeLocation() const {
    return relativeLocation;
}

void Image::setRelativeLocation(const string &relativeLocation) {
    Image::relativeLocation = relativeLocation;
}

Image::Image() {

}

//Image::Image(int width, int height, const string &name, const string &extension, const string &relativeLocation)
//        : width(width), height(height), name(name), extension(extension), relativeLocation(relativeLocation) {}


