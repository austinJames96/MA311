
/* C++ program to find a prime factor of composite using 
   Pollard's Rho algorithm */
#include<bits/stdc++.h> 
using namespace std; 

long long int modular_pow(long long int base, int exponent, 
                          long long int modulus) 
{ 
    long long int result = 1; 
  
    while (exponent > 0) 
    { 
        if (exponent & 1){
            result = (result * base) % modulus; 
        }
  
        exponent = exponent >> 1; 
  
        base = (base * base) % modulus; 
    } 
    return result; 
} 

long long int PollardRho(long long int n) 
{ 
    srand (time(NULL)); 
  
    if (n==1) return n; 
  
    if (n % 2 == 0){
         return 2;
    } 
  
    long long int x = (rand()%(n-2))+2; 
    long long int y = x; 
    long long int c = (rand()%(n-1))+1; 
    long long int d = 1;   
  
    while (d==1) 
    { 
        x = (modular_pow(x, 2, n) + c + n)%n; 
        y = (modular_pow(y, 2, n) + c + n)%n; 
        y = (modular_pow(y, 2, n) + c + n)%n; 

        d = __gcd(abs(x-y), n); 
          
        if (d==n){
             return PollardRho(n); 
        }
    } 
  
    return d; 
} 
  
/* driver function */
int main() 
{ 
    unsigned long long int n[4] = {19238291,184865893,187189186201,15466048015829};
/*
    for(int i = 0; i<sizeof(n); i++){
        if(n[i]==n[0]||n[1]||n[2]||n[3]){
        printf("A divisors for %lld is %lld.\n", n[i], PollardRho(n[i]));
        }
    }*/
    printf("A divisor for %lld is %lld.\n", n[0], PollardRho(n[0]));
    printf("A divisor for %lld is %lld.\n", n[1], PollardRho(n[1]));
    printf("A divisor for %lld is %lld.\n", n[2], PollardRho(n[2]));
    printf("A divisor for %lld is %lld.\n", n[3], PollardRho(n[3]));
    
    return 0;
} 