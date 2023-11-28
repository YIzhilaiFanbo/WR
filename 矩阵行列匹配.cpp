#include<iostream>
#include<fstream> 
using namespace std;

void match(int m,int n){
	ofstream outfile("out.txt");
	int num[m][n];
	int c=0;
	for(int i=0;i<m;i++){
		for(int k=0;k<n;k++){
			cin>>num[i][k];
		}
	}
	for(int i=0;i<m;i++){
		int s1=0;
		for(int p=0;p<n;p++){
			s1+=num[i][p];
		}
		for(int k=0;k<n;k++){
			int s2=0;
			for(int q=0;q<m;q++){
				s2+=num[q][k];
			}
			if(s1==s2){
				c++;
			}
		}
	}
	outfile<<c;
	outfile.close();
}


int main(){
	freopen("in.txt","r",stdin);
	int m,n;
	cin>>m>>n;
	match(m,n);
	return 0;
}
