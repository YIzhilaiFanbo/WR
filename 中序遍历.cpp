#include<iostream>
#include<vector>
using namespace std;

struct BTNode{
	int data;
	BTNode* lchild;
	BTNode* rchild;
	BTNode():lchild(NULL),rchild(NULL){}
	BTNode(int d){
		data=d;
		lchild=rchild=NULL;
	}
};

BTNode* createTree(int M){
	vector<BTNode*>Nodes;
	for(int i=0;i<M;i++){
		int d;	
		cin>>d;
		BTNode* Node=new BTNode(d);
		Nodes.push_back(Node);
	}
	int x=0;
	for(int y=1;y<M;){
		if(y<M&&Nodes[y]->data!=0){
			Nodes[x]->lchild=Nodes[y];
		}else{
			Nodes[x]->lchild=NULL;
		}
		y++;
		if(y<M&&Nodes[y]->data!=0){
			Nodes[x]->rchild=Nodes[y];	
		}else{
			Nodes[x]->rchild=NULL;
		}	
		y++;
		x++;
	}
	return Nodes[0];
}

void inorderTraversal(BTNode* root){//ÖÐÐò±éÀú 
	 if (root) {
        inorderTraversal(root->lchild);
        cout << root->data<<" ";
        inorderTraversal(root->rchild);
    }
}

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int M;
		cin>>M;
		BTNode* root = createTree(M);
		inorderTraversal(root);	
		cout<<endl;
	}
	return 0;
} 
