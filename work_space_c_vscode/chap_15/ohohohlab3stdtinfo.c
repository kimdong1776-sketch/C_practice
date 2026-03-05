#include<stdio.h>

typedef struct student{
    char dept[40];
    char name[20];
    int snum;
} student;

int main(){
    student mylab[] = {
        {"컴퓨터정보공학과", "이미정", 20224576},
        {"컴퓨터정보공학과", "김별이", 20226734},
        {"컴퓨터소프트웨어공학과", "김한수", 20228732}
    };
    FILE *f;
    char fname[] = "student.bin";

    f = fopen(fname, "wb");
    int size = sizeof(mylab) / sizeof(student);
    fwrite(mylab, sizeof(student), size, f);
    fclose(f);

    f = fopen(fname, "rb");
    student lab[size];

    fread(lab, sizeof(student), size, f);
    for(int i = 0 ; i < size ; i++){
        printf("%24s %10s %12d\n", lab[i].dept, lab[i].name, lab[i].snum);

    }
    fclose(f);

    return 0;
}