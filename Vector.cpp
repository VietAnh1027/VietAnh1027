#include<iostream>
#include<string.h>

using namespace std;

struct sinhvien{
    int stt;
    char masv[10];
    char ten[10];
};

struct vector{
    int count = -1;
    sinhvien e[8];
};

sinhvien input_sv(){
    sinhvien a;
    //cout << "Nhap stt: "; cin >> a.stt;
    //cout << "Nhap ma sinh vien: "; fflush(stdin); gets(a.masv);
    cout << "Nhap ten sinh vien: "; fflush(stdin); gets(a.ten);
    return a;
}

vector input_vt(){
    vector a;
    int n;
    cout << "Nhap so sinh vien: "; cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Nhap sinh vien thu " << i + 1 << ": \n";
        a.e[i] = input_sv();
        a.count++;
    }
    return a;
}

void printvector(vector a){
    for(int i = 0; i <= a.count; i++){
        cout << a.e[i].ten << " ";
    }
    cout << "\n";
}

void del_first(vector &a){
    for(int i = 0; i <= a.count; i++){
        a.e[i] = a.e[i + 1];
    }
    a.count--;
}

void insert_vt(vector &a, int vitri){
    cout << "Nhap sinh vien can chen: \n";
    sinhvien b = input_sv();
    for(int i = a.count; i >= vitri - 1; i--){
        a.e[i + 1] = a.e[i];
    }
    a.e[vitri - 1] = b;
    a.count++;
}

void sapxep(vector &a){
    for(int i = 0; i <= a.count; i++){
        int m = i;
        for(int j = i + 1; j <= a.count; j++){
            if(strcmp(a.e[m].ten, a.e[j].ten) > 0){
                m = j;
            }
        }
        sinhvien temp = a.e[m];
        a.e[m] = a.e[i];
        a.e[i] = temp;
    }
}

int main(){
    vector dsach = input_vt();
    printvector(dsach);
    del_first(dsach);
    printvector(dsach);
    insert_vt(dsach, 3);
    printvector(dsach);
    sapxep(dsach);
    printvector(dsach);
}