#include <iostream>
#include <sstream>
	using std::cout;
	using std::endl;
	using std::istringstream;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp; 
}
int** flip(int pixels[][9], int height, int width){

	swap(width,height);
	int **temp = new int*[height];
	for (int i = 0; i < height; ++i){
		temp[i] = new int[width];
		for (int j = 0; j < width; ++j) {
 			temp[i][j] = pixels[width - j - 1][i];
		}
	}
	return temp;
}

void display(int ** arr, int height, int width){
	for (int i = 0; i < height; ++i){
		for (int j = 0; j < width; ++j){
			cout << arr[i][j] << ' ' ;
		}
		cout << "\n";
	}

}
void display(int ** arr){
	for (int i = 0; arr[i] != NULL; ++i){
		for (int j = 0; arr[i][j] != 0 and arr[i][j] != '\0'; ++j){
			cout << arr[i][j] << '\t' ;
		}
		cout << "\n";
	}

}

int** scale(int** image, int h, int w){
	// dynamic array
	int **out = new int*[h*2];
	for (int i = 0; i < 20; ++i){
		out[i] = new int [w*2];
	}

	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
			out[row*2][col*2] = image[row][col];
			out[row*2+1][col*2] = image[row][col];
			out[row*2][col*2+1] = image[row][col];
			out[row*2+1][col*2+1] = image[row][col];
		}
	}
	display(out);
	return out;
}

int main(int argc, char const *argv[]){
	std::string str[];


	int arr[4][9] = {
					{11,12,13,14,15,16,17,18,19},
					{21,22,23,24,25,26,27,28,29},
					{31,32,33,34,35,36,37,38,39},
					{41,42,43,44,45,46,47,48,49}
					};
	int ** res = flip(arr,4,9);
	// display(res,9,4);
	scale(res,9,4);
	// cout << "Scale \n";
	// display(res,18,8);
	return 0;
}