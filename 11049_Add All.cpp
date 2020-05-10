#include<iostream>
#include<queue>
using namespace std;


int main(){

    int n;
    while(cin>>n){
        if(n==0)break;
        priority_queue<int,vector<int>,greater<int> > Small_queue;
        int tmp;
        for(int i=0;i<n;i++){
            cin>>tmp;
            Small_queue.push(tmp);
        }
        int Count=0,q1,q2,sum;
        for(int i=1;i<n;i++){
            q1 = Small_queue.top();
            Small_queue.pop();
            q2 = Small_queue.top();
            Small_queue.pop();
            sum = q1 + q2;
            Small_queue.push(sum);
            Count+=sum;
        }
        cout<<Count<<endl;
    }


    return 0;
}
