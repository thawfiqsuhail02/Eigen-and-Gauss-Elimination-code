#include<stdio.h>
#include<conio.h>
#include<math.h>

#define SIZE 10

int main()
{
		 float a[SIZE][SIZE], x[SIZE], ratio;
		 int i,j,k,l;
		 /* Inputs */
		 /* 1. Reading number of unknowns */
		 printf("Enter number of unknowns: ");
		 scanf("%d", &l);
		 /* 2. Reading Augmented Matrix */
		 printf("Enter coefficients of Augmented Matrix:\n");
		 for(i=1;i<=l;i++)
		 {
			  for(j=1;j<=l+1;j++)
			  {
				   printf("a[%d][%d] = ",i,j);
				   scanf("%f", &a[i][j]);
			  }
		 }
		 /* Applying Gauss Jordan Elimination */
		 for(i=1;i<=l;i++)
		 {
			  if(a[i][i] == 0.0)
			  {
				   printf("Mathematical Error!");
				   return 0;
			  }
			  for(j=1;j<=l;j++)
			  {
				   if(i!=j)
				   {
					    ratio = a[j][i]/a[i][i];
					    for(k=1;k<=l+1;k++)
					    {
					     	a[j][k] = a[j][k] - ratio*a[i][k];
					    }
				   }
			  }
		 }
		 /* Obtaining Solution */
		 for(i=1;i<=l;i++)
		 {
		  	x[i] = a[i][l+1]/a[i][i];
		 }
		 /* Displaying Solution */
		 printf("\nSolution:\n");
		 for(i=1;i<=l;i++)
		 {
		  	printf("x[%d] = %0.3f\n",i, x[i]);
		 }
		 getch();
		 return(0);
}
