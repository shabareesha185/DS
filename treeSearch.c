#include<stdio.h>

int main(){
    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    int n = sizeof(arr)/sizeof(arr[0]);
    int mid = n/2;
    int key = 60;
    if(key == arr[mid]) printf("%d \n", mid);
    if(key<arr[mid]){
        for (int i = mid-1; i>=0; i--)
        {
            if(key == arr[i]) printf("%d \n", i);
        } 
    }
    if (key > arr[mid]){
        for (int i = mid+1; i < n; i++){
            if (key == arr[i]){
                printf("%d \n", i);
            }
        }
    }
    return 0;
}