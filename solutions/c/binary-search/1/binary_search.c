#include "binary_search.h"
const int *binary_search(int value, const int *arr, size_t length){
    int low,high,mid;
    low=0;
    high=length-1;
    mid=(low+high)/2;
    while(low <= high){
        if(arr[mid]==value){return &arr[mid] ;}
        else if(value<arr[mid]){
            high=mid-1;
        }
        else if(value>arr[mid]){
            low=mid+1;
        }
        mid=(low+high)/2;
        
    }
    return NULL;
}