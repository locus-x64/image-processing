/**
 * Defines the SimpleImage class.
 */
#include "SimpleImage.hpp"

#include <iostream>
#include <fstream>
	using std::string;
	using std::ifstream;
	using std::ofstream;
	using std::cout;
	using std::endl;

// Default constructor:
// Mostly used with a SimpleImage is defined but not yet initialized.
SimpleImage::SimpleImage() {
	init(0,0,0);
}

// basic constructor
// This initializes the basic attributes with the incoming information.
SimpleImage::SimpleImage(int h, int w, int gs) {
	init(h,w,gs);
}

// constructor from file source.
// most commonly used
SimpleImage::SimpleImage(string filename) {
	ifstream reader(filename);
	string imagecode;
	getline(reader,imagecode);
	if (imagecode != "P2") {
		cout << "Not the correct image type.\n";
		cout << "Got "<<imagecode<<", expected P2.\n";
		// create a default object
		init(0,0,0);
		return;
	}
	// The next two integers are the width and height in pixels
	// width is number of columns.
	// height is number of rows.
	// greyscale is the range of black to white (usually 256)
	int h, w, gs;
	reader >> w;
	reader >> h;
	if (!reader) {
		cout << "Cannot pick out the width and height values.\n";
		init(0,0,0);
		return;
	}
	reader >> gs;
	
	// sets up the attributes, builds the array
	init(h,w,gs);

	// The initialization of the pixels is
	// extracted from the file.
	int value;
	for (int r=0; r<height; r++) {
		for (int c=0; c<width; c++) {
			reader >> value;
			pixels[r][c] = value;
		}
	}
}

// destructor (needs to release the array memory.
SimpleImage::~SimpleImage() {
	if (height * width != 0) {
		dismantle();
	}
}

// copy constructor
// Useful when assigning a copy of one image to another.
SimpleImage::SimpleImage(const SimpleImage &image) {
	// what are the original's attributes?
	int h = image.height;
	int w = image.width;
	int gs = image.greyscale;
	init(h, w, gs);
	// copy all the pixel information to the new one.
	for (int r=0; r<height; r++) {
		for (int c=0; c<width; c++) {
			pixels[r][c] = image.get_pixel(r,c);
		}
	}
}

// Helper functions for the constructors and destructor.

// Allocates the memory needed for the array
void SimpleImage::init_pixels() {
	pixels = new int*[height];
	for (int r=0; r<height; r++) {
		pixels[r] = new int[width];
	}
}

// Dismantles 2D array and releases memory.
void SimpleImage::dismantle() {
	for (int r=0; r<height; r++) {
		delete[] pixels[r];
	}
	delete[] pixels;
}
	
/*
 * Sets up the initial dimensions for the image.
 * Then calls the init_pixels to set up the array
 * inputs: h, w, gs: height, width and greyscale.
 * ASSERTION: That this is only called by a constructor
 */
void SimpleImage::init(int h, int w, int gs) {
	if (h < 0) {
		height = 0;
	} else {
		height = h;
	}
	if (w < 0) {
		width = 0;
	} else {
		width = w;
	}
	if (gs < 0) {
		greyscale = 0;
	} else {
		greyscale = gs;
	}
	if (height * width > 0 and greyscale > 0) {
		init_pixels();
	} else {
		pixels = nullptr;
	}
}

// No setters.
// Getters are coded inline in the hpp file.

/***** Printing to a console or converting to a file */

void SimpleImage::to_file(string filename) {
	ofstream writer(filename);
	writer << "P2\n";
	writer << width << " " << height << endl;
	writer << greyscale << endl;

	for (int r=0; r<height; r++) {
		for (int c=0; c<width; c++) {
			writer << get_pixel(r,c) << endl;
		}
	}
}

// prints to the console
void SimpleImage::print() {
	cout << height << " X " << width << endl;
	for (int r=0; r<height; r++) {
		for (int c=0; c<width; c++) {
			cout<<pixels[r][c]<<" ";
		}
		cout << endl;
	}
}

