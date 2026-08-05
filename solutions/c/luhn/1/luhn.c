#include "luhn.h"
#include<string.h>
bool luhn(const char *num){
    int len=strlen(num);
    int digit_count=0;
    for(int i=0;i<len;i++){
        if(num[i]>= '0' && num[i]<='9'){
            digit_count++;
        }
        else if(num[i] !=' '){
            return false;
        }
                           }
if(digit_count<2){return false;}
    int digit_position=0;
    int sum=0;
    for(int i=0;i<len;i++){
        if(num[i]==' '){continue;}
        int digit=num[i]-'0';
        digit_position++;
        if((digit_count %2==0 && digit_position %2==1 )|| (digit_count %2 != 0 && digit_position %2 ==0)){
            digit *=2;
            if(digit>9){digit-=9;}
        }
        sum +=digit;
    }


    if(sum%10==0){return true;}
    return false;

}