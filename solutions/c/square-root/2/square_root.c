#include "square_root.h"

int square_root(int target)
{
    int low=1;
    int high=target;
    int mid;
    while(low<=high){
         mid=(low+high)/2;
    if(mid*mid==target){return mid;}
        else if(mid*mid<target){
            low=mid+1;
        }
        else if(mid*mid>target){high=mid-1;}
    }


    return -1;
}