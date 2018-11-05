#include<stdio.h>
int main(){
   /* 2D array declaration*/
   int disp[4][5];
   /*Counter variables for the loop*/
   int i, j;
   for(i=0; i<4; i++) {
      for(j=0;j<5;j++) {
         printf("Enter value for disp[%d][%d]:", i, j);
         scanf("%d", &disp[i][j]);
      }
   }
   //Displaying array elements
   printf("Two Dimensional array elements:\n");
   for(i=0; i<4; i++) {
      for(j=0;j<5;j++) {
         printf("%d ", disp[i][j]);
         if(j==4){
            printf("\n");
         }
      }
   }
   return 0;
}
