#include<iostream>

using namespace std;

struct Stack{
    int top = -1;
    int arr[10];
};

bool checkFull(Stack a){
    return a.top == 10;
}

bool checkEmpty(Stack a){
    return a.top == -1;
}

void s_push(Stack &a, int data){
    if(checkFull(a)) return;
    a.top++;
    a.arr[a.top] = data;
    cout << "Push thanh cong !\n";
} 

int s_pop(Stack &a){
    if(checkEmpty(a)) return -1;
    int result = a.arr[a.top];
    a.top--;
    return result;
}

int main(){
    Stack a;
    int n;
    int he;
    cout << "Nhap so he 10: "; cin >> n;
    cout << "Chuyen thanh he so: "; cin >> he;
    while(n != 0){
        int x = n % he;
        /*switch(x){
            case 10:
                char x = 'A';
                break;
            case 11:
                char x = 'B';
                break;
            case 12:
                char x = 'C';
                break;
            case 13:
                char x = 'D';
                break;
            case 14:
                char x = 'E';
                break;
            case 15:
                char x = 'F';
                break;
        }*/
        s_push(a, x);
        n = n / he;
        

    }
    while(a.top != - 1){
        cout << s_pop(a) << " ";
    }
}