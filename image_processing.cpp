/*
 * Name: Ibrahim
 * Date: 28 March 2022
 * Title: CS Assignment 6
 */

#include "image_processing.hpp"
#include <iostream>
#include <sstream>
#define MAXGRAYSCALE 255

	using std::cout;
	using std::endl;
	using std::istringstream;


/*
 * This program is doing image processing on ASCII P2 formate of image of
 * Portable Grey Map (PGM) file format. This program is using a user defined
 * data type (Class) which has detailed information about thr image.pgm and
 * this information is beaing read from the given input source image file
 * (in the command line arguments).
 * After that it performs the given opertaion (also given in the command line arguments),
 * and then write the new image after performing the required operation on the given image
 * into the destination image file (also given in the command line arguments).
 */



/////////////////////////////////////////////////////
// 												   //
//         My Helper Functions					   //
// 												   //
/////////////////////////////////////////////////////

/*
 * My Helper function:
 * This fuction is simply swaping two pointers.
 * Input: two refrence variables of pointers
 */
void swap(int* &a, int* &b) {
    int *temp = a;
    a = b;
    b = temp; 
}
/*
 * My Helper function:
 * This fuction is simply swaping two integers.
 * Input: two refrence variables of integers
 */
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp; 
}
/*
 * My Helper function:
 * This fuction is de-allocating (freeing) the memory of a 2d dynamic array.
 * Input: 	refferance variable of double pointer (2d dynamic array)
			number of pointers in double poniter (number of rows)
 */
void free_2d_array(int** &arr, int rows){
	for (int i = 0; i < rows; ++i){
		delete[] arr[i];
	}
	delete[] arr;
}
/*
 * My Helper function:
 * This fuction is creating a new 2d dynamic array of giver dimentions
 * and the copying the values of input array into newly created
 * dynamic array. And in last, returning the the pointer to the newly created
 * copy of array.
 *
 * Input: 	pointer to the 2d array who's value has to be copied in the new array.
 			number of colmuns and rows of given input array.
 * Outut: 	pointer to the newly created copy of array.
 */
int** creat_dynamic_copy(int** arr, int columns, int row){
	int **arrCopy = new int*[columns];
	for (int i = 0; i < columns; ++i){
		arrCopy[i] = new int[row];
		for (int j = 0; j < row; ++j){
			arrCopy[i][j] = arr[i][j];
		}
	}
	return arrCopy;
}


/////////////////////////////////////////////////////
// 												   //
//         Required Asked functions				   //
// 												   //
/////////////////////////////////////////////////////

SimpleImage invert(const SimpleImage &image) {
	SimpleImage inverted = image;
	// copying the array of garysahed of the picture so that they can be modified.
	int **pixels = inverted.get_pixels();
	// subtracting each value in the grayshade from MAXGRAYSCALE
	for (int i = 0; i < inverted.get_height(); ++i){
		for (int j = 0; j < inverted.get_width(); ++j){
			pixels[i][j] = MAXGRAYSCALE - pixels[i][j];
		}
	} // end of outer for loop

	// returning the inverted image.
	return inverted;
}

SimpleImage vert_flip(const SimpleImage &image) {
	SimpleImage v_flipped = image;

	// copying the array of garysahed of the picture so that they can be modified.
	int **pixels = v_flipped.get_pixels();

	// copying the width and height of image.
	int height = v_flipped.get_height();
	int width = v_flipped.get_width();

	// creating a temporary copy of garyshade pixles array
	int **temp = creat_dynamic_copy(pixels,height,width);

	// swaping the rows with it's own temporary copy.
	// so that it it will swap the 1st row with last row and so on.
	for (int i = 0; i < height; ++i){
		swap(temp[i],pixels[height - 1 - i]);
	}

	// removing the temporary array created above, from the memory and freeing the space.
	free_2d_array(temp,height);

	// returning the flipped image.
	return v_flipped;
}

SimpleImage horiz_flip(const SimpleImage &image) {
	SimpleImage h_flipped = image;

	// copying the array of garysahed of the picture so that they can be modified.
	int **pixels = h_flipped.get_pixels();

	// copying the width and height of image.
	int height = h_flipped.get_height();
	int width = h_flipped.get_width();

	// creating a temporary copy of garyshade pixles array
	int **temp = creat_dynamic_copy(pixels,height,width);

	
	for (int i = 0; i < height; ++i){
		for (int j = 0; j < width; ++j){
			pixels[i][j] = temp[i][width - 1 - j];
		}
	}

	// removing the temporary array created above, from the memory and freeing the space.
	free_2d_array(temp,height);
	
	// returning the flipped image.
	return h_flipped;
}

SimpleImage rotate(const SimpleImage &image) {
	// copying the image into a new image because input image is contstant.
	SimpleImage non_const_image = image;

	// copying the array of garysahed of the picture so that they can be modified.
	int **pixels = non_const_image.get_pixels();

	// copying the width and height of image.
	int height = non_const_image.get_height();
	int width = non_const_image.get_width();

	// creating a temporary copy of garyshade pixles array
	int **temp = creat_dynamic_copy(pixels,height,width);

	// swaping the width and height of image since we are going to rotate it in 90 degree.
	swap(width,height);

	// creating a simple new image of new rotated (swaped) dimentions.
	SimpleImage rotated(height,width);

	// copying the array of garysahed of the new picture so that they can be modified.
	pixels = rotated.get_pixels();

	// copying the values of 1st column from bottom into the 1st row from left to right
	// and the second and so on.
	for (int i = 0; i < height; ++i){
		for (int j = 0; j < width; ++j) {
 			pixels[i][j] = temp[width - j - 1][i];
		}
	}

	// removing the temporary array created above, from the memory and freeing the space.
	free_2d_array(temp,height);

	// returning the rotated (new) image.
	return rotated;
}

SimpleImage scale(const SimpleImage &image, double scalefactor) {
	// copying the image into a new image because input image is contstant.
	SimpleImage non_const_image = image;

	// copying the array of garysahed of the picture so that they can be modified.
	int **pixels = non_const_image.get_pixels();

	// copying the width and height of image.
	int height = non_const_image.get_height();
	int width = non_const_image.get_width();

	// creating a temporary copy of garyshade pixles array
	int **temp = creat_dynamic_copy(pixels,height,width);

	// creating new dimentions of scaled image
	int newHeight = (height*scalefactor+1);
	int newWidth  = (width*scalefactor+1);

	// creating a simple new image of new scaled dimentions.
	SimpleImage scaled(newHeight,newWidth);

	// copying the array of garysahed of the new picture so that they can be modified.
	pixels = scaled.get_pixels();

	// Now copying the garyshaed of copy image into the nearest possible pixel of the scaled image.
	// This will en large or shrink the original image.
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			// finding the nearest possible dimention for placing the garyshade value.
			int c = (int)(j*scalefactor), r = (int)(i*scalefactor);

			pixels[r]  [c] 	 = temp[i][j];
			pixels[r+1][c] 	 = temp[i][j];
			pixels[r]  [c+1] = temp[i][j];
			pixels[r+1][c+1] = temp[i][j];
		}
	}

	// removing the temporary array created above, from the memory and freeing the space.
	free_2d_array(temp,height);

	// returning the scaled (new) image.
	return scaled;
}
			
int main(int argc, char* argv[]) {

	if (argc < 4) {
		cout << "Invalid program execution, please use:\n";
		cout << "./go <inputfile> <outputfile> <operation>\n";
		return(0);
	}

	string infile = argv[1];
	string outfile = argv[2];
	string task = argv[3];

	// Create an image object from a file
	SimpleImage image(infile);

	//FOR DEBUG PURPOSES:
	// image.print();

	//Depending on the task, do what is necessary to the image.
	if (task == "invert") {
		SimpleImage inverted = invert(image);
		inverted.to_file(outfile);
	} else if (task == "verticalFlip") {
		SimpleImage vFlipped = vert_flip(image);
		vFlipped.to_file(outfile);
	} else if (task == "horizontalFlip") {
		SimpleImage hFlip = horiz_flip(image);
		hFlip.to_file(outfile);
	} else if (task == "rotate") {
		SimpleImage rotated = rotate(image);
		rotated.to_file(outfile);
	} else if (task == "scale") {
		if (argc < 5) {
			cout << "Invalid program execution, please use:\n";
			cout << "./go <inputfile> <outputfile> scale <scalefactor value>\n";
			return(0);
		} else {
			double scalefactor;
			istringstream(argv[4]) >> scalefactor;
			SimpleImage scaled = scale(image,scalefactor);
			scaled.to_file(outfile);
		}
	} else {
		cout << "Error in the task: Do not know what " << task << " means.\n";
		return (0);
	}
	
	cout << "All done\n";
	return 0;
}
