#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
char inputFile[100],outputFile[100],ch[127];
    int  z[255],x;
    FILE *fd1,*fd2; //fd means file descriptor
    printf("\n- Enter name of the file:");
    scanf("%s",inputFile);

   printf("- Enter 1 to Encrypt the File\n -Enter 2 to Decrypt the File: ");
   scanf("%d", &x);

    fd1=fopen(inputFile,"r"); //"r" Opens a file for reading. The file must exist.
    for(int b=0;b<strlen(inputFile) && inputFile[b]!= '.'; b++)
    {
        outputFile[b]=inputFile[b];
    }
    if (x ==1){
        strcat(outputFile,".crp");
        fd2=fopen(outputFile,"w");
        printf("%s",outputFile);
    }
    else{
        strcat(outputFile, ".txt");
        fd2 =fopen(outputFile,"w");
        printf("%s",outputFile);
    }

    if (fd1==NULL){
        printf("\nInput file does not exist...(run the code again)");
        exit(0);   
    }else{
        while (fgets(ch,sizeof(ch),fd1) !=NULL)
        switch(x)
        {
        case 1:
            fprintf(fd2,"\n");
                for (int i = 0; i < strlen(ch); i++)
                {
                    if(ch[i]==32)
                        fprintf(fd2,"80");
                    else if (ch[i]==9)
                        fprintf(fd2,"TT");
                    else if (ch[i]==3)
                        fprintf(fd2,"<CR>");
                    else if (ch[i]>32){
                        z[i]=ch[i]-16;
                        if(z[i]<32) {
                            z[i] = (z[i] -32) +144;
                        } 
                        fprintf(fd2,"%X",z[i]);
                    }
                else if(ch[i]<32&&ch[i]!=9 && ch[i] !=3){
                    z[i]=ch[i]-32+144;
                    fprintf(fd2,"%X",z[i]);
                } 
            }
         break;
         case 2:
            for(int i = 0; i < strlen(ch); i++){
                if((ch[i]==56)&& (ch[i+1]==48)){
                    fprintf(fd2," ");
                    i=i+1;
                }
                else if ((ch[i]==56)&& (ch[i+1]==55)){
                  fprintf(fd2,"'");
                }
                else if((ch[i]==50)&&(ch[i+1]==70)){
                    fprintf(fd2,"?");
                }
                else if((ch[i]==56)&&(ch[i+1]==49)){
                    fprintf(fd2,"!");
                }
                else{
                    if((i%2==0 || i==0) && i!=1)
                        {z[i]=ch[i]-48;
                        z[i]=z[i]*16;
                    }
                    else
                    {
                        if (ch[i]=='A')
                        z[i]=z[i-1]+10;
                        else if (ch[i]=='B')
                        z[i]=z[i-1]+11;
                        else if (ch[i]=='C')
                        z[i]=z[i-1]+12;
                        else if (ch[i]=='D')
                        z[i]=z[i-1]+13;
                        else if (ch[i]=='E')
                        z[i]=z[i-1]+14;
                        else if (ch[i]=='F')
                        z[i]=z[i-1]+15;

                    else{
                        z[i]=ch[i]-48;
                        z[i]=z[i-1]+z[i];
                    }
                    ch[i]=z[i]+16;


                    if(ch[i]>127)
                    {
                        ch[i]=(ch[i]-144)+32;
                        fprintf(fd2,"%c",ch[i]);
                    }
                    else
                        fprintf(fd2,"%c",ch[i]);
                    }
    
                   
                }
            }
        }
    }       
}
        
    
