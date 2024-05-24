#include<iostream>

using namespace std;

struct Queue{
    int front;
    int near;
    int arr[10];
};

void defaultQ(Queue &e){
    e.front = 0;
    e.near = -1;
}

bool checkEmpty(Queue e){
    return e.near == -1;
}

bool checkFull(Queue e){
    return e.near == 10;
}

void q_push(Queue &e, int data){
    if(checkFull(e)){
        cout << "Queue da day !\n";
    } else {
        e.near++;
        e.arr[e.near] = data;
    }
    
}

int q_pop(Queue &e){
    if(checkEmpty(e)) return NULL;
    else{
        int k;
        if(e.front == e.near){
            k = e.arr[e.front];
            defaultQ(e);
        } else {
            k = e.arr[e.front];
            e.front++;
        }
        return k;
    }
}

int main(){
    Queue e;
    defaultQ(e);
    int n = 5;
    int x; 
    for(int i = 0; i < n; i++){
        cout << "Nhap Queue e[" << i << "]: ";
        cin >> x;
        q_push(e, x);
    }
    for(int i = 0; i < n; i++){
        cout << q_pop(e) << " ";
    }
}
