#include<stdio.h>

int main(){
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    int id = 5;
    int left = 0, right = 9-1;
    while (left <= right)   
    {
        int mid = left+(right-left)/2;
        if(arr[mid] == id) {
            printf("%d",mid);
            return 0;
        }
        if (id > arr[mid])
        {
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    
}