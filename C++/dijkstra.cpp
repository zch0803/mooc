#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int e[10][10];//邻接矩阵记录顶点之间的边
    int dis[10]; //记录顶点间最短距离
    int book[10]={0}; //记录是否属于集合P，book[i]=0不属于
    int inf = 99999999;
    int n,m;
    ifstream fin("dijkstra.txt");
    fin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(i==j) e[i][j]=0;
            else e[i][j]=inf;
    int x, y, d;
    for(int i=1;i<=m;i++){
        fin >> x >> y >> d;
        e[x][y] = d;
    }
    for(int i=1;i<=n;i++){
        dis[i]=e[1][i];
    }
    book[1] = 1;
    //dijkstra算法开始
    int Min, a; //min用来查找最小值，a用来记录最小值的位置
    for(int i=1;i<=n-1;i++){
        Min = inf;
        for(int j=1;j<=n;j++){
            if(book[j]==0 && dis[j]<Min){
                Min = dis[j];
                a = j;
            }
        }
        book[a]=1;
        for(int j=1;j<=n;j++){
            if(dis[a]+e[a][j]<dis[j])
                dis[j] = dis[a] + e[a][j];
        }
    }
    for(int i=1;i<=n;i++)
        cout << dis[i] << " ";
    return 0;
}
