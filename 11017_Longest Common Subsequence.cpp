#include<iostream>
#include<string>
using namespace std;

int table[1001][1001]={0};
int main(int argc, char** argv){
    string str1;
    string str2;
    while(cin>>str1){
        cin>>str2;
        for(int i=1;i<=str1.size();i++){
            for(int j=1;j<=str2.size();j++){
                if(str1[i-1]==str2[j-1]){
                    table[i][j] = table[i-1][j-1]+1;
                }
                else{
                    table[i][j] = max(table[i-1][j],table[i][j-1]);
                }
            }
        }
        cout<<table[str1.size()][str2.size()]<<endl;
    }
    return 0;
}
