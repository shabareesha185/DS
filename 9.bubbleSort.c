#include<stdio.h>

int main(){
    int arr[10] = {10,9,8,3,2,1,5,7,4,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d, ", arr[i]);
    }
    return 0;
}