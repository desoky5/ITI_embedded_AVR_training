#include<stdio.h>

int main()
{
 int arr[] = {3,5,2,9,7};
 int size=sizeof(arr)/sizeof (arr[0]);//get size of array

 
 for (int i =0;i<size-1;i++ )
 {
   for (int j = 0 ; j < size-1-i ; j++) // -i is for not comparing with what have been sorted previously
   {  
      int temp ; 
      if(arr[j]>arr[j+1])
      {
         temp=arr[j];
         arr[j] = arr[j+1];
         arr[j+1]= temp;
      } 
   }
 }
 printf("------------sorted-------------------");
 for (int i = 0 ; i < size ; i++)
 {
   printf("index %d is : %d \n",i,arr[i]);
 }
 
 }

    