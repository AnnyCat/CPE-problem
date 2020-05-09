#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
bool sieve[1000001];//default is false
void CreatePrimeTable(){
    sieve[0]=true;
    sieve[1]=true;
    for(int i=2;i<=sqrt(1000000);i++){
        if(!sieve[i]){//prime
            for(int j=i*i;j<=1000000;j+=i)
                sieve[j]=true;
        }
    }
}
int DigitSum(int n){
    int Sum=0;
    while(n){
        Sum+=n%10;
        n/=10;
    }
    return Sum;
}

int main(){
    CreatePrimeTable();
    int n;
    cin>>n;
    while(n--){
        int n1,n2,Count=0;
        cin>>n1>>n2;
        for(int i=n1;i<=n2;i++){
            if(!sieve[i] && !sieve[DigitSum(i)])
                Count++;
        }
        cout<<Count<<"\n";


    }
    return 0;
}
