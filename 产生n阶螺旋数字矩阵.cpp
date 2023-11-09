#include<iostream>
using namespace std;

void rectangle(int n){
	int a[n][n];
	int h=0;
	int s=0;
	int num=1;
	int x=n;
	while(num<=n*n){
		for(int i=0;i<x;i++){
			a[h][s]=num;
//			cout<<num;
			s++;
			num++;
		}
		h++;
		s--;
		x--;
		for(int i=0;i<x;i++){
			a[h][s]=num;
//			cout<<num;
			h++;
			num++;
		}
		s--;
		h--;
		for(int i=0;i<x;i++){
			a[h][s]=num;
//			cout<<num;
			s--;
			num++;
		}
		h--;
		s++; 
		x--;
		for(int i=0;i<x;i++){
			a[h][s]=num;
//			cout<<num;
			h--;
			num++;
		}
		s++;
		h++;
	}
	for(int i=0;i<n;i++){
		for(int o=0;o<n;o++){
			cout<<a[i][o]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	if(n<=0||n>10){
		return -1;
	}
	rectangle(n);
	return 0;
} 
