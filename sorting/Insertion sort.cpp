#include<bits/stdc++.h>
using namespace std;
int* insertionsort(int *arr,int len)      // here the think is if we pass an array to a user define fuction 
{                                         // after that if we want to calcualte the length of that array 
                                          // we literally can't do that because when we pass the array the user define 
   int i,j,temp;                          // function catchs the array name to a pointer even if we initilize the 
                                          // peratmeter as "int arr[]" it is also work as pointer for this reason we can't calculate the length
   for(i= 1;i<len;i++)                    // of the array by sizeof() function we to calculate that where the array is delcared 
   {                                      // like in th main() function. And pass the length the of that array like "int len" as perameter 
       j = i-1;
       temp = arr[i];
       while(temp<arr[j] && j>=0)                                       
       /* if j<0 then some garbage data will cheack with from the negetive index 
       by this that garbage value will also cout as array data that's why j>=0 
       is given in the conditon*/
       {
           arr[j+1]= arr[j];
           j--;

       }
       arr[j+1]= temp;

   }
   return arr;
}

int main()
{
    int arr[]= {8,4,2,1,6,1,7,0,19,20},*p;
  
    int len = sizeof(arr)/sizeof(arr[0]);
  p = insertionsort(arr,len);

    for(int i =0 ;i<len;i++)
    {
        cout << p[i]<< "   "<< i  << endl;
    }
}