// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: main.cpp
// Last Modification Date: 04/04/2022
// Author1 and ID and Group: Remon atef mahrows daniel, 20210141, group A
// Author2 and ID and Group: Eslam mohamed abdel azim ali, 20211013, group A
// Author3 and ID and Group: Seifeldeen mohamed ahmed mohamed, 20210168, group A
// Teaching Assistant: Eng.Afaf Abelmonem
// Purpose: applt filters  to gray (256 * 256) images
#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
#include <cmath> //C:\Users\remon\Desktop\assignment3\mario
#include "bmplib.cpp"
using namespace std;

unsigned char image[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
void loadImage()
{
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file full path\n>>>> ";
    cin.sync();
    cin.getline(imageFileName, 100);

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
    
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------
void saveImage()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file full path\n>>>> ";
    cin.sync();
    cin.getline(imageFileName, 100);

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
void BWFilter()
{
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            
            if((image[i][j][0]+image[i][j][1]+image[i][j][2])/3 > 127)//if pixel is bigger than average let it be white
            {
                image[i][j][0] = image[i][j][1] = image[i][j][2] = 255;
            }
            else // else make it black
            {
                image[i][j][0] = image[i][j][1] = image[i][j][2] = 0;
            }
            
        }
    }    
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

void Flip_Image()
{
    unsigned char image2[SIZE][SIZE][RGB];

    char x;
    cout << "do you want to flip (h)orizontally or (v)ertically ?\n>>>> ";
    cin >> x;
    while(x != 'h' && x != 'v' && x != 'H' && x != 'V')
    {
        cout << "enter \'h\' or \'v\'\n>>>> ";
        cin >> x;
    }
    
    if(x == 'h' || x == 'H')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < 3; k++){                
                    image2[i][255-j][k] = image[i][j][k]; // that line flip the image horizontally
                }
            }   
        }
    }

    else if(x == 'v' || x == 'V')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < 3; k++){                
                    image2[255-i][j][k] = image[i][j][k]; // that line flip the image vertically
                }
            }
        }
    }
    swap(image, image2);
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------
void Detect_Image_Edges()
{
    

    unsigned char image2[SIZE][SIZE][RGB];
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            
            if((image[i][j][0]+image[i][j][1]+image[i][j][2])/3 > 127)//if pixel is bigger than average let it be white
            {
                image[i][j][0] = image[i][j][1] = image[i][j][2] = 255;
            }
            else // else make it black
            {
                image[i][j][0] = image[i][j][1] = image[i][j][2] = 0;
            }
            
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        { // if there is any white pixel around the pixel i am in its index
            if(image[i][j][0] == 0 && (image[i+1][j][0] == 255 || image[i-1][j][0] == 255 || image[i][j+1][0] == 255 || image[i][j-1][0] == 255 || image[i+1][j-1][0] == 255 || image[i+1][j+1][0] == 255 || image[i-1][j-1][0] == 255 || image[i-1][j+1][0] == 255))
            {
                image2[i][j][0] = image2[i][j][1] = image2[i][j][2] = 0; // then turn it black

            }
            else
            {
                image2[i][j][0] = image2[i][j][1] = image2[i][j][2] = 255; // else make it white
            }
        }   
    }


    swap(image, image2);
    
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------
void Mirror_half_Image()
{
    
    unsigned char image2[SIZE][SIZE][RGB];

    char y;
    cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side?\n>>>> ";
    cin >> y;
    while(y != 'l' && y != 'L' && y != 'r' && y != 'R' && y != 'u' && y != 'U' && y != 'd' && y != 'D')
    {
        cout << "enter \'l\' or \'r\' or \'u\' or \'d\'";
        cin >> y;
    }
    if(y == 'l' || y == 'L')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE/2; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    image2[i][j][k] = image[i][j][k]; // copy the left half
                }
            }
            for (int j = SIZE/2, m = SIZE/2; j >= 0; j--, m++)
            {
                for (int k = 0; k < 3; k++)
                {
                    image2[i][m][k] = image[i][j][k]; // copy the left half on right half 
                } 
            }
        }
    }
    else if(y == 'r' || y == 'R')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = SIZE/2; j < SIZE; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    image2[i][j][k] = image[i][j][k]; // copy the right half
                }
            }
            for (int j = 0, m = SIZE-1; j < SIZE/2; j++, m--)
            {
                for (int k = 0; k < 3; k++)
                {
                    image2[i][j][k] = image[i][m][k]; // copy the right half on left half 
                }
            }
        }

    }
    else if(y == 'u' || y == 'U')
    {
        for (int i = 0; i < SIZE/2; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    image2[i][j][k] = image[i][j][k]; // copy the upper half
                    image2[255-i][j][k] = image[i][j][k]; // copy the upper half on the lower half 
                }
            }
        }
    }
    else if(y == 'd' || y == 'D')
    {
        for (int i = SIZE/2; i < 256; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    image2[i][j][k] = image[i][j][k]; // copy the upper half
                    image2[255-i][j][k] = image[i][j][k]; // copy the upper half on the lower half 
                }
            }
        }
    }

    swap(image, image2);
    
}



//--------------------------------------------------------------------------------------------------------------------------------------------------------------
int main() {
    string imagefilename;
    char typefilter;
    bool boolean=true, load_Image=true;
    cout<<"Ahlan ya user ya habibi :)\n";
    
    //this while to be available to the user to change on the photo more than once
    while(boolean)
    {
        //this function to load second photo insead of the last photo when the user choose 
        if(load_Image)
        {
            loadImage();
            load_Image = false;
        }
        cout << "\nPlease select a filter to apply or 0 to exit:\n\n"
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
                "s- save Image\n"
                "0- Exit\n"
                ">>>> ";
        cin>>typefilter;
         switch(typefilter)
        {
            case '1':BWFilter();
                cout << "\nthe black and white filter has been applied  :)" << endl;
                break;
            case '2':Invert_Filter();
                cout << "\nthe invert filter has been applied  :)" << endl;
                break;
            case '3':Merge_Filter();
                cout << "\nthe merge filter has been applied  :)" << endl;
                break;
            case '4':Flip_Image();
                cout << "\nthe flip image filter has been applied  :)" << endl;
                break;
            case '5':DL_Image();
                cout << "\nthe darken and lighten filter has been applied  :)" << endl;
                break;
            case '6':Rotate_Image();
                cout << "\nthe rotate image filter has been applied  :)" << endl;
                break;
            case '7':Detect_Image_Edges();
                cout << "\nthe detect image edges filter has been applied  :)" << endl;
                break;
            case '8':Enlarge_Image();
                cout << "\nthe enlarge image filter has been applied  :)" << endl;
                break;
            case '9':Shrink_Image();
                cout << "\nthe shrink image filter has been applied  :)" << endl;
                break;
            case 'a':Mirror_half_Image();
                cout << "\nthe mirror half filter has been applied  :)" << endl;
                break;
            case 'b':Shuffle_Image();
                cout << "\nthe shuffle image filter has been applied  :)" << endl;
                break;
            case 'c':Blur_Image();
                cout << "\nthe blur filter has been applied  :)" << endl;
                break;
            case 's':saveImage();
                cout << "\nyour image has been saved  :)" << endl;
                load_Image = true;
                break;
            case '0':boolean=false;
                cout << "\ngood bye :)" << endl;
                break;
            default:
                cout<<"the choice you entered isn't correct";
        }
    }       
}
