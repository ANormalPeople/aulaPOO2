
#include "c.myString.c"
#include <stdio.h>
#include <stdlib.h>


int main(){


    char s1[50];
    char s2[50];
    char s3[] = "Ola";  
    char s4[] = "Bom dia"; 
    
    system("cls");


	mystrcpy(s1,s3);   
	mystrncpy(s2,s4,6);
    mystrcat(s3,s4);   
	mystrncat(s3,s4,9);
    mystrcmp(s3,s4);
    printf("\n%d",mystrncmp(s3,s4,20));
    
return 0;

}