#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool canPopStack(int N,string istr,string ostr){
	stack<char>istring;
	stack<char>ostring;
	for(int i=N-1;i>=0;i--){
		ostring.push(ostr[i]);
	}
	int a=0;
    while (!ostring.empty()) {
        if (istring.empty() || istring.top() != ostring.top()) {
            if (a >= N) {
                return false;  
            }
            istring.push(istr[a]);
            a++;
        } else {
            istring.pop();
            ostring.pop();
        }
    }
	return true;
}

int main(){
	int N;
	cin>>N;
	if(N<=3||N>=26){
		cout<<"false";
		return 0;
	}
	string istr(N, ' ');
	string ostr(N, ' ');
	for(int i=0;i<N;i++){
		char ch;
		cin>>ch;
		istr[i]=ch;
	}
	for(int i=0;i<N;i++){
		char ch;
		cin>>ch;
		ostr[i]=ch;
	}
	if(canPopStack(N,istr,ostr)){
		cout<<"true";
	}else{
		cout<<"false";
	}
	return 0;
} 
