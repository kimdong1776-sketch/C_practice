/******************************************************
 *	- File:	hw9.c
 *	- ID:	2025003170
 *	- Name:	김  동후
 ******************************************************/

#include <stdio.h>
#include <string.h>
#define	MAX_LEN	20	

typedef	struct		
{	
    char name[MAX_LEN];	
    char position[MAX_LEN];	
    int salary;
    int year;
    }EMPLOYEE;	

void print_title(void){
    printf("------------------------------------------------------------\n");	
    printf("%4s	%20s %18s %8s %5s \n", "NO.", "NAME", "POSITION", "SALARY", "YEAR");	
    printf("------------------------------------------------------------\n");
}

void Display_all_employees_information(EMPLOYEE *e, int people){
    print_title();
    for(int i = 0;i<people;i++){
        printf("[ %d]%24s %18s %8d %5d\n", i+1, e[i].name, e[i].position, e[i].salary, e[i].year);  
    }
}   

void Search_employees_name(EMPLOYEE *e, int people){
    char sname[MAX_LEN] = {0};
    int swich = 0;
    printf("Type a name for search: ");
    fgets(sname, MAX_LEN, stdin);
    sname[strlen(sname)-1] = '\0';
    print_title();
    for(int i = 0;i<people;i++){
        if(strstr(e[i].name ,sname)!=NULL){
            swich = 1;
            printf("[ %d]%24s %18s %8d %5d\n", i+1, e[i].name, e[i].position, e[i].salary, e[i].year);
        }
    }

    if(swich == 0){
        printf("No search result: %s\n", sname);
    }
}

void Modify_one_employee_information(EMPLOYEE *e,int people){
    char sname[MAX_LEN] = {0};
    int swich = 0;
    printf("Type a name for search: ");
    fgets(sname, MAX_LEN, stdin);
    sname[strlen(sname)-1] = '\0';

    for(int i = 0;i<people;i++){
        if(strcmp(e[i].name ,sname)==0){
            swich = 1;
            printf("Enter New Position: ");
            fgets(e[i].position, MAX_LEN, stdin);
            e[i].position[strlen(e[i].position)-1] = '\0';
            printf("Enter New Salary: ");
            scanf("%d", &e[i].salary);
            printf("[ %d]%24s %18s %8d %5d\n", i+1, e[i].name, e[i].position, e[i].salary, e[i].year);
            break;
        }
    }
    if(swich == 0){
        printf("No search result: %s\n", sname);
    }
}


int main(){
    EMPLOYEE employee[]	=	{	
        {"John Smith", "Senior Engineer", 450, 2020},	
        {"Kim Young", "Junior Engineer", 380, 2025},	
        {"Lisa Barnes", "Team Leader", 670, 2008},	
        {"Michale Smith", "Project Manager", 700, 2005},	
        {"Mary Anne", "Chief Engineer", 600, 2012}
    };
    int people = sizeof(employee)/ sizeof(employee[0]);
    int choice;

    do{
        printf("=========================================\n");
        printf("Employee Management System\n");
        printf("=========================================\n");
        printf("1. Display all employees\n");
        printf("2. Search employees' name\n");
        printf("3. Modify one employee's information\n");
        printf("4. Exit program\n");
        printf("=========================================\n");
        printf("-> ");
        scanf("%d",&choice);
        getchar();
        if(choice > 4 || choice < 1){
            printf("Incorrect menu number. Type agin!\n");
            continue;
        }
        else if(choice == 1){
            Display_all_employees_information(employee, people);
        }
        else if(choice == 2){
            Search_employees_name(employee, people);
        }
        else if(choice == 3){
            Modify_one_employee_information(employee, people);
        }
    }while(choice != 4);
    printf("Bye!");
    
    return 0;
}
