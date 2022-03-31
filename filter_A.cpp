
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

void filter_A();

int main() {
    loadImage();
    filter_A();
    saveImage();
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
void saveImage() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << RED << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

//_________________________________________
void filter_A() {
    cout << BLUE << "Mirror (l)eft, (r)ight, (u)pper, (d)own side?"
                    "\n>>";
    char choice;
    cin >> choice;
    if (choice == 'd') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = image[255 - i][j];
            }
        }
    }else if (choice == 'u') {

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[255-i][j] = image[i][j];;
            }
        }
    }
    else if (choice == 'l') {

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][255-j] = image[i][j];
            }
        }
    }
    else if (choice == 'r') {

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = image[i][255-j];
            }
        }
    }

}
