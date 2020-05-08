#include<iostream>
#include<vector>
using namespace std;
vector<unsigned int> table;;
unsigned int search_Fib_table(unsigned int find_value)
{
    while(table.back()<find_value){
        //create table
        table.push_back(*(table.end()-1) + *(table.end()-2));
    }
    //binary search table
    unsigned int max_index = table.size()-1;
    unsigned int min_index = 0;
    while(min_index <= max_index){
        unsigned int mid_index = (min_index+max_index)/2;
        if(find_value < table.at(mid_index)){
            max_index = mid_index-1;
        }else if(find_value > table.at(mid_index)){
            min_index = mid_index+1;
        }else{
            return mid_index;
        }
    }
    return (min_index<max_index)?min_index:max_index;
}

string Fib_base(unsigned int value){

    unsigned int index = search_Fib_table(value);
    unsigned int max_size = index+1;
    string arr="1";
    value = value-table.at(index);
    while(value!=0){
        unsigned int next_index = search_Fib_table(value);
        for(unsigned int i=0;i<index-next_index-1;i++)arr = arr + "0";
        arr = arr + "1";
        index = next_index;
        value = value-table.at(index);
    }

    if(index!=0)
        for(unsigned int i=0;i<index;i++)arr = arr + "0";


    return arr;


}




int main(){
    table.push_back(1);
    table.push_back(2);
    unsigned int num,seq;
    cin>>num;
    vector <unsigned int>sequeue;
    for(unsigned int i=0;i<num;i++){
        cin>>seq;
        sequeue.push_back(seq);
    }
    for(int i=0;i<num;i++){
        cout<<sequeue[i]<<" = "<<Fib_base(sequeue.at(i))<<" (fib)"<<endl;
    }

    return 0;
}
