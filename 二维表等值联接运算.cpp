#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

struct DataNode			
{
	vector<int>data;
	DataNode* next;	 
	DataNode(int d){
		data.resize(d);
	} 
};

struct HNode	
{
	int Row, Col;	
	DataNode* next;	

	HNode() :next(NULL) {}		
	HNode(int r, int c)		 
	{
		Row = r;
		Col = c;
		next = NULL;
	}
};

void link(HNode h1,HNode h2,int a1,int a2){
	ofstream outfile("abc.out");
	DataNode* d1=h1.next;
	DataNode* d2=h2.next;
	while (d1 != NULL) {
        while (d2 != NULL) {
			if(d1->data[a1-1]==d2->data[a2-1]){
				for(int x=0;x<h1.Col;x++){
					outfile<<d1->data[x]<<" ";
				}
				for(int x=0;x<h2.Col;x++){
					outfile<<d2->data[x]<<" ";
				}
				outfile<<endl;
			}
			d2=d2->next;
		}
		d1=d1->next;
		d2 = h2.next;
	}
	outfile.close();
}

int main(){
	freopen("in.txt","r",stdin);
	int m1,n1,m2,n2,a1,a2;
	cin>>m1>>n1;
	HNode h1(m1,n1);
	DataNode* r=new DataNode(n1);
	h1.next=r;
	for(int k=0;k<n1;k++){
			cin>>r->data[k];
		}
	for(int k=0;k<m1-1;k++){
		DataNode *s=new DataNode(n1);
		r->next=s;
		r=s;
		for(int k=0;k<n1;k++){
			cin>>r->data[k];
		}
	}
	r->next=NULL;
	cin>>m2>>n2;
	HNode h2(m2,n2);
	r=new DataNode(n2);
	h2.next=r;
	for(int k=0;k<n2;k++){
			cin>>r->data[k];
		}
	for(int k=0;k<m2-1;k++){
		DataNode *s=new DataNode(n2);
		r->next=s;
		r=s;
		for(int k=0;k<n2;k++){
			cin>>r->data[k];
		}
	}
	r->next=NULL;	
	cin>>a1>>a2;	
	link(h1,h2,a1,a2);
	return 0;
} 

