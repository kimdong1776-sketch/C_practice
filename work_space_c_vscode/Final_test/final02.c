/******************************************************
*	- File:	final02.c	
*	- ID:	2025003170	
*	- Name:	김  동후
******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOK 10

typedef struct {	
    char title[50];	
    char author[30];					
    int	price;	
}book;	

int book_count = 0;

void print_all_book(book *lib, int count){
    printf("Total Book count: %d\n", count);
    for(int i = 0; i < count;i++){
        printf("[%d] Title: %s,Author: %s, price : %d\n",i+1,		
                        lib[i].title,		
                        lib[i].author,	
                        lib[i].price);
    }
    printf("======================================\n");
}
void add_new_book(book *lib, int *count){
    char title[50];
    char author[30];
    if(*count == 10){
        printf("NO empty space. (%d blokc)\n", *count);
        printf("======================================\n");
        return;
    }
    printf("type a new book title(MAX: 50 chars): ");
    fgets(title, sizeof(title), stdin);
    title[strlen(title)-1] = '\0';
    strcpy(lib[*count].title, title);

    printf("type a new book author(MAX: 30 chars): ");
    fgets(author, sizeof(author), stdin);
    author[strlen(author)-1] = '\0';
    strcpy(lib[*count].author, author);

    printf("type a new book price");
    scanf("%d", &(lib[++(*count)].price));
    printf("A new book added. (book count: %d)\n", *count);
    printf("======================================\n");
}
void serach_book(book * lib){
}
void update_book(book * lib, int count){
    char title[50]= {0};
    int indext = 0;
    printf("Type a index for updatingn: ");
    scanf("%d",&indext);
    if(indext > count || indext <= 0){
        printf("OUT of index");
        return;
    }
    printf("[%d] Title: %s,Author: %s, price : %d\n",indext,		
                        lib[indext-1].title,		
                        lib[indext-1].author,	
                        lib[indext-1].price);
    printf("Enter a new title(Enter: skip):");
    
    printf("======================================\n");
}
void save_book_exit_program(book * lib, int count){
    FILE *f;
    char *fname = "book_out.txt";
    if((f = fopen(fname,"w"))==NULL){
        fprintf(stderr, "wirte err\n");
    }
    for(int i = 0; i < count; i++){
        fprintf(f,"%s,%s,%d\n", lib[i].title,lib[i].author, lib[i].price);
    }
    fclose(f);

}

void delete_space(char *src, char *dest){
    int j = 0;
    for(int i = 0 ; src[i] != 0 ; i++){
        if (src[i] != ' ' && src[i] != '\n'){
            dest[j++] = src[i];
        }
    }
    dest[j] = 0;
}

int main(){
    FILE *f;
    book booklib[MAX_BOOK] = {0};
    char *fname = "books.txt";
    char line[200];
    char dst[200];
    int choise = 0;
    int count = 0;
    memset(booklib, 0,sizeof(book));
    if((f = fopen(fname,"r"))==NULL){
        fprintf(stderr, "Read err\n");
    }

    while((fgets(dst, sizeof(dst), f)) != NULL){
        delete_space(dst, line);
        fgets(line,	sizeof(line),	fin);	
        sscanf(line,	"%[^,],%[^,],%d",		
        booklib[count].title,		
        booklib[count].author,	
        &booklib[count].price);	
        count ++;

    }
    fprintf(stdout, "read %s (8 books) successfully\n", fname);
    fclose(f);


    
    while(1){
        printf("======================================\n");
        printf("Book Management Program\n");
        printf("1. print All Books\n");
        printf("2. Add new book\n");
        printf("3. Search Book\n");
        printf("4. update book Information\n");
        printf("5.save book data and exit program\n");
        printf("======================================\n");
        printf("type anumber:");
        scanf("%d", &choise);
        getchar();
        
        if(choise == 1){
            print_all_book(booklib ,count);
        }
        else if(choise == 2){
            add_new_book(booklib, &count);
        }
        // else if(choise == 3){
        //     serach_book(booklib);
        // }
        else if(choise == 4){
            update_book(booklib, count);
        }
        else if(choise == 5){
            save_book_exit_program(booklib, count);
            return 0;
        }
        else{
            printf("err number : plz again type\n");
            continue;
        }
    }
    
    

    return 0;
}