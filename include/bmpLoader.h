#ifndef BMPLOADER_H
#define BMPLOADER_H
#include<windows.h>

class bmpLoader
{
  public:
    unsigned char* textData;
    int width, height;
    bmpLoader(const char*);
    ~bmpLoader();
  private:
    BITMAPFILEHEADER bmpFileHeader;
    BITMAPINFOHEADER bmpInfoHeader;
};

#endif // BMPLOADER_H
