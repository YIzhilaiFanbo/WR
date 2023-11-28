#include<iostream>
#include<fstream>
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
			s++;
			num++;
		}
		h++;
		s--;
		x--;
		for(int i=0;i<x;i++){
			a[h][s]=num;
			h++;
			num++;
		}
		s--;
		h--;
		for(int i=0;i<x;i++){
			a[h][s]=num;
			s--;
			num++;
		}
		h--;
		s++; 
		x--;
		for(int i=0;i<x;i++){
			a[h][s]=num;
			h--;
			num++;
		}
		s++;
		h++;
	}
	cout<<"["<<endl;
	for(int i=0;i<n;i++){
		for(int o=0;o<n;o++){
			if(o==0){
				cout<<"[";
			}
			cout<<a[i][o];
			if(o==n-1){
				cout<<"]";
			}
			if(o!=n-1||i!=n-1){
				cout<<",";
			}
		}
		cout<<endl;
	}
	cout<<"]";
}

int main(){
	freopen("in.txt","r",stdin); 
	int n;
	cin>>n;
	if(n<=0){
		return -1;
	}
	rectangle(n);
	return 0;
} 

