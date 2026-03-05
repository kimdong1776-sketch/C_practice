/******************************************************
 *	- File:	hw10.c
 *	- ID:	2025003170
 *	- Name:	김  동후
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5

typedef struct {
    int id;            // 학번
    char name[20];     // 이름
    int mid;           // 중간고사 점수 (100점 만점, 30%)
    int final;         // 기말고사 점수 (100점 만점, 40%)
    int hw1;           // 과제1 점수 (30점 만점)
    int hw2;           // 과제2 점수 (30점 만점)
    int attendance;    // 출석 점수 (10점)
} STUDENT;

// 학생 별 STUDENT_SCORE 구조체를 만들고 값을 저장해야 됨
typedef struct {
    int id;            // 학번
    char name[20];     // 이름
    double mid;
    double final;
    double hw;
    int attendance;
    double total;
    char score[3];
    /* 필요한 변수 추가 */
} STUDENT_SCORE;

void load_file(STUDENT *stu){
    
    char f_naem[] = "students.txt";
    FILE *s;

    if((s = fopen(f_naem, "r"))==NULL){
        printf("파일이 열리지 않습니다.");
        exit(1);
    }
    for(int i = 0; i< MAX_SIZE; i++){
        fscanf(s,"%d %s %d %d %d %d %d\n",
            &stu[i].id, 
            stu[i].name, 
            &stu[i].mid, 
            &stu[i].final, 
            &stu[i].hw1, 
            &stu[i].hw2, 
            &stu[i].attendance);// ex 2023024 Evan 56 90 15 20 10
    }
    fclose(s);     
}

void print_raw_data(STUDENT *stu){
    for(int i = 0; i< MAX_SIZE; i++){
        printf("%10d %10s %6d %6d %5d %5d %12d\n",
            stu[i].id, 
            stu[i].name, 
            stu[i].mid, 
            stu[i].final, 
            stu[i].hw1, 
            stu[i].hw2, 
            stu[i].attendance);// ex 2023024 Evan 56 90 15 20 10
    }
}

void caclulate_score(STUDENT_SCORE *stu, STUDENT *sorce){
    double cmp;
    for(int i = 0; i< MAX_SIZE; i++){
        stu[i].id = sorce[i].id;
        strcpy(stu[i].name, sorce[i].name);
        stu[i].mid = (double)sorce[i].mid * 0.3;
        stu[i].final = (double)sorce[i].final * 0.4;
        stu[i].hw = (sorce[i].hw1 + sorce[i].hw2)/2.0;
        stu[i].attendance = sorce[i].attendance;
        stu[i].total = stu[i].mid+ stu[i].final + stu[i].hw+ stu[i].attendance;
        cmp = stu[i].total;
        if(cmp < 60){
            strcpy(stu[i].score, "F");
        }
        else if(cmp < 70){
            if(cmp < 65){
                strcpy(stu[i].score, "D0");
            }
            else{
                strcpy(stu[i].score, "D+");
            }
        }
        else if(cmp < 80){
            if(cmp < 75){
                strcpy(stu[i].score, "C0");
            }
            else{
                strcpy(stu[i].score, "C+");
            }
        }
        else if(cmp < 90){
            if(cmp < 85){
                strcpy(stu[i].score, "B0");
            }
            else{
                strcpy(stu[i].score, "B+");
            }
        }
        else{
            if(cmp < 95){
                strcpy(stu[i].score, "A0");
            }
            else{
                strcpy(stu[i].score, "A+");
            }
        }
            
    }
}

void print_credit(STUDENT_SCORE * stu){
    for(int i = 0; i< MAX_SIZE; i++){
        printf("%10d %10s %6.1lf %6.1lf %6.1lf %12d %6.1lf %6s\n",
            stu[i].id, 
            stu[i].name, 
            stu[i].mid, 
            stu[i].final, 
            stu[i].hw, 
            stu[i].attendance,
            stu[i].total,
            stu[i].score);// ex 2023024 Evan 56 90 15 20 10
    }
}

int main(){
    STUDENT students[MAX_SIZE];
    STUDENT_SCORE student_scores[MAX_SIZE];
    memset(students, 0, sizeof(students));
    memset(student_scores, 0, sizeof(student_scores));

    load_file(students);
    printf("[SCORES OF STUDENTS]\n");
    printf("%10s %10s %6s %6s %5s %5s %12s\n", "ID", "NAME", "MID", "FINAL", "HW1", "HW2", "ATTENDANCE");
    printf("-------------------------------------------------------\n");
    print_raw_data(students);
    printf("-------------------------------------------------------\n\n\n");
    
    printf("[CREDITS OF STUDENTS]\n");
    caclulate_score(student_scores, students);
    printf("%10s %10s %6s %6s %6s %12s %6s %6s\n", "ID", "NAME", "MID", "FINAL", "HW1", "ATTENDANCE", "TOTAL", "SCORE");
    printf("-------------------------------------------------------------------------\n");
    print_credit(student_scores);
    printf("-------------------------------------------------------------------------\n");

}
