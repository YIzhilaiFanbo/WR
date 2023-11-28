#include<iostream>
#include<string>
#include<vector>
using namespace std;

void comPress(){
	string str;
	vector<int>count;
	char ch;
	while(cin>>ch){
		if(ch!=str[str.length()-1]){
			str+=ch;
			count.push_back(1);
		}else{
			count.back()++;
		}
	}
	for(int i=0;i<str.length();i++){
		cout<<str[i]<<" ";
		if(count[i]>1){
			cout<<count[i]<<" ";
		}
	}
}

int main(){
	freopen("in.txt","r",stdin);
	comPress();
	return 0;
}
