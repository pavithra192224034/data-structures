#include<stdio.h>
int main(){
	int i,f=1, num;
	printf("Enter a number: ");
	scanf("%d", &num);
	if((num==1)||(num==0)){
  		f=1;
  }
	else{
		for(i=1;i<=num;i++){
    		f = f * i; 
    	}
  		printf("%d! = %d\n", num, f);
	}
	return 0;
}
