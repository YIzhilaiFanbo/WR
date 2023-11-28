#include<iostream>
#include<fstream>
using namespace std;

int MaxSum(int m,int n,int x,int y){
	int max=0;
	int sum=0;
	int a[m][n];
	for(int i=0;i<m;i++){
		for(int k=0;k<n;k++){
			cin>>a[i][k]; 
		}
	}
	for(int i=0;i<m-x+1;i++){
		for(int k=0;k<n-y+1;k++){
			int t=i;
			for(int p=0;p<x;p++){
				int s=k;
				for(int q=0;q<y;q++){
					sum+=a[t][s];
					s++;
				}
				t++;
			}
			if(sum>max){
				max=sum;
			}
			sum=0;
		}
	}
	return max;
}

int main(){
	freopen("in.txt","r",stdin);
	int m,n,x,y;
	cin>>m>>n>>x>>y;
	cout<<MaxSum(m,n,x,y);
	return 0;
}
