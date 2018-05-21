#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

struct node{
    char color;
    int loc;
    node *next;
    node *prev;
};

node *head;

void Init(string str){
    int len = str.size();
    //cout << str <<endl;
    node *q;
    for(int i = 0;i < len; i++){
        //cout << "num: " << i << endl;
        node *p = new node;
        //cout << p << endl;
        p -> color = str[i];
        p -> loc = i;
        p -> next = NULL;
        p -> prev = NULL;
        if (i == 0){
            q = p;
            head = q;
            //cout << head->color <<endl;
        }
        else{
            //cout << "q" << q->color <<endl;
            //cout << "p" << p->color <<endl;
            q -> next = p;
            p -> prev = q;
            q = p;
        }
    }
}

void Insert(char color, int loc){
    
}

void Delete(){
    
}

void CheckDelete(){
    node *t = head;
    while(t != NULL){
        cout << t->color << " " << t->loc << endl;
        t = t-> next;
        //break;
    }
}

void PrintList(){
    node *t = head;
    while(t != NULL){
        cout << t->color << " " << t->loc << endl;
        t = t-> next;
        //break;
    }
}

int main(){
    string s;
    getline(cin, s);
    Init(s);
    PrintList();
    return 0;
}
