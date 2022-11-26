#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    float index;
    float value;
    struct Node *next;
};

struct queue{
    struct Node *front, *rear;
};

struct queue* createQueue()
{
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

struct Node* newNode(float index, float value)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->index = index;
    temp->value = value;
    temp->next = NULL;
    return temp;
}

void display(struct queue* q) {
	struct Node *temp;
	if ((q->front == NULL) && (q->rear == NULL)) {
		printf("\nQueue is Empty\n");
	} else {
		printf("The queue is \n");
		temp = q->front;
		while (temp) {
			printf("%.1f,%f\n", temp->index,temp->value);
			temp = temp->next;
		}
	}
}

void write(struct queue* q) {
	struct Node *temp;
	if ((q->front == NULL) && (q->rear == NULL)) {
		printf("\nQueue is Empty\n");
	} else {
		temp = q->front;
		FILE *fpt;
		char inp[50];
    	printf("Enter the signal name: ");
    	scanf("%s",inp);
        fpt = fopen(inp, "w+");   
        while(temp){ 
            fprintf(fpt,"%.1f, %.2f \n",temp->index,temp->value);    
            temp = temp->next;  
        }  
        fclose(fpt); 
		}
	}

void scale(struct queue* q,float scale) {
	struct Node *temp;
	if ((q->front == NULL) && (q->rear == NULL)) {
		printf("\nQueue is Empty\n");
	} else {
		temp = q->front;
		while (temp) {
			float tp;
			tp=(float)temp->index;
			tp=tp/scale;
			temp->index=tp;
			temp = temp->next;
		}
	}
}

void shift(struct queue* q,float shift) {
	struct Node *temp;
	if ((q->front == NULL) && (q->rear == NULL)) {
		printf("\nQueue is Empty\n");
	} else {
		temp = q->front;
		while (temp) {
			float tp;
			tp = (float)temp->index;
			tp=tp-shift;
			temp->index = tp;
			temp = temp->next;
		}
	}
}

void enQueue(struct queue* q, int index,float value)
{
    struct Node* temp = newNode(index,value);

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

struct Node* deQueue(struct queue* q)
{
    if (q->front == NULL)
        return NULL;
    struct Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    return temp;
}

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
	
	struct queue *input = createQueue();
	
	int c=0;
	float value,indx;
	while(fgets(str,50,fp)!=NULL){
		tok = strtok(str,",");
		int o=0;
		while(tok!=NULL){
			if(o%2==0)
			indx=atof(tok);
			if(o%2==1)
			value=atof(tok);
			o++;
			tok=strtok(NULL,",");
		}
		c++;
		enQueue(input,indx,value);
	}
    fclose(fp);
    float scle, shft;
    printf("Enter the scaling factor: ");
    scanf("%f",&scle);
    printf("Enter the shifting factor: ");
    scanf("%f",&shft);
    display(input);
    scale(input, scle);
	shift(input, shft);
	display(input);
	write(input);
    return 0;
}
