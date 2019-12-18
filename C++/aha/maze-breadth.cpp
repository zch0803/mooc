#include <iostream>
#include <fstream>
using namespace std;

struct queue{
    int x;
    int y;
    int f;
    int step;
};

int main(){
    struct queue que[2501];
    int a[51][51] = {0},book[51][51] = {0};
    int next[4][2]={{0,1},{0,-1},{1,0},{-1,0}};//定义了四个方向应该如何走
    int head,tail;
    int startx, starty, stopx, stopy, n, m, tx, ty;
    ifstream fin;
    //string filename;
    //getline(cin, filename, '\n');
    fin.open("maze.txt");
    if(!fin){
        cerr << "file can't open" <<endl;
        return 1;
    }
    fin >> n >> m;
    for(int i = 1;i<=n;i++)
        for(int j=1;j<=m;j++){
            fin >> a[i][j];
        }
    fin >> startx >> starty;
    fin >> stopx >> stopy;
    //初始化起始点
    head = 1;
    tail = 1;
    que[tail].x = startx;
    que[tail].y = starty;
    que[tail].f = 0;
    que[tail].step = 0;
    tail ++;
    book[startx][starty] = 1;
    int flag = 0;
    while(head < tail){
        for(int k = 0; k < 4 ; k++){
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];
            if(tx<1 || tx>n || ty<1 || ty>m)
                continue;
            if(a[tx][ty] == 0 && book[tx][ty] == 0){
                book[tx][ty] = 1;
                que[tail].x = tx;
                que[tail].y = ty;
                que[tail].f = head;
                que[tail].step = que[head].step+1;
                tail++;
            }
            if(tx == stopx && ty == stopy){
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            break;
        head++; //只有当一个节点将四周都试遍了以后才能head++，也就是对后面的点进行扩展
    }
    cout << que[tail-1].step <<endl;
    return 0;
}
