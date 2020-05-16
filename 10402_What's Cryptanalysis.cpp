#include<iostream>
#include<string>
using namespace std;
int main(){
    int letter[26] = {0};
    int Count=0;
    int n;
    cin>>n;
    string input;
    input="\n"; // Important: Clear input stream
    getline(cin,input); // Important: Clear input stream
    while(n--){
        getline(cin,input);
        for(int i=0;i<input.size();i++){
            if(input[i]>='a' && input[i]<='z'){
                letter[input[i]-'a']++;
                Count++;
            }

            if(input[i]>='A' && input[i]<='Z'){
                letter[input[i]-'A']++;
                Count++;
            }

        }
    }
    for(int j=Count;j>=1;j--){
        for(int i=0;i<26;i++){
            if(letter[i]==j)
                cout<<char('A'+i)<<" "<<j<<"\n";
        }
    }


    return 0;
}
