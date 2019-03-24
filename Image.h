#pragma once
#include <vector>
struct Pixel {
	uint8_t r, g, b;
	Pixel() :r(0), g(0), b(0) {};
	Pixel(uint8_t red, uint8_t green, uint8_t blue) :r(red), g(green), b(blue) {};
};

class Image {
public:
	bool write(std::string filename);
	Image(uint32_t r, uint32_t c);
	inline uint32_t rows() { return _rows; };
	inline uint32_t cols() { return _cols; };
	inline Pixel& operator () (uint32_t r, uint32_t c) {
		return _pixels[r*_cols + c];
	}
private:
	std::vector<Pixel> _pixels;
	uint32_t _rows;
	uint32_t _cols;
};
