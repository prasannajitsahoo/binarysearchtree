#include<iostream>
using namespace std;
//class Node
class Node{
	//make public
	public:
	int data;
	Node* left,* right;
	Node(int value){
		data=value;
		left=NULL;
		right=NULL;
	}
};
//class Tree
class BiST{
	//make public
	public:
	Node* root;
	BiST(){
		root=NULL;
	}
	//recursion
	void insert1(int value,Node* &current){
		if(current==NULL){
			current=new Node(value);
			if(root==NULL){root=current;}
			return;		
		}
		else if(current->data>=value){
			//cout<<"left,";
			insert1(value,current->left);
		}
		else if(current->data<value){
			//cout<<"right,";
			insert1(value,current->right);
		}
		else{}
	}
	//inserts the data
	//it will insert the greater number in right side and smaller number in left side
	void insert(int value){
			insert1(value,root);
			//cout<<"NULL"<<endl;
	}
	//recursion display
	void display1(Node* current){
		//stoping condition
		if(current==NULL){return;}
		else{
			//first go to the left leaf
			display1(current->left);
			//print the data
			cout<<current->data<<"->";
			//then go to the right
			display1(current->right);
		}
	}
	//display function
	void display(){
		 display1(root);
		cout<<"NULL"<<endl;	
	}
	// searches the value in the node
	Node* search(Node* current,int value){
		//if it does not get any value or it gets
		if(current==NULL || current->data==value) return current;
		else if(current->data>value) return search(current->left,value);
		else return search(current->right,value);
	}
};
//main
int main(){
	BiST b;
	for(int i=1;i<10;i++){
		b.insert(i);
	}
	//b.display();
	//b.insert(0);
	b.display();
	return 0;
}
