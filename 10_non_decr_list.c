#include <stdio.h>
int main()
{
   int n,i,x,max;
   i=1;
   (void)scanf("%d", &n);
   while (i <=n)
    {
     (void)scanf("%d", &x);  
      max=0;
      if(x>max)
        {
           printf("1");
           x=max;
         } 
         else{
           printf("0");}
      i++; 
    }
   return 0;
}
