#include <stdio.h>
#include <stdlib.h>

int main() {
	double myValue,myArray[10];
	int choice,index;
	do{
		printf("Make a choice(-1 to Exit)\n");
		printf("\t1,write to array\n");
		printf("\t2,read from array\n");
		scanf("%d",&choice);
		if(choice==-1) break;
		if(choice!=1 && choice!=2){
			printf("Are you kidding me?");
			continue;
		}
		printf("Enter array index:");
		scanf("%d",&index);
		if(index<0 || index>9){
			printf("index should be in the range of 0-9");
			continue;
		}
		switch(choice){
			case 1: printf("\n Enter the value:");
			scanf("%lf",&myValue);
			myArray[index]=myValue;
			printf("The write operation is succesful\n\n");
			break;
			case 2: printf("myArray[%d]:%.2f\n\n",index,myArray[index]);
			break;
		}
	}while(choice!=-1);
	return 0;
}
