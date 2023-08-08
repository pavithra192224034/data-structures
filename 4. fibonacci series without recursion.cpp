#include <stdio.h>
int main(){
    int i, n, firstTerm=0, secondTerm=1, sum=0;
    printf("\nEnter number of terms required in Fibonacci Series: ");
    scanf("%d",&n);
    if(n<=0){
		printf("Error!! No Elements!!");
	}
	else if(n==1){
    printf("\nFibonacci Series is:\n %d ", firstTerm);
	}
	else if (n==2){
		printf("\nFibonacci Series is:\n\n\n %d %d ", firstTerm, secondTerm);
	}
	else{	
    	i=2;
    	printf("\nFibonacci Series is:\n %d %d ", firstTerm, secondTerm);
    	while (i<n)	{	
    	    sum=firstTerm+secondTerm;
    	    firstTerm=secondTerm;
    	    secondTerm=sum;
    	    ++i;
    	    printf("%d ",sum);
    	}
	}
    return 0;
}
