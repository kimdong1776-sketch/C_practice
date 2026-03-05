/******************************************************
*	- File:	hw01_01.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/

#include<stdio.h>

int main(){
    int Midterm_score, Final_score;
    printf("Type midterm final score: ");
    scanf("%d %d",&Midterm_score,&Final_score);
    printf("Midterm score: %d, Final score: %d\n",Midterm_score, Final_score);
    printf("Total: %d, Average: %.1f", Midterm_score+Final_score, (Midterm_score + Final_score)/2.0);

    return 0;
}
