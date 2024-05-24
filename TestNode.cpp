#include<iostream>
#include<string.h>


using namespace std;

struct sinhvien{
    int stt;
    char masv[10];
    char ten[10];
};

struct node{
    sinhvien data;
    node* next;
};

node* createNode(sinhvien a){
    node* temp = new node;
    temp->data = a;
    temp->next = NULL;
    return temp;
}

node* addNode(node* truoc, sinhvien a){
    node* temp = createNode(a);
    truoc->next = temp;
    return temp;
}

sinhvien input_sv(){
    sinhvien a;
    //cout << "Nhap stt: "; cin >> a.stt;
    //cout << "Nhap ma sinh vien: "; fflush(stdin); gets(a.masv);
    cout << "Nhap ten sinh vien: "; fflush(stdin); gets(a.ten);
    return a;
}

void printlist(node* dau){
    node* temp = dau;
    cout << "Danh sach sinh vien: ";
    while(temp != NULL){
        cout << temp->data.ten << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void del_head(node* &dau){
    node* temp = dau;
    dau = dau->next;
    delete temp;
}

void insert_sv(node* &dau, int vitri){
    node* temp = dau;
    cout << "Nhap sinh vien can chen: \n";
    node* chen = createNode(input_sv());
    if(vitri < 1){
        cout << "Vi tri khong hop le ! \n";

    } else if(vitri == 1) {
        chen->next = dau;
        dau = chen;

    } else {
        for(int i = 0; i < vitri - 2; i++){
            if(temp->next == NULL){
                break;
            }
            temp = temp->next;   
        }
        chen->next = temp->next;
        temp->next = chen;
    }
}

void sapxep(node* &dau){
    node* dau1 = dau;
    while(dau1->next != NULL){
        node* M = dau1;
        node* Q = dau1->next;
        while(Q != NULL){
            if(strcmp(M->data.ten, Q->data.ten) > 0){
                M = Q;
            }
            Q = Q->next;
        }
        sinhvien temp = M->data;
        M->data = dau1->data;
        dau1->data = temp;
        dau1 = dau1->next;
    }
}

int main(){
    int n; 
    cout << "So sinh vien: "; cin >> n;
    cout << "Nhap sinh vien thu 1: \n";
    node* l = createNode(input_sv());
    node* p = l;
    for(int i = 1; i < n; i++){
        cout << "Nhap sinh vien thu " << i + 1 << ": \n";
        p = addNode(p, input_sv());
    }
    printlist(l);
    del_head(l);
    printlist(l);
    insert_sv(l, 100);
    printlist(l);
    sapxep(l);
    printlist(l);
}