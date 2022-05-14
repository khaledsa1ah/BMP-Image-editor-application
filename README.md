# BmpEditor Program 
Made by: ***[Khaled Salah](https://github.com/khaledsa1ah) - [Aya Ali](https://github.com/ayaaalli) - [Youssef Morad](https://github.com/YoussefMorad1)***

Requested by: *Dr. Mohammed El-Ramly in Structured Programming course (Assingment 3)*

## The Idea of the BmpEditor Program 

* This is a simple image processing console project.

* BmpEditor is an image processing tool that can apply different filters to a bit map image of size 256 x 256.

* BmpEditor has 2 versions:
  1. **greyBmpEditor.cpp** is a version that works with GREY images
  2. **rgbBmpEditor.cpp** is a version that works with RGB images 

* BmpEditor uses **bmplib.cpp** Library to load and save the images 
  * **bmplib** is a small library with four functions for loading the pixels of the image into a 2D or 3D array.
The library consists of two files bmplib.cpp and bmplib.h.


## Program Overview

***The list of filters that can be applied to an image before saving it:***

![image](https://user-images.githubusercontent.com/102534922/164736021-f707f434-abab-4e74-a86b-9f5345200914.png)

***Examples of the filters effects:***

| Original Image |
| ----------- | 
| ![image](https://user-images.githubusercontent.com/102534922/164740582-04867427-e31b-459d-80a8-c1494c262091.png) | 
  
|  Black and White | Invert | Merge 2 Images | Flip (vertical-horizontal) |
| ----------- |        ------- | ------------- |  ------------------ |
 | ![image](https://user-images.githubusercontent.com/102534922/164742887-a93e5fc8-429f-47e0-b7e3-349c9dbacf9f.png)  | ![image](https://user-images.githubusercontent.com/102534922/164743000-dac9cb4d-0cac-45ba-9268-c697da570559.png) | ![image](https://user-images.githubusercontent.com/102534922/164743882-4d09eca8-5f0f-4391-bfdc-76ab3d69c695.png) | ![image](https://user-images.githubusercontent.com/102534922/164743489-390d94d3-042d-4e08-9a59-8582c52211e9.png) |

| Rotate (90-180-270-360) | Darken or Lighten | Detect Edges | Enlarge (choose quarter to enlarge) |
| ----------- |        ------- | ----------------- | ---- |
| ![image](https://user-images.githubusercontent.com/102534922/164743627-a5a6a195-5879-4a79-b4af-e0cedc7c8f43.png) | ![image](https://user-images.githubusercontent.com/102534922/164744849-5a2a4b81-0489-4ca0-8454-51a1f4c0c07f.png) | ![image](https://user-images.githubusercontent.com/102534922/164745091-d85348f8-33b9-44bd-acef-fa72fecb1572.png) | ![image](https://user-images.githubusercontent.com/102534922/164746004-754f43c8-1bf7-4274-8f73-2348237df196.png) |

|  Shrink (to 1/2, 1/3, etc) | Mirror (Right-Left-Upper-Lower) | Shuffle (new order to quarters) |  Blur |
| ------------------ | ----------- |        ------- | ----------------- |
| ![image](https://user-images.githubusercontent.com/102534922/164746176-d62f3a03-0401-46ca-bce1-38a12cb4e23b.png) | ![image](https://user-images.githubusercontent.com/102534922/164746245-ef2ed2a2-283c-4728-b696-d19a31f06855.png) | ![image](https://user-images.githubusercontent.com/102534922/164746552-e43bba8f-453c-40a7-a967-1a81cd97e3f6.png) | ![image](https://user-images.githubusercontent.com/102534922/164747531-a9ee393d-1eb7-4e88-b718-bf37780dbf21.png) |



