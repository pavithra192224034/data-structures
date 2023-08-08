#include<stdio.h>
int Fibonacci(int n){
   if(n==0)
      return 0;
   else if(n==1)
      return 1;
   else
      return (Fibonacci(n-1)+Fibonacci(n-2) );
} 
int main(){
   int n,i=0;
   printf("Enter the number of terms in the series : ");
   scanf("%d",&n); 
   printf("Fibonacci series\n"); 
   for (int c=1;c<=n;c++){
      printf("%d\n", Fibonacci(i));
      i++; 
   }
   return 0;
}
