#include<iostream>

using namespace std;

struct node{
	int data;
	node* left;	
	node* right;
};

node* createNode(int data){
	node* temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void addNode(node* &dau, int data){
	if(dau == NULL){
		dau = createNode(data);
	}
	else if(dau->data > data){
		addNode(dau->left, data);
	}
	else{
		addNode(dau->right, data);
	}
}

void TaoCay(node* &dau){
	int x;
	do{
		cout << "Nhap so nguyen, ket thuc nhap -1: ";
		cin >> x;
		if(x == -1) break;
		addNode(dau, x);
	} while(1);
}

void delNode(node* &dau, int k){
	if(dau->data == k){
		dau = NULL;
	}else if(k > dau->data){
		delNode(dau->right, k);
	} else {
		delNode(dau->left, k);
	}
}

void printroot(node* dau){
	node* root = dau;
	if(root != NULL){
		cout << root->data << " ";
		printroot(root->left);
		printroot(root->right);
	}
}

int main(){
	int n, x; 
	cout << "n = "; cin >> n;
	node* l = NULL;
	TaoCay(l);
	
	printroot(l);
	delNode(l, 24);
	cout << '\n';
	printroot(l);
}
	