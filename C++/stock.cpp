#include <iostream>
#include <string>
using namespace std;

class Stock {
private:
    int top;
    char *a;
    int N;
public:
    Stock (int num){
        top = 0;
        N = num;
        a = new char[N];
    }
    ~Stock (){
        delete []a;
    }
    void pop(){
        top--;
    }
    void push(char num){
        a[top] = num;
        top++;
    }
    void printtop(){
        cout << top <<endl;
    }
    int gettop(){
        if (top!=0)
            return a[top-1];
        else{
            printf("%s\n", "stock is null");
        }
    }
    void printstock(){
        for(int i = 0;i<top;i++)
            cout << a[i] << endl;
        cout << endl;
    }
};

bool ishuiwen(char *a){
    int len = strlen(a);
    //cout << len << endl;
    Stock s(len);
    int mid = len/2;
    for (int i=0; i<mid; i++){
        s.push(a[i]);
    }
    //s.printstock();
    bool flag = true;
    for (int i=mid+mid%2; i<len; i++){
        //cout <<"a[i]"<<a[i]<< endl;
        //s.printtop();
        //s.printstock();
        if(s.gettop()==int(a[i])){
            s.pop();
            continue;
        }
        else{
            flag = false;
            break;
        }
    }
    return flag;
}

int main(int argc, char const *argv[]) {
    char a[100];
    gets(a);
    if (ishuiwen(a))
        printf("congratulation!");
    else
        printf("failed");
    return 0;
}
