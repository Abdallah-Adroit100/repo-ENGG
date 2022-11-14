#include<stdio.h>
#include <stdlib.h>

// here where the encryption code starts:-
void encryption(){
    char inputFile[20],outputFile[20],ch;
     int  numAscii;
     FILE *fd1,*fd2; //fd means file descriptor


     printf("\n- Enter name of the file:");
     scanf("%s",inputFile);
     printf("\n- Enter the name of the output file:");
     scanf("%s",outputFile);

     fd1=fopen(inputFile,"r"); //"r" Opens a file for reading. The file must exist.

     if (fd1==NULL){
          printf("\nInput file does not exist...");
          exit(0);

     }else{

          fd2=fopen(outputFile,"w"); // "w" means Creates an empty file for writing. If a file with the same name already exists, its content is erased and the file is considered as a new empty file.
          ch=fgetc(fd1);

          while (ch!=EOF){ // EOF means The END of the FILE, After we enter the text, if we press ctrl+Z, the text terminates i.e. it indicates the file reached end nothing to read.
               numAscii=(int)ch;
               numAscii=numAscii+5;
               fprintf(fd2,"%c",numAscii); // fprintf means format print function.
               ch=fgetc(fd1);
               
          }
          fclose(fd2);

     }
     fclose(fd1);
     printf("\nFile is now Encrypted with name %s.",outputFile);
     return 0;
}

// here is the decryption code starts:-

void decryption(){
    char inputFile[20],outputFile[20],ch;
     int  numAscii;
     FILE *fd1,*fd2; //fd means file descriptor


     printf("\n- Enter name of the file:");
     scanf("%s",inputFile);
     printf("\n- Enter the name of the output file:");
     scanf("%s",outputFile);

     fd1=fopen(inputFile,"r"); //"r" Opens a file for reading. The file must exist.

     if (fd1==NULL){
          printf("\nInput file does not exist...");
          exit(0);

     }else{

          fd2=fopen(outputFile,"w"); // "w" means Creates an empty file for writing. If a file with the same name already exists, its content is erased and the file is considered as a new empty file.
          ch=fgetc(fd1);

          while (ch!=EOF){ // EOF means The END of the FILE, After we enter the text, if we press ctrl+Z, the text terminates i.e. it indicates the file reached end nothing to read.
               numAscii=(int)ch;
               numAscii=numAscii-5;
               fprintf(fd2,"%c",numAscii); // fprintf means format print function.
               ch=fgetc(fd1);
               
          }
          fclose(fd2);

     }
     fclose(fd1);
     printf("\nFile is now Encrypted with name %s.",outputFile);
     return 0;
}

// here where the code runs:-
int main(){
     printf("\n---Welcome to the Encryption/Decryption program---\n");
     int n;
    while (1)
    {
        printf("\n\n----------------\n"
               "1: Encryption\n"
               "2: Decryption\n"
               "3: Exit\n"
               "----------------\n");
        printf("Enter your choice: ");

        scanf("%d", &n);
        if (n == 1)
            encryption();
        else if (n == 2)
            decryption();
        else
            exit(0);
    }
   
}    
// to creat a txt file or any file, enter in the terminal: code "name of the file.type of the file"