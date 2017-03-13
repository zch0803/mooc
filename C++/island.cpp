//宝岛探险：从island.txt中读取一个n*m的矩阵，还有一个起始坐标，矩阵中0代表海水，大于0的数字代表陆地，寻找起始坐标所在的陆地面积
//本题解题思想为采用广度搜索的方法，但是深度搜素也能够实现，只是在深度搜索时不改变访问过节点的值，即一个节点只会访问一次。
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int a[51][51],book[51][51];
int startx, starty, sum, n, m;
void dfs(int x,int y, int color){
    int next[4][2]={{0,1},{0,-1},{1,0},{-1,0}};//定义了四个方向应该如何走
    int tx, ty;
    a[x][y] = color;
    for(int k=0; k<4; k++ ){
        tx = x + next[k][0];
        ty = y + next[k][1];
        if(tx<1 || tx>n || ty<1 || ty>m)
            continue;
        if(a[tx][ty] > 0 && book[tx][ty] == 0){
            sum++;
            book[tx][ty] = 1;
            dfs(tx,ty,color);
            //book[tx][ty] = 0;  //深度搜索最关键一步，再尝试过此节点后回退
        }
    }
    return;
}

int main(){
    ifstream fin;
    //string filename;
    //getline(cin, filename, '\n');
    fin.open("island.txt");
    if(!fin){
        cerr << "file can't open" <<endl;
        return 1;
    }
    fin >> n >> m;
    fin >> startx >> starty;
    for(int i = 1;i<=n;i++)
        for(int j=1;j<=m;j++){
            fin >> a[i][j];
        }
    book[startx][starty] = 1;
    sum = 1;
    dfs(startx,starty,-1);
    cout << sum << endl;
    for (int i = 1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << a[i][j]<< " ";
        }
        cout << endl;
    }
    return 0;
}
