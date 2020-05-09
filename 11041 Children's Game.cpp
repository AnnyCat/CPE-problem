#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(string a,string b){
    return a+b>b+a;//排序大到小
}


int main(){
    int n;
    while(cin>>n){
        if(n==0) break;
        vector<string> str_array;
        string tmp_str;
        while(n--){
            cin>>tmp_str;
            str_array.push_back(tmp_str);
        }
        sort(str_array.begin(),str_array.end(),compare);
        for(int i=0;i<str_array.size();i++)
            cout<<str_array.at(i);
        cout<<"\n";
    }

    return 0;
}
