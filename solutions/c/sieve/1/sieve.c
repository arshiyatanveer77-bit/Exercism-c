#include "sieve.h"
#include <stdbool.h>
uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes){
   bool is_prime[limit+1];
    if (max_primes == 0) {
    return 0;
}
    is_prime[0]=false;
     is_prime[1]=false;
    for(uint32_t i=2;i<=limit;i++){
        is_prime[i]=true;
    }
    for(uint32_t i=2;i * i<=limit;i++){
        if(is_prime[i]){
            for(uint32_t j=i*i;j<=limit;j=j+i){
            is_prime[j]=false;
            }
        }
    }
   uint32_t count=0;
    for(uint32_t i=0;i<=limit;i++){
        if(is_prime[i]){
            primes[count]=i;
             count++;
        }
      
        if(count == max_primes){
            break;
        }
}
    return count;
}
