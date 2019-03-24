#include "Image.h"
#include <stdlib.h>
#include <iostream>

Image::Image(uint32_t r, uint32_t c) : _pixels(r*c) {
	_rows = r;
	_cols = c;
}

bool Image::write(std::string filename) {
	FILE *fp;
	errno_t err = fopen_s(&fp, filename.c_str(), "wb"); /* b - binary mode */
	if (err != 0) {
		std::cout << "Error opening file\n";
		return false;
	}
	(void)fprintf(fp, "P6\n%d %d\n255\n", _rows, _cols);
	uint32_t bytes = _rows * _cols * sizeof(Pixel);
	size_t written = fwrite(&_pixels[0], 1, bytes, fp);
	(void)fclose(fp);
	return bytes == written;
}