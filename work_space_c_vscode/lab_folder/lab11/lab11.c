/******************************************************
*	Lab	11.	함수와 포인터
*	- File:	lab10.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 15
#define HEIGHT 15


typedef struct{
    int width;
    int height;
    unsigned char buffer[WIDTH][HEIGHT];
} IMAGE;

void fill_image(IMAGE *p){
    srand(time(NULL));
    for(int i = 0; i <p->height; i++){
        for(int j = 0 ; j<p->width; j++){
            p->buffer[i][j] = rand()%256;
        }
    }
}

void convert_image(IMAGE *p){
    for(int i = 0; i <p->height; i++){
        for(int j = 0 ; j<p->width; j++){
            if(p->buffer[i][j] < 128){
                p->buffer[i][j] = 0;
            }
            else{
                p->buffer[i][j] = 255;
            }
        }
    }
}

void reverse_image(IMAGE *p){
    for(int i = 0; i <p->height; i++){
        for(int j = 0 ; j<p->width; j++){
            p->buffer[i][j] = (char)(255-(int)(p->buffer[i][j]));
        }
    }
}

void print_image(IMAGE *p){
    for(int i = 0; i <p->height; i++){
        for(int j = 0 ; j<p->width; j++){
            printf("%3d ", p->buffer[i][j]);
        }
        printf("\n");
    }
}

int main(void){
    IMAGE image = {.width = WIDTH, .height = HEIGHT};
    IMAGE backup;
    
    fill_image(&image);
    memcpy(&backup, &image, sizeof(backup));
    printf("--------------------------------------\n");
    printf("Original Image\n");
    printf("--------------------------------------\n");
    print_image(&image);

    printf("--------------------------------------\n");
    printf("Backup Image\n");
    printf("--------------------------------------\n");
    print_image(&backup);


    convert_image(&image);
    printf("--------------------------------------\n");
    printf("Converted Image(from image)\n");
    printf("--------------------------------------\n");
    print_image(&image);


    reverse_image(&backup);
    printf("--------------------------------------\n");
    printf("Converted Image(from backup)\n");
    printf("--------------------------------------\n");
    print_image(&backup);
    
}