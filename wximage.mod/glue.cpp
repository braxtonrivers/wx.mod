/*
  Copyright (c) 2007 Bruce A Henderson
 
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/ 

#include "glue.h"

// ---------------------------------------------------------------------------------------

MaxImage::MaxImage()
	: image(wxNullImage)
{
	image = wxImage();
}

MaxImage::MaxImage(const wxImage & img)
	: image(wxNullImage)
{
	image = wxImage(img); // we need to make a copy of it !
}

wxImage & MaxImage::Image() {
	return image;
}

MaxImage::~MaxImage() {
//	delete &image;
}


// *********************************************


MaxImage * bmx_wximage_createempty(int width, int height) {
	wxImage i = wxImage(width, height);
	return new MaxImage(i);
}

void bmx_wximage_delete(MaxImage * image) {
	delete image;
}

void bmx_wximage_setrgb(MaxImage * image, int x, int y, int r, int g, int b) {
//printf("setrgb - %d, %d, %d .. %d\n", r, g, b, static_cast<unsigned char>(r));fflush(stdout);
//unsigned char z = 1;
//image->Image().SetRGB(x, y, z, z, z);
	image->Image().SetRGB(x, y, static_cast<unsigned char>(r), static_cast<unsigned char>(g), static_cast<unsigned char>(b));
}

void bmx_wximage_rescale(MaxImage * image, int width, int height, int quality) {
	image->Image().Rescale(width, height, quality);
}

int bmx_wximage_getwidth(MaxImage * image) {
	return image->Image().GetWidth();
}



void bmx_wximage_addhandler(wxImageHandler * handler) {
	wxImage::AddHandler(handler);
}

wxPNGHandler * bmx_wxpnghandler_create() {
	return new wxPNGHandler();
}
