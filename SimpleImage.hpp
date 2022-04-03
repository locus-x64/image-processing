#ifndef GREY_BITMAP_H
#define GREY_BITMAP_H

/**
 * The SimpleImage class declarations and documentation.
 * A Greyscale image that can be manipulated by students,
 * using a 2D array of integers.
 * Created for use in VIU/CSCI160 by B.Bultena.
 */

#include <iostream>
	using std::string;

/**
 * SimpleImage is a bitmap of greyscale pixels with a height, weight, greyscale range
 * and a 2D integer array.
 * Once the height and width have been set, the pixel array is allocated,
 * The height and width cannot be changed once set to values > 0.
 * The user of this class can have direct access and update privileges to the elements in the pixel array.
 */
class SimpleImage {
public:
// The constructors and destructors:
	/**
 	 * Creates a default empty image.
	 */
	SimpleImage();
	
	/**
  	 * Creates an image object with dimensions height and width,
	 * a given greyscale range: 0 ... greyscale-1.
	 * @param height the number of pixels vertically.
	 * @param width the number of pixels horizontally.
	 * @param greyscale the grey scale range. Default set to 256.
	 */
	SimpleImage(int height, int width, int greyscale=256);

	/**
 	 * Creates an image object from the information in a P2 PGM file.
	 * This could be adapted to handle different filetypes, but for 
	 * educational purposes, we use the simplest format.
 	 * @param filename the name of the legitimate file.
 	 */
	SimpleImage(string filename);

	/**
	 * Creates an image object that is a direct copy of the input image.
	 * @param orig the original image.
	 */
	SimpleImage(const SimpleImage &orig);

	/**
 	 * Frees all the memory used for a deallocated image object.
 	 */
	~SimpleImage();

// the getters:
// There are no setters in this class
	/**
	 * @return the width of the image.
 	 */
	int get_height() const {return height;}

	/** 
	 * @return the height of the image.
	 */
	int get_width() const {return width;}

	/**
	 * @return the greyscale range.
  	 */
	int get_greyscale() const {return greyscale;}

	/**
	 * Retrieves the pixel value in the array at location (r,c).
	 * @param r The row number (0 ... rows-1)
	 * @param c The col number (0 ... cols-1)
	 * @return The value at pixes[r][c].
	 */
	 int get_pixel(int r, int c) const {return pixels[r][c];}

	/**
	 * This allows direct access to the array of pixel values, to update any or all values.
	 * Note that the user of the array is responsible for making sure that each
	 * of the pixel values are within the correct range: 0 ... greyscale-1
	 * Note also that this function is not accessible for any SimpleImage that has been declared constant.
	 * To access pixel values of constant SimpleImage objects, use get_pixel(int, int)
	 * @return The 2D array of pixels, with num of rows = height and num of cols = width.
	 */
	int** get_pixels() {return pixels;}

// Other operations that can be performed on the image.
	/**
 	 * Prints out all the values within the array in a grid-shape.
	 * Mostly used for debugging purposes.
	 */
	void print();

	/**
 	 * Creates a P2 PGM file that represents the image bitmap.
	 * @param filename the file to contain the rendering.
	 *		If this file exists, then it will be over-written.
	 */
	void to_file(string filename);

// Non accessible attributes and helper functions
private:
	int height, width; 
	int greyscale;
	int **pixels; // the 2D array.
	void init(int,int,int);
	void init_pixels();
	void dismantle();
};

#endif
