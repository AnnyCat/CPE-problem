#include<iostream>
#include<vector>
#include<algorithm>//lower_bound
using namespace std;

int LIS(int input [],int n){
    vector<int> LIS_seq; //the sequence is not the LIS, but length is equal to LIS
    LIS_seq.push_back(input[n]);
    for(int i=1;i<n;i++){
        int num = input[i];
        if(num>LIS_seq.back()){
            LIS_seq.push_back(num);
        }else{
            *(lower_bound(LIS_seq.begin(),LIS_seq.end(),num)) = num;
        }
    }
    return LIS_seq.size();

}

int main(){
    int Max=0;
    int n;
    cin>>n;
    int input[n];
    int length[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    for(int i=0;i<n;i++){
        length[i]=1; //initial: self is the LCS of length equal to 1
        for(int j=i-1;j>=0;j--){
            if(input[i]>input[j]){ // check whether jth number can extend behind ith number
                length[i] = max(length[i],length[j]+1);
                Max = max(Max,length[i]);
            }
        }
    }
    cout<<Max<<endl;
    cout<<LIS(input,n);
    return 0;
}
