#include <stdio.h>
 
int main()
{
  int frow, fcolumn, srow, scolumn, c, d, k, mul = 0,sum=0,i,j;
  int first[10][10], second[10][10], multiply[10][10],add[10][10];
 
  printf("Enter number of rows and columns of first matrix\n");
  scanf("%d%d", &frow, &fcolumn);
  printf("Enter elements of first matrix\n");
 
  for (c = 0; c < frow; c++)
    for (d = 0; d < fcolumn; d++)
      scanf("%d", &first[c][d]);
 
  printf("Enter number of rows and columns of second matrix\n");
  scanf("%d%d", &srow, &scolumn);
 
  //if (fcolumn != srow)
    //printf("The matrices can't be multiplied with each other.\n");
  //else
  //{
    printf("Enter elements of second matrix\n");
 
    for (c = 0; c < srow; c++)
      for (d = 0; d < scolumn; d++)
        scanf("%d", &second[c][d]);
 
    for (c = 0; c < frow; c++) {
      for (d = 0; d < scolumn; d++) {
        for (k = 0; k < srow; k++) {
          mul = mul + first[c][k]*second[k][d];
        }
 
        multiply[c][d] = mul;
        mul = 0;
      }
    }
    for(c=0;c<frow;c++)
    {
    	for(d=0;d<srow;d++)
    	{
    		sum= sum+(first[c][d]+second[c][d]);
		
		add[c][d]=sum;
		sum=0;
	}	
	}
	printf("sum of  matrices :\n");
	for(i=0;i<frow;i++)
	{
		for(j=0;j<scolumn;j++)
		{
			printf("%d\t",add[i][j]);
			
		}
		printf("\n");
	}
 
    printf("Product of the matrices:\n");
 
    for (c = 0; c < frow; c++) {
      for (d = 0; d < scolumn; d++)
        printf("%d\t", multiply[c][d]);

      printf("\n");
    }
  //}
  return 0;
}

