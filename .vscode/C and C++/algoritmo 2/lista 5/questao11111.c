
    for(z=0;z<=50;z++){
        if(n2==0){
            printf("complexo\n");
        }
        printf("%2.f %2.f\n",n4[z],n5[z]);
    }



    
        raizes(n1,n2,n3,&n4[z],&n5[z]);
        
void raizes(float a, float b, float c, float *x1, float *x2){    
    int delta;

    delta = pow(b,2)-4*a*c;
    
    
    if(a!=0){
        if(delta>=0){
            x1 = (-b+sqrt(delta))/(2*a);
            x2 = (-b-sqrt(delta))/(2*a);
        }
       if(delta==0){
           return 0;
       }                  
   
    }
    if(a==0){
        if(b!=0){
            x1=-c/b;
            printf("%f",*x1);
            return 0;
        }else{
            return 0;
        }
    }

}