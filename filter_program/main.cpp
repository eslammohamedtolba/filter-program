// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: xxxxxx.cpp
// Last Modification Date: xx/xx/xxxx
// Author1 and ID and Group: xxxxx xxxxx
// eslam mohamed abdel azim ali and ID and Group: 20211013 group A
// Author3 and ID and Group: xxxxx xxxxx
// Teaching Assistant: xxxxx xxxxx
// Purpose:..........
#include <bits/stdc++.h>//C:\Users\remon\Desktop\assignment3
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
using namespace std;

unsigned char image[SIZE][SIZE];

void loadImage()
{
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin.sync();
    cin.getline(imageFileName, 100);

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
    
}

//_________________________________________
void saveImage()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin.sync();
    cin.getline(imageFileName, 100);

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

//_________________________________________
void BWFilter()
{
    loadImage();
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if(image[i][j] > 127)
            {
                image[i][j] = 255;
            }
            else
            {
                image[i][j] = 0;
            }
        }
    }
    saveImage();
}

//_________________________________________
void Invert_Filter()
{

}
//_________________________________________
void Merge_Filter()
{

}
//_________________________________________
void Flip_Image()
{
    loadImage();

    unsigned char image2[SIZE][SIZE];
    
    char x;
    cout << "do you want to flip (h)orizontally or (v)ertically ?\n>>>> ";
    cin >> x;
    while(x != 'h' && x != 'v')
    {
        cout << "enter \'h\' or \'v\'\n>>>> ";
        cin >> x;
    }
    
    if(x == 'h')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image2[i][255-j] = image[i][j];
            }   
        }
    }

    else if(x == 'v')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image2[255-i][j] = image[i][j];
            }
        }
    }
    swap(image, image2);
    saveImage();
}
//_________________________________________
void DL_Image()
{

}
//_________________________________________
void Rotate_Image()
{

}
//_________________________________________
void Detect_Image_Edges()
{

}
//_________________________________________
void Enlarge_Image()
{

}
//_________________________________________
void Shrink_Image()
{

}
//_________________________________________
void Mirror_half_Image()
{

}
//_________________________________________
void Shuffle_Image()
{

}
//_________________________________________
void Blur_Image()
{

}
//_________________________________________
void Save_image_to_file()
{

}
//_________________________________________
int main() {
    string imagefilename;
    char typefilter;bool boolean=true;
    cout<<"Ahlan ya user ya habibi\n";
    while(boolean)
    {
        cout << "\nPlease select a filter to apply or 0 to exit:\n"
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
                "s- Save the image to a file\n"
                "0- Exit\n"
                ">>>> ";
        cin>>typefilter;
        switch(typefilter)
        {
            case '1':BWFilter();
                break;
            case '2':Invert_Filter();
                break;
            case '3':Merge_Filter();
                break;
            case '4':Flip_Image();
                break;
            case '5':DL_Image();
                break;
            case '6':Rotate_Image();
                break;
            case '7':Detect_Image_Edges();
                break;
            case '8':Enlarge_Image();
                break;
            case '9':Shrink_Image();
                break;
            case 'a':Mirror_half_Image();
                break;
            case 'b':Shuffle_Image();
                break;
            case 'c':Blur_Image();
                break;
            case 's':Save_image_to_file();
                break;
            case '0':boolean=false;
                break;
            default:
                cout<<"the choice you entered isn't correct ";
        }
    }
          
}

