#include<iostream>
#include<string>
using namespace std;
int main(){

    string str1;
    string str2;
    while(cin>>str1){
        cin>>str2;
        int start=0;
        bool allinall=1;
        for(int i=0;i<str1.size();i++){
            for(int j=start;j<str2.size();j++){
                if(str1[i]==str2[j]){
                    start = j+1;
                    break;
                }
                if(j==str2.size()-1)
                    allinall=0;
            }
            if(!allinall)break;
        }
        if(allinall)
            cout<<"Yes\n";
        else
            cout<<"No\n";

    }


    return 0;

}
