#include <bits/stdc++.h>
using namespace std;
void BWFilter()
{

}
void Invert_Filter()
{

}
void Merge_Filter()
{

}
void Flip_Image()
{

}
void DL_Image()
{

}
void Rotate_Image()
{

}
void Detect_Image_Edges()
{

}
void Enlarge_Image()
{

}
void Shrink_Image()
{

}
void Mirror_half_Image()
{

}
void Shuffle_Image()
{

}
void Blur_Image()
{

}
void Save_image_to_file()
{

}
int main() {
    string imagefilename;char typefilter;cin.ignore();
    cout<<"Ahlan ya user ya habibi\n"
          "Please enter file name of the image to process:"<<endl;
    getline(cin,imagefilename);
    cout<<"Please select a filter to apply or 0 to exit:\n"
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
          "0- Exit"<<endl;
    cin>>typefilter;
    if(typefilter=='1'){
        BWFilter();
    }
    if(typefilter=='2'){
        Invert_Filter();
    }
    if(typefilter=='3'){
        Merge_Filter();
    }
    if(typefilter=='4'){
        Flip_Image();
    }
    if(typefilter=='5'){
        DL_Image();
    }
    if(typefilter=='6'){
        Rotate_Image();
    }
    if(typefilter=='7'){
        Detect_Image_Edges();
    }
    if(typefilter=='8'){
        Enlarge_Image();
    }
    if(typefilter=='9'){
        Shrink_Image();
    }
    if(typefilter=='a'){
        Mirror_half_Image();
    }
    if(typefilter=='b'){
        Shuffle_Image();
    }
    if(typefilter=='c'){
        Blur_Image();
    }
    if(typefilter=='s'){
        Save_image_to_file();
    }
    return 0;
}
