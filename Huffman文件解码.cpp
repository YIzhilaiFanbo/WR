#include<iostream>

using namespace std;

struct BTNode{
	char data;
	BTNode* child0;
	BTNode* child1;
	BTNode():child0(NULL),child1(NULL){}
	BTNode(char d){
		data=d;
		child0=child1=NULL;
	}
};

BTNode* createTree(int n){
	BTNode* root=new BTNode();
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		char ch=str[0];
		BTNode* current=root;
		for(int k=2;k<str.length();k++){
			if(str[k]=='0'){
				if(!current->child0){
					current->child0=new BTNode();	
				}
				current=current->child0;
			}else{
				if(!current->child1){
					current->child1=new BTNode();	
				}
				current=current->child1;
			}
		}
		current->data=str[0];

	}
	return root;
}

string decode(BTNode* root){
	freopen("in.txt","r",stdin);
	string result;
	string str;
	cin>>str;
	BTNode* current=root;
	for(int i=0;i<str.length();i++){
		if(str[i]=='0'){
			current=current->child0;
		}else{
			current=current->child1;
		}
		if(!current->child0&&!current->child1){
			result+=current->data;
			current=root;
		}
	}
	return result;
}

int main(){
	int n;
	cin>>n;
	BTNode* root=createTree(n);
	cout<<decode(root);
	return 0; 
}
