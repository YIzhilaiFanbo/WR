#include<iostream>
#include<fstream> 
using namespace std;

void multiply(int m,int n,int nums1[],int nums2[]){
	ofstream outfile("out.txt");
	int prodnums[m+n-1];
	for(int i=0;i<m+n-1;i++){
		prodnums[i]=0;
	}
	for(int i=0;i<m;i++){
		for(int k=0;k<n;k++){
			prodnums[i+k]+=nums1[i]*nums2[k];
		}
	}
	for(int i=0;i<m+n-1;i++){
		outfile<<prodnums[i]<<" ";
	}
	outfile.close();
}

int main(){
	freopen("in.txt","r",stdin);
	int m,n;
	cin>>m;
	int nums1[m];
	for(int i=0;i<m;i++){
		cin>>nums1[i];
	}
	cin>>n;
	int nums2[n];
	for(int i=0;i<n;i++){
		cin>>nums2[i];
	}
	multiply(m,n,nums1,nums2);
	return 0;
}
