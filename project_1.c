#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int input_x, input_y, n, t, i, flag;
char mag_1 [100];
long int e[50], d[50], temp[50], j, m[50], en[50];
int prime(long int);
void encryption_key();
long int cd(long int);
void encrypt();
void decrypt();

int main(){
    printf("\n- ENTER the first Prime number:");
    scanf("%d",&input_x);
    flag =prime(input_x);
    if(flag==0){
        printf("\n----Wrong Input----\n");
        exit(0);
    }
    printf("\n- Enter second Prime Number:");
    scanf("")
}