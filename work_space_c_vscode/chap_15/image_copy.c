#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE*src_file, *dst_file;
    char srcname[100] = {0};
    char dstname[100] = {0};
    char buffer[1024];
    int rd_byte;
    int total_byte = 0;

    printf("Type the original image file name: ");
    scanf("%s", srcname);
    printf("Type a file name for saving");
    scanf("%s", dstname);

    src_file = fopen(srcname, "rb");
    dst_file = fopen(dstname, "wb");
    if(src_file == NULL || dst_file == NULL){
        fprintf(stderr, "file open error\n");
        exit(1);    
    }

    while((rd_byte = fread(buffer, sizeof(char), sizeof(buffer), src_file)) > 0){
        total_byte += rd_byte;
        int wr_bytes = fwrite(buffer, sizeof(char), rd_byte, dst_file);

        printf("rd_bytes = %d, wr_bytes = %d\n", rd_byte, wr_bytes);
    }
    printf("Complete file copy (%s to %s) file size = %d Btytes\n", srcname, dstname, total_byte);

    fclose(src_file);
    fclose(dst_file);
}