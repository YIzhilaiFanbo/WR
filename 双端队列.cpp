#include<iostream>
#include<queue>
using namespace std;

void changeOrder(int N,int grade[]){
	queue<int>gra;
	for(int i=0;i<N;i++){
		if(grade[i]>=90){
			gra.push(grade[i]);
		}
	}
	for(int i=0;i<N;i++){
		if(grade[i]<60){
			gra.push(grade[i]);
		}
	}
	for(int i=0;i<N;i++){
		if(grade[i]>=60&&grade[i]<90){
			gra.push(grade[i]);
		}
	}
	for(int i=0;i<N;i++){
		if(i!=N-1){
			cout<<gra.front()<<" ";
		}else{
			cout<<gra.front();
		}
		gra.pop();
	}
}

int main(){
	int N;
	cin>>N;
	if(N<=3||N>=20){
		return -1;
	}
	int grade[N];
	for(int i=0;i<N;i++){
		cin>>grade[i];
	}
	changeOrder(N,grade);
	return 0;
} 
