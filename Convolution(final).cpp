#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct signl{
    float index;
    float value;
} f[100],h[100],y[100];


int main(void) {
    char inpt[50];
    FILE *fp;
    char str[50];
	char *tok;
    
    printf("Enter the signal: ");
    scanf("%s",inpt);

    fp = fopen(inpt, "r");
    if (fp == NULL) {
        printf( "Error reading file\n");
        return 1;
    }

	int c=0,m=0;
	while(fgets(str,50,fp)!=NULL){
		tok = strtok(str,",");
		int o=0;
		while(tok!=NULL){
			if(o%2==0)
			f[c].index=atof(tok);
			if(o%2==1)
			f[c].value=atof(tok);
			o++;
			tok=strtok(NULL,",");
		}
		c++;
		m++;
	}
	for(int i=0;i<c;i++)
	{
		printf("\n x[%.1f]=%.2f",f[i].index,f[i].value);
	}
    fclose(fp);

    printf("\n\n Enter the impulse response signal: ");
    scanf("%s",inpt);

    fp = fopen(inpt, "r");
    if (fp == NULL) {
        printf( "Error reading file\n");
        return 1;
    }
	
	int n=0;
	c=0;
	while(fgets(str,50,fp)!=NULL){
		tok = strtok(str,",");
		int o=0;
		while(tok!=NULL){
			if(o%2==0)
			h[c].index=atof(tok);
			if(o%2==1)
			h[c].value=atof(tok);
			o++;
			tok=strtok(NULL,",");
		}
		c++;
		n++;
	}
	for(int i=0;i<c;i++)
	{
		printf("\n h[%.1f]=%.2f",h[i].index,h[i].value);
	}
    fclose(fp);
    int i,j;
    for(i=0;i<m+n-1;i++)
	
	{          
	
	    y[i].value=0;
		for(j=0;j<=i;j++)
		{
	        y[i].value=y[i].value+(f[j].value*h[i-j].value);
		}
	}
	printf("\n\n Output signal is: \n");
	y[0].index= f[0].index;
	for(i=1;i<m+n-1;i++)
	{
		y[i].index=y[i-1].index+1;
	}
	for(i=0;i<m+n-1;i++)
	{
		printf("\n y[%.1f]=%.2f",y[i].index,y[i].value);
	}
	
	FILE *fp1;
	fp1 = fopen("con_output.csv", "w+");  
 
            for(i=0;i<m+n-1;i++)
			{ 
                fprintf(fp1,"%.1f, %.2f\n",y[i].index,y[i].value);  
            }  

            fclose(fp1);
    return 0;
}
