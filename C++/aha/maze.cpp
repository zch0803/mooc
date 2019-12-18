#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int a[51][51],book[51][51];
int startx, starty, stopx, stopy, n, m;
int Min = 99999999;
void dfs(int x,int y, int step){
    if(x == stopx && y == stopy){
        if(step < Min)
            Min = step;
        return;
    }
    int next[4][2]={{0,1},{0,-1},{1,0},{-1,0}};//定义了四个方向应该如何走
    int tx, ty;
    for(int k=0; k<4; k++ ){
        tx = x + next[k][0];
        ty = y + next[k][1];
        if(tx<1 || tx>n || ty<1 || ty>m)
            continue;
        if(a[tx][ty] == 0 && book[tx][ty] == 0){
            book[tx][ty] = 1;
            dfs(tx,ty,step+1);
            book[tx][ty] = 0;  //深度搜索最关键一步，再尝试过此节点后回退
        }
    }
    return;
}

int main(){
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
    dfs(startx,starty,0);
    cout << Min << endl;
    return 0;
}
