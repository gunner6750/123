# include <stdio.h>
# define STB_IMAGE_IMPLEMENTATION
# include "headers\stb_image.h"
# define STB_IMAGE_WRITE_IMPLEMENTATION
# include "headers\stb_image_write.h"
int main(){
    // declare variables
    int width , height , channel ;
    char background[] = "./images1/background.jpg";
    char foreground[] = "./images1/foreground.jpg";
    char weather[] = "./images1/new_background.jpg";
    char save_path [] = "./images1/saved.jpg";
    // read image data
    unsigned char *image1 = stbi_load(foreground , &width , &height , &channel , 0);
    if ( image1 == NULL )
    {
        printf ("\nError in loading the image1 \n");
        exit(1) ;
    }
    //printf (" Width = %d\nHeight = %d\nChannel = %d\n", width , height , channel );
    unsigned char *greenscreen = stbi_load(background , &width , &height , &channel , 0);
    if ( greenscreen == NULL )
    {
        printf ("\nError in loading the image2 \n");
        exit(1) ;
    }
    unsigned char *weatherr = stbi_load(weather , &width , &height , &channel , 0);
    if ( weather == NULL )
    {
        printf ("\nError in loading the image3 \n");
        exit(1) ;
    }
    for (int i=0;i<height;i++){
        for (int j = 0; j < width ; j++){
                for ( int k = 0; k < channel ; k++){
                        if (image1[i * width * channel + j * channel + k]==greenscreen[i * width * channel + j * channel + k])
                        image1[i * width * channel + j * channel + k]=weatherr[i * width * channel + j * channel + k];
                }
        }
    }
    // save image
    stbi_write_png(save_path , width , height , channel , image1, width *channel );
    printf (" New image saved to %s\n", save_path);
}
