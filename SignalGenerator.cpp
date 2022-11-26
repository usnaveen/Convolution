#include <stdio.h>  
#include <ctype.h> 
#include <math.h>  

int main(){  
    int choice=0;  
    float c,a,A,w,pi,start,end;  
    int st;  
    printf("Signal Generator:\n1. Exponential Signal\n2. Sinusoidal Signal\n3. Impulse Signal\n4. Step Signal\n5. Ramp Signal\n");  
    printf("\nChoose your signal: ");  
    scanf("%d",&choice);  
    switch (choice){  
        case 1: 
            printf("\nx[n] = c*\u03B1^n\n");  
            printf("\nc = ");  
            scanf("%f",&c);  
            printf("\n\u03B1 = ");  
            scanf("%f",&a);  
            printf("\nSampling time: ");  
            scanf("%d",&st);  
            printf("Enter the sample range: ");  
            scanf("%f",&start);  
            scanf("%f",&end);  
            FILE *fpt;  
            fpt = fopen("exponential.csv", "w+");   
            while(start<=end){ 
                fprintf(fpt,"%.1f, %.2f \n",start, c*pow(a,start));  
                printf("\n%.1f, %.2f",start, c*pow(a,start));  
                start=start+st;  
            } 
            fclose(fpt);  
            break; 
        case 2:  
            printf("\nx[n] = a*cos(\u03C9t+\u03C6)\n");  
            printf("\nA = ");  
            scanf("%f",&A);  
            printf("\n\u03C9 = ");  
            scanf("%f",&w); 
            printf("\n\u03C6 = ");  
            scanf("%f",&pi); 
            printf("\nSampling time: ");  
            scanf("%d",&st);  
            printf("Enter the sample range: ");  
            scanf("%f",&start);  
            scanf("%f",&end);  
            FILE *fpt1;  
            fpt1 = fopen("sinusoidal.csv", "w+");  
            while(start<=end){ 
                fprintf(fpt1,"%.1f, %.2f \n",start, A*sin(w*start+pi));  
                printf("\n%.1f, %.2f",start,A*sin(w*start+pi));  
                start=start+st;  
            }  
            fclose(fpt1);   
            break; 
        case 3: 
            printf("\nx[n] = a*\u03B4(n)\n");  
            printf("\nA = ");  
            scanf("%f",&A); 
            printf("\nSampling time: ");  
            scanf("%d",&st);  
            printf("Enter the sample range: ");  
            scanf("%f",&start);  
            scanf("%f",&end);  
            FILE *fpt2;  
            fpt2 = fopen("impulse.csv", "w+");   
            while(start<=end){
                if(start==0){ 
                    fprintf(fpt2,"%.1f, %.2f\n",start,A);  
                    printf("%.1f, %.2f\n",start,A); 
                } 
                else { 
                fprintf(fpt2,"%.1f, 0\n",(float)start);  
                printf("%.1f, 0\n",(float)start);  
                } 
                start=start+st; 
            }  
            fclose(fpt2);  
            break;  
        case 4:  
            printf("\nx[n] = a*u(n)\n");  
            printf("\nA = ");  
            scanf("%f",&A);  
            printf("\nSampling time: ");  
            scanf("%d",&st);  
            printf("Enter the sample range: ");  
            scanf("%f",&start);  
            scanf("%f",&end);  
            FILE *fpt3;  
            fpt3 = fopen("step.csv", "w+");   
            while(start<=end){ 
                if(start>=0){ 
                    fprintf(fpt3,"%.1f, %.2f\n",start,A);  
                    printf("%.1f, %.2f\n",start,A); 
                } 
                else { 
                fprintf(fpt3,"%.1f, 0\n",start);  
                printf("%.1f, 0\n",start);  
                } 
                start=start+st;  
            }  
            fclose(fpt3);  
            break;  
        case 5:  
            printf("\nx[n] = a*n\n");  
            printf("\nA = ");  
            scanf("%f",&A);  
            printf("\nSampling time: ");  
            scanf("%d",&st);  
            printf("Enter the sample range: ");  
            scanf("%f",&start);  
            scanf("%f",&end);  
            FILE *fpt4;  
            fpt4 = fopen("ramp.csv", "w+");  
            while(start<=end){ 
                fprintf(fpt4,"%.1f, %.2f\n",start,start*A);  
                printf("%.1f, %.2f\n",start,start*A); 
                start=start+st;  
            }  
            fclose(fpt4); 
            break;  
        default: 
            printf("Invalid input."); 
    return 0;  
    }  
} 
