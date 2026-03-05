/******************************************************
*	- File:	hw02_01.c
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/

#include<stdio.h>

int main() {
    int income;
    double tax_rate, income_tax;

    printf("Input income >> ");
    scanf("%d", &income);
    
    if (income <= 12000000) {
        tax_rate = 0.06;
    } else if (income <= 46000000) {
        tax_rate = 0.15;
    } else if (income <= 88000000) {
        tax_rate = 0.24;
    } else if (income <= 150000000) {
        tax_rate = 0.35;
    } else if (income <= 300000000) {
        tax_rate = 0.38;
    } else {
        tax_rate = 0.40;
    }

    income_tax = income * tax_rate;

    printf("Income: %d, tax rate: %.2f, income tax: %.2f\n", income, tax_rate, income_tax);

    return 0;
}