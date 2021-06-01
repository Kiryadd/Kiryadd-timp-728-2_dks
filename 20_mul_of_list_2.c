#include <stdio.h>
int main()
{
   int n,i,x;
   double p=1;
   i=1;
   (void)scanf("%d", &n);
   while (i <=n)
    {
      (void)scanf("%d", &x);  
      p =p*x;
      i++; 
    }
   printf("%lf\n", p);
   return 0;
}
