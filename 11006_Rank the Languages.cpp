#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int main(){

    int n,world_num=1;
    cin>>n;
    while(n--){
        int H,W;
        cin>>H>>W;
        int total=0;
        int record[26]={0};//a-z
        char matrix[H][W];
        int Color[H*W];
        memset(Color,0,H*W*sizeof(int));
        int Distance[H*W];
        memset(Distance,0,H*W*sizeof(int));
        vector <int> AdjList [H*W];//store index
        queue <int> Queue;
        for(int i=0;i<H;i++)
            for(int j=0;j<W;j++)
                cin>>matrix[i][j];
        // Create Adjacency List
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(i!=0){//not at top side
                    if(matrix[i][j]==matrix[i-1][j])
                        AdjList[i*W+j].push_back((i-1)*W+j);
                }
                if(j!=0){//not at left side
                    if(matrix[i][j]==matrix[i][j-1])
                        AdjList[i*W+j].push_back(i*W+j-1);
                }
                if(i!=(H-1)){//not at bottom side
                    if(matrix[i][j]==matrix[i+1][j])
                        AdjList[i*W+j].push_back((i+1)*W+j);
                }
                if(j!=(W-1)){//not at right side
                    if(matrix[i][j]==matrix[i][j+1])
                        AdjList[i*W+j].push_back(i*W+j+1);
                }

            }
        }
        //BFS
        int i=0;//start
        for(int j=0;j<H*W;j++){
            if(Color[i]==0){//start point
                Color[i] = 1;
                Distance[i]=0;
                Queue.push(i);
                total++;
                while(!Queue.empty()){
                    int f = Queue.front();
                    for(unsigned int k=0;k<AdjList[f].size();k++){//k=f's neighbor
                        if(Color[AdjList[f].at(k)]==0){
                            Queue.push(AdjList[f].at(k));
                            Color[AdjList[f].at(k)]=1;
                            Distance[AdjList[f].at(k)] = Distance[f] + 1;
                        }
                    }
                    Queue.pop();
                }
            }
            i=j;
        }
        for(int j=0;j<H*W;j++){
            if(Distance[j]==0){
                int index = matrix[j/W][j%W]-'a';
                record[index]++;
            }
        }

        cout<<"World #"<<world_num++<<endl;
        for(int i=total;i>=1;i--){
            for(int j=0;j<26;j++){
                if(record[j]==i)
                    cout<<char(j+'a')<<": "<<i<<endl;
            }
        }


    }



    return 0;
}


