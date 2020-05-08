#include<iostream>
using namespace std;
long long Fac(long long n){
    if(n==0)return 1;
    else{
        long long previous = Fac(n-1);
        if(previous>6227020800)return 6227020801;
        else return n*previous;
    }

}

int main(){

    long long n;
    while(cin>>n){
        if(n<0){
            if(n%2==0)//even
                cout<<"Underflow!\n";
            else
                cout<<"Overflow!\n";
        }else{
            long long result = Fac(n);
            if(result<10000)
                cout<<"Underflow!\n";
            else if(result>6227020800)
                cout<<"Overflow!\n";
            else
                cout<<result<<"\n";

        }


    }




    return 0;
}
