#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include <sstream>
using namespace std;

struct BTNode{
	string data;
	BTNode* lchild;
	BTNode* rchild;
	BTNode():lchild(NULL),rchild(NULL){}
	BTNode(string d){
		data=d;
		lchild=rchild=NULL;
	}
};

BTNode* createTree(string exp){
	queue<BTNode*>postexp;
	stack<BTNode*>opand;
	stack<char>opor;
	int i=0;
	char ch;
	//转为后缀表达式 
	while(i<exp.length()){
		ch=exp[i];
		if(ch=='('){
			opor.push(ch);
		}else if(ch==')'){
			while(!opor.empty()&&opor.top()!='('){
				BTNode* B=new BTNode();
				B->data+=opor.top();
				postexp.push(B);
				opor.pop();
			}
			opor.pop();
		}else if(ch=='+'||ch=='-'){
			while(!opor.empty()&&opor.top()!='('){
				BTNode* B=new BTNode();
				B->data+=opor.top();
				postexp.push(B);
				opor.pop();
			}
			opor.push(ch);
		}else if(ch=='*'||ch=='/'){
			while(!opor.empty()&&opor.top()!='('&&(opor.top()=='*'||opor.top()=='/')){
				BTNode* B=new BTNode();
				B->data+=opor.top();
				postexp.push(B);
				opor.pop();
			}
			opor.push(ch);
		}else{
			string d="";
			while(ch>='0'&&ch<='9'){
				d+=ch;
				i++;
				if(i<exp.length()){
					ch=exp[i];
				}else{
					break;
				}
			}
			i--;
			BTNode* B=new BTNode(d);
			postexp.push(B);
		}
		i++;
	}
	while(!opor.empty()){
		BTNode* B=new BTNode();
		B->data=opor.top();
		postexp.push(B);                                                                                                                                                                                                                                                                                                            
		opor.pop();
	}
	//建立二叉树 
	while(!postexp.empty()){
		if(postexp.front()->data=="+"||postexp.front()->data=="-"||postexp.front()->data=="*"||postexp.front()->data=="/"){
			BTNode* parent=new BTNode();
			parent->rchild=opand.top();
			opand.pop();
			parent->lchild=opand.top();
			opand.pop();
			parent->data=postexp.front()->data;
			opand.push(parent);
		}else{
			opand.push(postexp.front());
		}
		postexp.pop();
	}
 	return opand.top();
}


void preorderTraversal(BTNode* root){//前序遍历 
	if (root) {
        if(root->data=="+"||root->data=="-"||root->data=="*"||root->data=="/"){
        	cout << root->data;
		}else{
			cout << root->data<<"#";
		}
        preorderTraversal(root->lchild);
        preorderTraversal(root->rchild);
    }
}

void inorderTraversal(BTNode* root){//中序遍历 
	 if (root) {
        inorderTraversal(root->lchild);
        if(root->data=="+"||root->data=="-"||root->data=="*"||root->data=="/"){
        	cout << root->data;
		}else{
			cout << root->data<<"#";
		}
        inorderTraversal(root->rchild);
    }
}

void postorderTraversal(BTNode* root){//后序遍历 
	if (root) {
        postorderTraversal(root->lchild);
        postorderTraversal(root->rchild);
        if(root->data=="+"||root->data=="-"||root->data=="*"||root->data=="/"){
        	cout << root->data;
		}else{
			cout << root->data<<"#";
		}
    }
}

void levelTraversal(BTNode* root){//层次遍历 
	 if (!root) return;
    queue<BTNode*> q;
    q.push(root);
    while (!q.empty()) {
        BTNode* current = q.front();
        q.pop();
        if(current->data=="+"||current->data=="-"||current->data=="*"||current->data=="/"){
        	cout << current->data;
		}else{
			cout << current->data<<"#";
		}
        if (current->lchild) q.push(current->lchild);
        if (current->rchild) q.push(current->rchild);
    }
}

void caculate(BTNode* root){
	if(root->lchild && root->rchild){
		caculate(root->lchild);
		caculate(root->rchild);
		int a=0;
		int b=0;
		int c=0;
		stringstream ss;
		for(int i=0;i<root->lchild->data.length();i++){
			if(root->lchild->data[i]=='-'){
				continue;
			}
			a=10*a+(root->lchild->data[i]-'0');
		}
		if(root->lchild->data[0]=='-'){
			a=0-a;
		}
		for(int i=0;i<root->rchild->data.length();i++){
			if(root->rchild->data[i]=='-'){
				continue;
			}
			b=10*b+(root->rchild->data[i]-'0');
		}
		if(root->rchild->data[0]=='-'){
			b=0-b;
		}
		switch(root->data[0]){
			case'+':
				c=a+b;
				break;
			case'-':
				c=a-b;
				break;
			case'*':
				c=a*b;
				break;
			case'/':
				c=a/b;
				break;
		}
		ss<<c;
		root->data=ss.str();
	}
} 

int main(){
	string exp;
	char ch;
	do{
		cin>>ch;
		if(ch!='='){
			exp+=ch;
		}
	}while(ch!='=');
	BTNode* root = createTree(exp);	 
	preorderTraversal(root);
	cout<<endl;
	inorderTraversal(root);
	cout<<endl;
	postorderTraversal(root);
	cout<<endl;
	levelTraversal(root);
	cout<<endl;
	caculate(root);
	cout<< root->data;
	return 0;
} 
