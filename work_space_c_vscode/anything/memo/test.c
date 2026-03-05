#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
// #include <windows.h> // Windows user: comment out unistd.h, uncomment this and use Sleep(ms)

#define VIEW_WIDTH 20 

void led_display_scroll(char *input_string) {
    int input_len = strlen(input_string);
    int i, offset;

    int source_len = input_len + VIEW_WIDTH;
    char *source_buffer = (char *)malloc(source_len + 1);
    if (source_buffer == NULL) return; 

    char padding[VIEW_WIDTH + 1];
    for (i = 0; i < VIEW_WIDTH; i++) {
        padding[i] = ' ';
    }
    padding[VIEW_WIDTH] = '\0';

    sprintf(source_buffer, "%s%s", input_string, padding);
    
    char view_buffer[VIEW_WIDTH + 1];
    view_buffer[VIEW_WIDTH] = '\0'; 

    system("cls"); // or "clear" for Linux/macOS

    offset = 0;
    for (i = 0; i < 100; i++) {
        
        memcpy(view_buffer, source_buffer + offset, VIEW_WIDTH);

        printf("\r%s", view_buffer); // Use \r to return to start of line (avoids gotoxy)
        fflush(stdout); 

        offset++;
        
        if (offset == input_len) {
            offset = 0;
        }
        
        usleep(1000 * 200); // 200ms
        // Sleep(200); // Windows version
    }

    free(source_buffer); 
}


int main(){
    char message[51] = {0};
    int len;

    printf("Type a message(50 chars): ");
    fgets(message, sizeof(message), stdin);

    len = strlen(message);
    if (message[len - 1] == '\n'){
            message[len - 1] = '\0';
    }

    if (strlen(message) == 0) {
        strcpy(message, "Hello World! This is a test."); // Default message
    }

    led_display_scroll(message);

    printf("\nDone.\n"); // Print newline at the end
    return 0;
}