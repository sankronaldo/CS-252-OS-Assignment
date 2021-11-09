#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>


//function to check if the given file exists or not

bool FileExists(char *fileName) {

    FILE *filePtr = fopen(fileName, "r");

    if (!filePtr) {
        return false;
    }

    return true;
}


//function to Copy content for input file to output file

void Copy(char *out, char *in) {

    // int c to store one char at a time
    int c;
    
    // input file is opened in read mode "r"
    FILE *inPtr = fopen(in, "r");
    
    // output file is opened in write mode "w"
    FILE *outPtr = fopen(out, "w");
    
   // check if inPtr is null
    if (!inPtr) {
        perror("Source file can't be opened: ");
        exit(1);
    }

    //check if outPtr is null
    if (!outPtr) {
        perror("Destination file can't be opened: ");
        exit(1);
    }
    
    // Copy file one char at a time and terminate loop when c reaches end of file (EOF)
    while ((c = fgetc(inPtr)) != EOF) {
        fputc(c, outPtr);
    }

    // if all the above lines get executed, then the program has run successfully
    printf("\nSuccess!\n");

    // close files
    fclose(inPtr);
    fclose(outPtr);
}


// function to prompt the user to give the name of the input file and output file

void PromptUser() {  
    char str[32], inStr[32], outStr[32]; 
    char *strPtr = str;
    char *inPtr = inStr;
    char *outPtr = outStr;

    // get name of source file and check whether it exists
    while (strcmp(inStr, "")) { 
        printf("Enter name of source file: ");
        scanf("%s", strPtr);
        
        if (FileExists(strPtr)) {
            strcpy(inStr, str);
            break;
        }
        else {
            printf("File does not exist. File can't be opened!\n");
            continue;
        }
    }

    // get name of destination file and check if it already exists
    while (strcmp(outStr, "")) {
        printf("Enter name of destination file: ");
        scanf("%s", strPtr);
        
        if (!FileExists(strPtr)) {
            strcpy(outStr, str);
            break;
        }
        else {
            printf("File already exists! Please enter a different namme.\n");
            continue;
        }
    }
    
    //Calling the Copy function to Copy contents from inStr to outStr

    Copy(outStr, inStr);
}

int main() {
    PromptUser();
    
    return EXIT_SUCCESS; 
}
