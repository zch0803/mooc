#include <iostream>
#include <stdlib.h>
//链表实现时，经常会出现Segmentation fault: 11的报错，一般这种情况为越界了，或者链表访问了没有的位置
using namespace std;

class list{
private:
    struct node{
        int data;
        struct node *next;
    };
    struct node *head;
    struct node *p;
    struct node *t;
    struct node *q;
    struct node *o;
public:
    list(){
        head = NULL;
    }
    ~list(){
        t = head;
        while(head!=NULL){
            t = head -> next;
            delete head;
            head = t;
        }
    }
    void append(int num){
        //下面两种分配内存的方式分别对应于C++和C语言中分配内存的方法
        p = new struct node[sizeof(struct node)];
        //p = (struct node*)malloc(sizeof(struct node));
        p -> data = num;
        p -> next = NULL;
        if(head == NULL)
            head = p;
        else
            q -> next = p;
        q = p; //这句话很关键，有了这句话q就代表了p的上一个节点，每一次新的p添加时，添加到q的后面就好了
    }
    void insert(int num){
        t = head;
        o = NULL;
        p = new struct node[sizeof(struct node)];
        p -> data = num;
        p -> next = NULL;
        bool flag = true;
        while(t){
            if(t-> data < num){
                o = t;       // o 用来记录上一个节点的位置
                t = t-> next;
                continue;
            }
            else{
                if(o==NULL){  //处理前面的值都比p值大，如何插入
                    head = p;
                    p-> next = t;
                }
                else{
                    o-> next = p;
                    p-> next = t;
                }
                flag = false;
                break;
            }
        }
        if (head == NULL){  //主要用于判断空链表情况下，插入p
            head = p;
        }
        if(flag == true){  //在前面值都比p小的情况下的插入
            o -> next = p;
        }
    }
    void del(int num){
        t = head;
        if(t->data == num){
            head = t->next;
            delete t;
        }
        else
        while(1){
            if(t->next == NULL)
                break;
            if(t->next->data == num){
                o = t->next;
                t->next = t->next->next;
                delete o;
                break;
            }
            t = t->next;
        }
    }
    void printlist(){
        t = head;
        while(t){
            cout << t -> data <<" ";
            t = t -> next;
        }
        cout << endl;
    }
};

int main(){
    list t;

    t.append(1);
    t.append(2);
    t.append(3);
    t.append(4);
    t.append(6);
    t.insert(5);
    t.del(1);
    t.printlist();
    return 0;
}
