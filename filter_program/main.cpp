// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: xxxxxx.cpp
// Last Modification Date: xx/xx/xxxx
// Author1 and ID and Group: xxxxx xxxxx
// eslam mohamed abdel azim ali and ID and Group: 20211013 group A
// Author3 and ID and Group: xxxxx xxxxx
// Teaching Assistant: xxxxx xxxxx
// Purpose:..........
#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
using namespace std;

unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE] [SIZE];
unsigned char image3[SIZE] [SIZE];
//_________________________________________
void loadImage()
{
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name\n>>>> ";
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
    cout << "Enter the target image file name\n>>>> ";
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
   char image_name [20];
   char image2_name [20];
   char image3_name [20];
   cout << "Please Enter the image file name to load it : ";
   cin  >>  image_name;
   strcat (image_name , ".bmp");
   readGSBMP (image_name , image);
   //++++++++++++++++++++++++++++++++ 
   cout << "Please enter the second image file name to merge it : ";
   cin  >> image2_name;
   strcat (image2_name , ".bmp");
   readGSBMP (image2_name , image2);
   //++++++++++++++++++++++++++++++++
   for (int i = 0; i < SIZE; i++)
   {
      for (int j = 0; j < SIZE;j++)
      {
        image3[i][j] = (image[i][j] + image2[i][j])/4;
      } 
   }
   //++++++++++++++++++++++++++++++++ 
   cout << "Please enter the name of the image that you want to be saved with : ";
   cin >> image3_name;
   strcat (image3_name, ".bmp");
   writeGSBMP(image3_name, image3);
}
//_________________________________________
void Flip_Image()
{
    loadImage();

    unsigned char image2[SIZE][SIZE];
    
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
                image2[i][255-j] = image[i][j];
            }   
        }
    }

    else if(x == 'v' || x == 'V')
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
    loadImage();
    int choice;
    cout << "Type 1 if you want to Darken the image\n";
    cout << "Type 2 if you want to Lighten the image\n";
    cin >> choice;
    if (choice == 1)
    {
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] = image[i][j] - int(0.5 * image[i][j]);
            }
    }
    }
    else if (choice == 2)
    {
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] =image[i][j] + 30 ;
            }  
            }
    }
    saveImage();  
}
//_________________________________________
void Rotate_Image()
{

}

//_________________________________________
void Detect_Image_Edges()
{
    loadImage();

    unsigned char image2[SIZE][SIZE];
    
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

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if(image[i][j] == 0 && (image[i+1][j] == 255 || image[i-1][j] == 255 || image[i][j+1] == 255 || image[i][j-1] == 255 || image[i+1][j-1] == 255 || image[i+1][j+1] == 255 || image[i-1][j-1] == 255 || image[i-1][j+1] == 255))
            {
                image2[i][j] = 0;

            }
            else
            {
                image2[i][j] = 255;
            }
        }   
    }


    swap(image, image2);
    saveImage();
}

//_________________________________________
void Enlarge_Image()
{

}

//_________________________________________
void Shrink_Image()
{
   loadImage();
   int measure;
   cout << "Plz, Enter the number of measure that you want\n" << endl;
   cout << "1. Type 2 to resize it to half." << endl;
   cout << "2. Type 3 to resize it to third." << endl;
   cout << "3. Type 4 to resize it to quarter." << endl;
   cin >> measure;
   if (measure == 2 || measure == 3 || measure == 4)
   {
      for (int i = 0; i < SIZE; i++)
   {
      for (int j = 0; j < SIZE; j++)
      {
         image[i/measure][j/measure] = image[i][j];
         image[i][j] = 255;
      }
   }
   saveImage();   
   }
   else
   {
      cout<< "Invalid input, only 2 or 3 or 4 :(";
   }
}
//_________________________________________
void Mirror_half_Image()
{
    loadImage();
    unsigned char image2[SIZE][SIZE];

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
                image2[i][j] = image[i][j];
            }
            for (int j = SIZE/2, m = SIZE/2; j >= 0; j--, m++)
            {
                image2[i][m] = image[i][j];
            }
        }
    }
    else if(y == 'r' || y == 'R')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = SIZE/2; j < SIZE; j++)
            {
                image2[i][j] = image[i][j];
            }
            for (int j = 0, m = SIZE-1; j < SIZE/2; j++, m--)
            {
                image2[i][j] = image[i][m];
            }
        }

    }
    else if(y == 'u' || y == 'U')
    {
        for (int i = 0; i < SIZE/2; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image2[i][j] = image[i][j];
                image2[255-i][j] = image[i][j];
            }
        }

    }
    else if(y == 'd' || y == 'D')
    {
        for (int i = SIZE/2; i < 256; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image2[i][j] = image[i][j];
                image2[255-i][j] = image[i][j];
            }
        }
    }

    swap(image, image2);
    saveImage();
}

//_________________________________________
void Shuffle_Image()
{

}

//_________________________________________
void Blur_Image()
{
     for (int blur = 0; blur < 5; blur++)
   {
      for (int i = 0; i < SIZE; i++)
      {
         for (int j = 2; j < SIZE; j++)
         {
            image[i][j - 1] = (image[i][j] + image[i][j-2])/2;  
         }
         for (int j = 0; j < SIZE; j++)
         {
            if (i == 0)
            {
               break;
            }
            image2[i - 1][j] = (image[i - 2][j] + image[i][j])/2; 
         }
      }
      for (int i = 0; i < SIZE; i++)
      {
         for (int j = 0; j < SIZE; j++)
         {
            image[i][j] = image2[i][j];
         }  
      }  
   }
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
                "0- Exit\n"
                ">>>> ";
        cin>>typefilter;
        switch(typefilter)
        {
            case '1':BWFilter();
                cout << "\nthe black and white filter has been applied  :)" << endl;
                break;
            case '2':Invert_Filter();
                break;
            case '3':Merge_Filter();
                break;
            case '4':Flip_Image();
                cout << "\nthe flip image filter has been applied  :)" << endl;
                break;
            case '5':Rotate_Image();
                break;
            case '6':DL_Image();
                break;
            case '7':Detect_Image_Edges();
                cout << "\nthe detect image edges filter has been applied  :)" << endl;
                break;
            case '8':Enlarge_Image();
                break;
            case '9':Shrink_Image();
                break;
            case 'a':Mirror_half_Image();
                cout << "\nthe mirror half filter has been applied  :)" << endl;
                break;
            case 'b':Shuffle_Image();
                break;
            case 'c':Blur_Image();
                break;
            case '0':boolean=false;
                break;
            default:
                cout<<"the choice you entered isn't correct ";
        }
    }       
}
