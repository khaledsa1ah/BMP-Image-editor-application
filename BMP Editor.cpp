// FCI – Programming 1 – 2022 - Assignment 3 
// Program Name: BMP Image Editor.cpp
// Last Modification Date: 02-04-2022
// Author1 and ID and Group: Aya Ali Hassan & 20210083 & A
// Author2 and ID and Group: Khaled Salah Abbas & 20211033 & A
// Author3 and ID and Group: Youssef Mohammed Morad & 20210485 & A
// Teaching Assistant: Eng. Nesma Mohamed & Eng. Yousra Ayman

#include <iostream>
#include <regex>
#include <cstring>
#include "bmplib.cpp"


using namespace std;

unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char new_image[SIZE][SIZE];

void loadImage();

void saveImage();

void BW();

void invert();

void merge();

void flip();

void detect_edges();

void darkandLight();

void darken();

void lighten();

void rotate();

void filter_b();

void filter_c();

void filter_a();

void enlarge_image();

void shrink_image();

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
                "7- Detect Image Edges \n"
                "8- Enlarge Image\n"
                "9- Shrink Image\n"
                "a- Mirror 1/2 Image\n"
                "b- Shuffle Image\n"
                "c- Blur Image\n"
                "s- Save the image to a file(demo)\n"
                "0- Exit\n"
                ">>";
        char option;
        cin >> option;

        if (tolower(option) == 'a')
            filter_a();
        else if (tolower(option) == 'b')
            filter_b();
        else if (tolower(option) == 'c')
            filter_c();
        else if (tolower(option) == 's')
            saveImage();
        else if (option == '1')
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
        else if (option == '7')
            detect_edges();
        else if (option == '8')
            enlarge_image();
        else if (option == '9')
            shrink_image();
        else if (option == '0')
            return 0;
        cout << "\n_______________________________________________________________\n";
    }
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
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = new_image[i][j];
        }
    }
}

//_________________________________________
void lighten() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            new_image[i][j] = (image[i][j] + 255) / 2;
        }
    }
}

//_________________________________________
void darken() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            new_image[i][j] = image[i][j] / 2;
        }
    }
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
void merge() {
    load_2_images();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            new_image[i][j] = (image[i][j] + image2[i][j]) / 2;
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
void invert() {
    for (auto &i: image) {
        for (unsigned char &j: i) {
            j = 255 - j;
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
void filter_b() {
    string order;
    unsigned char Quarter_1[SIZE][SIZE];
    unsigned char Quarter_2[SIZE][SIZE];
    unsigned char Quarter_3[SIZE][SIZE];
    unsigned char Quarter_4[SIZE][SIZE];
    cout << "Enter the order of quarters you want the image to be ordered by :" << endl;
    getline(cin >> ws, order, '\n');
    for (int i = 0; i < order.length(); i++) {
        if (order[i] == ' ') {
            order.erase(i, 1);
        }
    }
    for (int i = 0; i < 4; i++) {
        while (order[i] != '1' and order[i] != '2' and order[i] != '3' and order[i] != '4') {
            cout << "Please enter a valid order :" << endl;
            getline(cin >> ws, order, '\n');
            for (int i = 0; i < order.length(); i++) {
                if (order[i] == ' ') {
                    order.erase(i, 1);
                }
            }
        }
    }
    for (int i = 0; i < 128; i++) {
        for (int j = 0; j < 128; j++) {
            Quarter_1[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < 128; i++) {
        for (int j = 128; j < 256; j++) {
            Quarter_2[i][j] = image[i][j];
        }
    }
    for (int i = 128; i < 256; i++) {
        for (int j = 0; j < 128; j++) {
            Quarter_3[i][j] = image[i][j];

        }
    }
    for (int i = 128; i < 256; i++) {
        for (int j = 128; j < 256; j++) {
            Quarter_4[i][j] = image[i][j];
        }
    }
    for (int k = 0; k < 4; k++) {
        if (k == 0) {
            for (int i = 0; i < 128; i++) {
                for (int j = 0; j < 128; j++) {
                    if (order[0] == '1') {
                        new_image[i][j] = Quarter_1[i][j];
                    } else if (order[0] == '2') {
                        new_image[i][j] = Quarter_2[i][128 + j];
                    } else if (order[0] == '3') {
                        new_image[i][j] = Quarter_3[128 + i][j];
                    } else if (order[0] == '4') {
                        new_image[i][j] = Quarter_4[128 + i][128 + j];
                    }
                }
            }

        } else if (k == 1) {
            for (int i = 0; i < 128; i++) {
                for (int j = 128; j < 256; j++) {
                    if (order[1] == '1') {
                        new_image[i][j] = Quarter_1[i][j - 128];
                    } else if (order[1] == '2') {
                        new_image[i][j] = Quarter_2[i][j];
                    } else if (order[1] == '3') {
                        new_image[i][j] = Quarter_3[128 + i][j - 128];
                    } else if (order[1] == '4') {
                        new_image[i][j] = Quarter_4[128 + i][j];
                    }
                }
            }


        } else if (k == 2) {
            for (int i = 128; i < 256; i++) {
                for (int j = 0; j < 128; j++) {
                    if (order[2] == '1') {
                        new_image[i][j] = Quarter_1[i - 128][j];
                    } else if (order[2] == '2') {
                        new_image[i][j] = Quarter_2[i - 128][128 + j];
                    } else if (order[2] == '3') {
                        new_image[i][j] = Quarter_3[i][j];
                    } else if (order[2] == '4') {
                        new_image[i][j] = Quarter_4[i][128 + j];
                    }
                }
            }
        } else if (k == 3) {
            for (int i = 128; i < 256; i++) {
                for (int j = 128; j < 256; j++) {
                    if (order[3] == '1') {
                        new_image[i][j] = Quarter_1[i - 128][j - 128];
                    } else if (order[3] == '2') {
                        new_image[i][j] = Quarter_2[i - 128][j];
                    } else if (order[3] == '3') {
                        new_image[i][j] = Quarter_3[i][j - 128];
                    } else if (order[3] == '4') {
                        new_image[i][j] = Quarter_4[i][j];
                    }
                }
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
void filter_c() {
    string radius_;
    cout << "Please enter the radius you want to blur your image with:\n";

    // taking radius input from user
    cin >> radius_;
    regex validChoice("0*[1-9][0-9]*");
    while (!regex_match(radius_, validChoice)) {
        cout << "Please enter a valid radius:\n";
        cin >> radius_;
    }

    int radius = stoi(radius_);

    for (int i = radius; i < SIZE -
                             radius; i++) { // loop for every possible row that has the needed radius around (without going out of boundaries)
        for (int j = radius; j < SIZE -
                                 radius; j++) { // loop for every possible column that has the needed radius around (without going out of boundaries)

            // ave variable to calculate the color of the blurred pixel by getting the average color of a group of pixels
            int ave = 0;

            // adding the color of these group of pixels then diving by the number of them
            for (int k = i - radius; k <= i + radius; k++) {
                for (int l = j - radius; l <= j + radius; l++) {
                    ave += image[k][l];
                }
            }
            ave /= (2 * radius + 1) * (2 * radius + 1);

            // filling the correspondent pixels with the blurred average in the new image
            for (int k = i - radius; k <= i + radius; k++) {
                for (int l = j - radius; l <= j + radius; l++) {
                    new_image[k][l] = ave;
                }
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
void filter_a() {
    cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side?"
            "\n>>";
    char choice;
    cin >> choice;
    tolower(choice);
    while (choice != 'd' && choice != 'u' && choice != 'l' && choice != 'r') {
        cout << "Please, enter a valid choice: ";
        cin >> choice;
    }
    if (choice == 'd') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = image[255 - i][j];
            }
        }
    }
    else if (choice == 'u') {

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[255 - i][j] = image[i][j];
            }
        }
    } else if (choice == 'l') {

        for (auto &i: image) {
            for (int j = 0; j < SIZE; j++) {
                i[255 - j] = i[j];
            }
        }
    } else if (choice == 'r') {

        for (auto &i: image) {
            for (int j = 0; j < SIZE; j++) {
                i[j] = i[255 - j];
            }
        }
    }
}

//_________________________________________
void enlarge_image() {
    int Quarter;
    cout << "Enter the quarter you want to enlarge :";
    cin >> Quarter;
    while (Quarter > 5 or Quarter < 0) {
        cout << "Enter a valid number :";
        cin >> Quarter;
    }
    if (Quarter == 1) {
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                new_image[i][j] = image[i / 2][j / 2];
            }
        }
    } else if (Quarter == 2) {
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                new_image[i][256 - j] = image[i][256 - j / 2];
            }
        }
    } else if (Quarter == 3) {
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                new_image[256 - i][j] = image[256 - i / 2][j / 2];
            }
        }
    } else if (Quarter == 4) {
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                new_image[256 - i][256 - j] = image[256 - i / 2][256 - j / 2];
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
void shrink_image() {

    cout << "How much do you want to shrink your image?\n"
            "The program will shrink it for 1/(a) of the image original dimensions\n"
            "Enter a:";

    string choice;
    int nCombinedPixels;
    cin >> choice;

    regex validChoice("0*[1-9][0-9]*");
    while (!regex_match(choice, validChoice)) {
        cout << "Please enter a valid choice:\n";
        cin >> choice;
    }

    nCombinedPixels = stoi(choice);

    // shrinking horizontally (a row will have fewer columns)
    for (auto &i: image) { // loop over all rows of new image

        //the start of the columns (in the same row) to take their average
        int st = 0;

        for (int j = 0; j < SIZE / nCombinedPixels; j++) { // loop over the needed columns to fill

            // the average color in the new pixel
            int ave = 0;
            for (int k = st; k < st + nCombinedPixels; k++) {
                ave += i[k];
            }

            // save the new color in the original image (as we're not done of shrinking yet)
            i[j] = ave / (nCombinedPixels);

            // the new start of the next 2 columns to get their average
            st += nCombinedPixels;
        }
    }

    // shrinking vertically after the horizontally (a column will have fewer rows)
    for (int i = 0; i < SIZE / nCombinedPixels; i++) { // loop over needed columns of new image to fill

        // the start of the rows (in the same column) to take their average
        int st = 0;

        for (int j = 0; j < SIZE / nCombinedPixels; j++) {

            // the average color in the new pixel
            int ave = 0;
            for (int k = st; k < st + nCombinedPixels; k++) {
                ave += image[k][i];
            }

            // save the new color in the new image (shrinking is done for this pixel)
            new_image[j][i] = ave / (nCombinedPixels);

            // the new start of the next 2 rows to get their average
            st += nCombinedPixels;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = new_image[i][j];
        }
    }
}

//_________________________________________
void detect_edges() {

    for (auto &i: image) {
        for (unsigned char &j: i) {
            if (j > 127)
                j = 255;
            else
                j = 0;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            new_image[i][j] =
                    (image[i][j - 1]) + (image[i - 1][j]) + (image[i][j] * -4) + (image[i + 1][j]) +
                    (image[i][j + 1]);
        }
    }

    for (auto &i: new_image) {
        for (unsigned char &j: i) {
            j = 255 - j;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = new_image[i][j];
        }
    }
}
