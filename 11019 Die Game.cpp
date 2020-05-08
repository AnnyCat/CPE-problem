#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main(){
    int num;
    while(cin>>num){
        if(num==0)break;
        int face[] = {1,2,3};//top,north,west
        char action[6];
        for(int i=0;i<num;i++){
            cin>>action;
            if(strcmp(action,"north")==0){

                int top=face[0];
                face[0]=7-face[1];//south
                face[1]=top;//top


            }
            else if(strcmp(action,"east")==0){

                int bottom=7-face[0];
                face[0]=face[2];
                face[2]=bottom;
            }
            else if(strcmp(action,"south")==0){
                int bottom=7-face[0];
                face[0]=face[1];//north
                face[1]=bottom;
            }
            else if(strcmp(action,"west")==0){
                int top=face[0];
                face[0]=7-face[2];//east
                face[2]=top;
            }
        }
        cout<<face[0]<<"\n";
    }


    return 0;
}
