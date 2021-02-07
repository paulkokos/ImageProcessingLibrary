//
// Created by paulkokos on 7/2/21.
//

#ifndef IMAGEPROCESSINGLIBRARY_IMAGE_HPP
#define IMAGEPROCESSINGLIBRARY_IMAGE_HPP

#include <cmath>
#include <string>
using std::string;
class Image {
private:
    //BASIC HEADER ATTRIBUTES
    constexpr static double PI = M_PI;
    int width;
public:
    Image(int width, int height, const string &name, const string &extension, const string &absoluteLocation);

    //Image(int width, int height, const string &name, const string &extension, const string &relativeLocation);
    //TODO: Relative VS Absolute location ???

    Image();
private:
    int height;
    string name;
    string extension;
public:
    int getWidth() const;

    void setWidth(int width);

    int getHeight() const;

    void setHeight(int height);

    const string &getName() const;

    void setName(const string &name);

    const string &getExtension() const;

    void setExtension(const string &extension);

    const string &getAbsoluteLocation() const;

    void setAbsoluteLocation(const string &absoluteLocation);

    const string &getRelativeLocation() const;

    void setRelativeLocation(const string &relativeLocation);

private:
    string absoluteLocation; //todo: potential method
    string relativeLocation; //todo: potential method


};


#endif //IMAGEPROCESSINGLIBRARY_IMAGE_HPP
