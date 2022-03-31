
#include <iostream>
#include <cstring>
#include "bmplib.cpp"
#include <cmath>
#include <cassert>

#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char new_image[SIZE][SIZE];

void loadImage();

void saveImage();
void save_new_Image();
void rotate();

int main() {
    loadImage();
    rotate();
    save_new_Image()
    return 0;
}

//_________________________________________
void loadImage() {
    char imageFileName[100];

    // Get gray scale image file name
    cout << RED << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

//_________________________________________
void save_new_Image() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << RED << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, new_image);
}

//_________________________________________
void rotate() {
    cout << BLUE << "Rotate (90), (180) or (360) degrees?"
                    "\n>>";
    string choice;
    cin >> choice;
    if (choice == "180") {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                new_image[i][j] = image[255 - i][255 - j];
            }
        }
    } else if (choice == "90") {

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                new_image[j][i] = image[255 - i][j];
            }
        }
    }

}
