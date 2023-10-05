#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

int findLastMinNode(ListNode* head){
	if(!head){
		return -1;//链表为空 ，表示没找到 
	}
	int last_node=0;
	int min_val=head->val; 
	ListNode* c=head;
	int c_index=0;
	while(c){
		if(c->val<=min_val){
			min_val=c->val;
			last_node=c_index;
		}
		c=c->next;
		c_index++;
	}
	return last_node+1;
}

int main(){
	int n;
//	freopen("in.txt", "r", stdin);
	cin>>n;
	ListNode* head=NULL;
	ListNode* tail=NULL;
	
	for(int i=0;i<n;i++){
		int val;
		cin>>val;
		ListNode* newNode= new ListNode(val);
		if(!head){
			head=newNode;
			tail=newNode;
		}else{
			tail->next=newNode;
			tail=newNode;
		}	
	}
	tail->next=NULL;
	
	int result =findLastMinNode(head);
	cout<<result<<endl;
	
	ListNode* c=head;
	while(c){
		ListNode*temp=c;
		c=c->next;
		delete temp;
	}
	
	return 0;
}
