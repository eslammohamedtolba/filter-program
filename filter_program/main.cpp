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
#include <cmath>
#include "bmplib.cpp"
using namespace std;

unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE] [SIZE];
unsigned char image3[SIZE] [SIZE];
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
    readGSBMP(imageFileName, image);
    
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
    writeGSBMP(imageFileName, image);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
void BWFilter()
{
    
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
    
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
void Invert_Filter()
{
    // this for loops to rotate on all pixels which in the photo 
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        
        //this operation to make the percent of the pixel black becames white and vice versa
        image[i][j]=255-image[i][j];
        }
    }
    
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
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
   //------------------------------------------------------
   cout << "Please enter the name of the image that you want to be saved with : ";
   cin >> image3_name;
   strcat (image3_name, ".bmp");
   writeGSBMP(image3_name, image3);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------
void Flip_Image()
{
    

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
    
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------
void DL_Image()
{
    
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
               if (image[i][j] + image[i][j]/2 > 255)
                {
                     image[i][j] = 255;  
                }
            }  
            }
    }
      
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void rotatebyninteen(){
        
        // this for loops to rotate on all pixels which in the photo 
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = i; j < SIZE - i - 1; j++) {
                //this operation to rotate the photo by 90 degree 
                int temp = image[i][j];
                image[i][j] = image[SIZE - 1 - j][i];
                image[SIZE - 1 - j][i] = image[SIZE - 1 - i][SIZE - 1 - j];
                image[SIZE - 1 - i][SIZE - 1 - j] = image[j][SIZE - 1 - i];
                image[j][SIZE - 1 - i] = temp;
        }}}
void Rotate_Image()
{
    int choice;
    cout<<"Do you want to Rotate (90), (180) or (360) degrees? >>> ";
    cin>>choice;
    // this for loop to take the number of rotates of 90 by divide the entered angle by 90 and by this we can rotate the photo for the user 
    for(int k=0;k<choice/90;k++){
        rotatebyninteen();
    }
    
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
void Detect_Image_Edges()
{
    

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
    
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
void Shrink_Image()
{
   
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
      
   }
   else
   {
      cout<< "Invalid input, only 2 or 3 or 4 :(";
   }
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------
void Mirror_half_Image()
{
    
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
    
}

//----------------------------------------------------------------------------------------------------------------------------------------
void find_coordinates2(int choice,int &i,int &repeatedj,int &row,int &colunm)
{
    //this function to take the number of the photo quarter that the user wanted and makes the variables take the start and last of the quarter from row and colunm
    switch(choice)
    {
        case 1:i=0;repeatedj=0;row=SIZE/2;colunm=SIZE/2;
            break;
        case 2:i=0;repeatedj=SIZE/2;row=SIZE/2;colunm=SIZE;
            break;
        case 3:i=SIZE/2;repeatedj=0;row=SIZE;colunm=SIZE/2;
            break;
        case 4:i=SIZE/2;repeatedj=SIZE/2;row=SIZE;colunm=SIZE;
            break;
    }
}
//this array to store the pixels of the image to exchange quarters between it and the photo 
char image4[SIZE][SIZE];
void find_coordinates1(int choice,int k)
{
    int i,j,repeatedj,row,colunm,x,y,repeatedy;
    find_coordinates2(choice,i,repeatedj,row,colunm);
    
    //this switch to take the number of the quarter of the array that we wanted to fill it by photo pixels and make the variable take the start and last of row and colunm of quarter
    switch(k)
    {
        case 1:x=0;repeatedy=0;
            break;
        case 2:x=0;repeatedy=SIZE/2;
            break;
        case 3:x=SIZE/2;repeatedy=0;
            break;
        case 4:x=SIZE/2;repeatedy=SIZE/2;
            break;
    }
    //this for loop to fill the image by pixels in the array again 
    for(;i<row;i++,x++){
        for(j=repeatedj,y=repeatedy;j<colunm;j++,y++){
            image[x][y]=image4[i][j];
        }
    }

}
void Shuffle_Image()
{
    
    int choice;
    //this for loops to fill the array by the pixels of the image to make second copy of it
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            image4[i][j]=image[i][j];
        }
    }
    cout<<"what is New order of quarters you want to be?"<<endl;
    for(int k=1;k<=4;k++){
        cin>>choice;
        find_coordinates1(choice,k);
    }
    
}
//----------------------------------------------------------------------------------------------------------------------------------------
void Enlarge_Image()
{
    
    int choice,k=1;
    cout<<"what do you want Which quarter to enlarge 1, 2, 3 or 4?"<<endl;
    cin>>choice;
    
    //this for loops to fill the array by the pixels of the image to make second copy of it
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            image4[i][j]=image[i][j];
        }
    }
    find_coordinates1(choice,k);
    
    //this for loops to make each pixel of the photo became 4 pixels in the array in its second filling to make the quarter of 64*64 became 256*256
    for(int k=0,i=0;i<SIZE;k++,i+=2){
        for(int z=0,j=0;j<SIZE;z++,j+=2){
            image4[i][j]=image[k][z];
            image4[i][j+1]=image[k][z];
            image4[i+1][j]=image[k][z];
            image4[i+1][j+1]=image[k][z];
        }
    }
    //to translate all pixels of the array to the image again
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            image[i][j]=image4[i][j];
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------------------------------
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
