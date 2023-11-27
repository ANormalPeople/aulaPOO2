#include "h.myString.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>

char *mystrcpy(char *s1, const char *s2){
    int i;
    
    for ( i = 0;*(s2+i)!= '\0'; i++ ) {
        *(s1+i)=*(s2+i);
    }
    
    s1[i]='\0';
    printf(s1);
    printf("\n");    
    return 0;
}

char *mystrncpy(char *s1, const char *s2, size_t n){
    int i;

    for (i=0;i!=n;i++) {
        *(s1+i)=*(s2+i);
    }

    s1[n]='\0';
    printf(s1);   
    printf("\n");       
    return 0;
        
}

char *mystrcat(char *s1, const char *s2){

   printf("%s %s",s1,s2);
   printf("\n");   
   return 0;
}

char *mystrncat(char *s1, const char *s2, size_t n){

	int i=0,c=0;

	while( s1[i] != '\0' && c<n){
		printf( "%c", s1[i] );
		i++;
        c++;
	}

    i=0;
    printf(" ");
  
	while( s2[i] != '\0' && c<n ){
		printf( "%c", s2[i] );
		i++;
        c++;
	}

    return 0;
}

int *mystrcmp(char *s1, const char *s2){
	
 int x=0;


    while( ( *s1 != '\0' && *s2 != '\0' ) && *s1 == *s2 ){
        s1++;
        s2++;
    }
  
    x = (*s1 ==*s2)?0:(*s1 >*s2)?1:-1;
    printf("\n%d",x);
    return 0;
    
}


int *mystrncmp(char *s1, const char *s2, size_t n){

    int i;
	
 for(i=0; i<n; i++){
        if(s1[i] == s2[i]){
            if(i==(n-1))
                return 0;
        }
        int a1 = (int) s1[i];
        int a2 = (int) s2[i];
        if(a1>a2)
            return 1;
        if(a2>a1)
            return -1;
    } 
    return 0;   
}






