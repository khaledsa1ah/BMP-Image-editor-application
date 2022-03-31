#include <iostream>
#include <cstring>
#include "bmplib.cpp"

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

void loadImage ();
void saveImage ();
void darkandLight ();

int main()
{
    cout << RED <<"Ahlan ya user ya habibi.\n";
    loadImage();
    darkandLight();
    saveImage();
    return 0;
}

//_________________________________________
void loadImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
    //readGSBMP("Black.bmp", image);
}

//_________________________________________
void saveImage () {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << MAGENTA<<"Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

//_________________________________________
void darkandLight() {
    cout <<BLUE <<"What do you want to do?\n(D)arken the picture"
            "\n(L)ighten the picture\n>>";
    char choice; cin>> choice;
    if (toupper(choice) == 'D'){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            int value = image[i][j];
            image[i][j] = (value)/ 2;
        }
    }}
    else if (toupper(choice)== 'L')
    {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                int value = image[i][j];
                image[i][j] = (value+255)/ 2;
            }
        }
    }
}
