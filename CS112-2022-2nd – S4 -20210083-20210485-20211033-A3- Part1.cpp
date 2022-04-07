// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: BMP Image Editor.cpp
// Last Modification Date: 02-04-2022
// Author1 and ID and Group: Aya Ali Hassan & 20210083 & A
// Author2 and ID and Group: Khaled Salah Abbas & 20211033 & A
// Author3 and ID and Group: Youssef Mohammed Morad & 20210485 & A
// Teaching Assistant: Eng. Nesma Mohamed & Eng. Yousra Ayman

#include <iostream>
#include <cstring>
#include "bmplib.cpp"


using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char new_image[SIZE][SIZE];

void loadImage();

void load_2_images();

void saveImage();

void BW();

void invert();

void merge();

void flip();

void darkandLight();

void darken();

void lighten();

void rotate();

int main() {
    cout << "Ahlan ya user ya habibi \uF04A\n";
    loadImage();
    while (true) {
        cout << "Please select a filter to apply or 0 to exit:\n"
                "1- Black & White Filter\n"
                "2- Invert Filter\n"
                "3- Merge Filter \n"
                "4- Flip Image\n"
                "5- Darken and Lighten Image \n"
                "6- Rotate Image\n"
                "s- Save the image to a file\n"
                "0- Exit\n"
                ">>";
        char option;
        cin >> option;
        if (option == '1')
            BW();
        else if (option == '2')
            invert();
        else if (option == '3')
            merge();
        else if (option == '4')
            flip();
        else if (option == '5')
            darkandLight();
        else if (option == '6')
            rotate();
        else if (tolower(option)== 's')
            saveImage();
        else if (option == '0')
            return 0;
        cout<<"___________________________________________________\n";
    }
}

void loadImage() {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Please enter file name of the image to process"
            "\n>>";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
    //readGSBMP("Black.bmp", image);
}

//_________________________________________

void load_2_images() {
    char second_imageFileName[100];

    // Get gray scale image file name

    cout << "Please enter file name of the image you want to merge with."
            "\n>>";
    cin >> second_imageFileName;

    // Add to it .bmp extension and load image
    strcat(second_imageFileName, ".bmp");
    readGSBMP(second_imageFileName, image2);
    //readGSBMP("Black.bmp", image);
}

//_________________________________________

void saveImage() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

//_________________________________________

void BW() {
    for (auto &i: image) {
        for (unsigned char &j: i) {
            if (j > 127)
                j = 255;
            else
                j = 0;
        }
    }
}

//_________________________________________

void invert() {
    for (auto &i: image) {
        for (unsigned char &j: i) {
            j = 255 - j;
        }
    }
}

//_________________________________________

void merge() {
    load_2_images();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = (image[i][j] + image2[i][j]) / 2;
        }
    }
}

//_________________________________________

void flip() {
    cout << "Flip (h)orizontally or (v)ertically ?"
            "\n>>";
    char choice;
    cin >> choice;
    if (tolower(choice) == 'v') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                new_image[i][j] = image[255 - i][j];
            }
        }
    } else if (tolower(choice) == 'h') {

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                new_image[i][j] = image[i][255 - j];
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = new_image[i][j];
        }
    }
}


//_________________________________________

void rotate() {
    int degree;
    cout << "Enter the degree you want the image be rotated by :";
    cin >> degree;
    if (degree == 270) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                new_image[255 - j][i] = image[i][j];
            }
        }
    } else if (degree == 180) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                new_image[255 - i][255 - j] = image[i][j];
            }
        }
    } else if (degree == 90) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                new_image[j][255 - i] = image[i][j];
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = new_image[i][j];
        }
    }
}
//_________________________________________

void darkandLight() {
    string choice;
    cout << "Enter 1 if you want to lighten your image\nEnter 2 if you want to darken your image\n";
    cin >> choice;

    while (choice != "1" && choice != "2") {
        cout << "Please enter a valid choice\n";
        cin >> choice;
    }

    if (choice == "1") {
        lighten();
    } else {
        darken();
    }
}

//_________________________________________
void lighten() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = (image[i][j] + 255) / 2;
        }
    }
}

//_________________________________________
void darken() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = image[i][j] / 2;
        }
    }
}
