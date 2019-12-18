#include<iostream>
using namespace std;

class Queue{
private:
    int head;
    int tail;
    int a[1000];
public:
    Queue(){
        head = 0;
        tail = 0;
        for(int i=0; i<1000; i++)
            a[i] = 0;
    }
    ~Queue(){
    }
    void inqueue(int num){
        //cout << "num=" << num << endl;
        //cout << "tail=" << tail << endl;
        a[tail] = num;
        //cout << "a[tail]" << a[tail] << endl;
        tail ++;
    }
    void dequeue(){
        if(tail > head){
            head++;
        }
        else{
            cout << "queue is null, can't dequeue";
        }
    }
    void out(){
        for(int i = head; i<tail; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    bool empty(){
        if (head == tail)
            return 1;
        else
            return 0;
    }
    int gethead(){
        return a[head];
    }
};

int main(){
    Queue q;
    int b[10] = {0};
    int a[9] = {6,3,1,7,5,8,9,2,4};
    for(int i=0; i<9; i++){
        //cout << "a[i]" << a[i]<< endl;
        q.inqueue(a[i]);
        //q.out();
    }
    //q.out();
    int i = 0;
    while (!q.empty()){
        b[i] = q.gethead();
        //cout << "i=" << i << "b[i]=" << b[i] << endl;
        i++;
        q.dequeue();
        q.inqueue(q.gethead());
        q.dequeue();
        //q.out();
    }
    //q.out();
    for(int j=0;j<i;j++)
        cout << b[j] << " " ;
    cout << endl;
    return 0;
}
