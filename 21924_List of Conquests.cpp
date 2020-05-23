#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
	int num,pos;
	map<string,int> list;
	map<string,int>::iterator iter;
	string str,substr_;
	cin>>num;
	str="\n";
	getline(cin,str);
	while(num--){
		getline(cin,str);
		pos = str.find_first_of(" ",0);
		substr_ = str.substr(0,pos);
		iter = list.find(substr_);
		if(iter != list.end()){
			iter->second++;
		}else{
			list.insert(pair<string,int>(substr_,1));
		}
		str.erase(0);
		substr_.erase(0);
	}
	for(iter = list.begin();iter!=list.end();iter++){
		cout<<iter->first<<" "<<iter->second<<endl;
	}
	return 0;
}
