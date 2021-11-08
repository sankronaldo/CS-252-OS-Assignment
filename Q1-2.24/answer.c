#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>


//function to check if the given file exists or not

bool file_exists(char *file_name) {

    FILE *file_ptr = fopen(file_name, "r");

    if (!file_ptr) {
        return false;
    }

    return true;
}


//function to copy content for input file to output file

void copy(char *out, char *in) {

    // int c to store one char at a time
    int c;
    
    // input file is opened in read mode "r"
    FILE *in_ptr = fopen(in, "r");
    
    // output file is opened in write mode "w"
    FILE *out_ptr = fopen(out, "w");
    
   // check if in_ptr is null
    if (!in_ptr) {
        perror("Source file can't be opened: ");
        exit(1);
    }

    //check if out_ptr is null
    if (!out_ptr) {
        perror("Destination file can't be opened: ");
        exit(1);
    }
    
    // copy file one char at a time and terminate loop when c reaches end of file (EOF)
    while ((c = fgetc(in_ptr)) != EOF) {
        fputc(c, out_ptr);
    }

    // if all the above lines get executed, then the program has run successfully
    printf("\nSuccess!\n");

    // close files
    fclose(in_ptr);
    fclose(out_ptr);
}


// function to prompt the user to give the name of the input file and output file

void prompt_user() {  
    char str[32], in_str[32], out_str[32]; // 32 char width is fine 
    char *str_ptr = str;
    char *in_ptr = in_str;
    char *out_ptr = out_str;

    // get name of source file and check whether it exists
    while (strcmp(in_str, "")) { 
        printf("Enter name of source file: ");
        scanf("%s", str_ptr);
        
        if (file_exists(str_ptr)) {
            strcpy(in_str, str);
            break;
        }
        else {
            printf("File does not exist. File can't be opened!\n");
            continue;
        }
    }

    // get name of destination file and check if it already exists
    while (strcmp(out_str, "")) {
        printf("Enter name of destination file: ");
        scanf("%s", str_ptr);
        
        if (!file_exists(str_ptr)) {
            strcpy(out_str, str);
            break;
        }
        else {
            printf("File already exists! Please enter a different namme.\n");
            continue;
        }
    }
    
    //Calling the copy function to copy contents from in_str to out_str

    copy(out_str, in_str);
}

int main() {
    prompt_user();
    
    return EXIT_SUCCESS; 
}
