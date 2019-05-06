#include "bmpLoader.h"
#include<bits/stdc++.h>

using namespace std;

bmpLoader::bmpLoader(const char *filename)
{
  FILE *file = fopen(filename,"rb");
  if(!file){
    cout<<"File Not Found"<<endl;
  }
  fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, file);
  if(bmpFileHeader.bfType != 0x4D42){
    cout<<"NOT A Valid File"<<endl;
  }
  fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, file);
  if(bmpInfoHeader.biSizeImage==0){
    bmpInfoHeader.biSizeImage = bmpInfoHeader.biHeight * bmpInfoHeader.biWidth * 3;
  }
  textData = new unsigned char[bmpInfoHeader.biSizeImage];
  fseek(file, bmpFileHeader.bfOffBits, SEEK_SET);
  fread(textData, 1, bmpInfoHeader.biSizeImage, file);

  for(int i=0;i<bmpInfoHeader.biSizeImage;i+=3){
    swap(textData[i],textData[i+2]);
  }
  width = bmpInfoHeader.biWidth;
  height = bmpInfoHeader.biHeight;

  fclose(file);

}

bmpLoader::~bmpLoader()
{
  delete [] textData;
}
