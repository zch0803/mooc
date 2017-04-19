#include <iostream>
#include <fstream>

using namespace std;

int Min=99999999,book[101],n,e[101][101];

void dfs(int city, int distance){
    if (distance > Min) //如果距离已经超过最小值，就没有继续搜索下去的必要，这是比较好的剪枝
        return;
    if(city == n){
        if(distance < Min)
            Min = distance;
        return;
    }
    for(int i=1;i<=n;i++){
        if(e[city][i]!=99999999 && book[i]==0 )
        {
            book[i]=1;
            dfs(i, distance+e[city][i]);
            book[i]=0;
        }
    }
    return;
}

int main(){
    int m,x,y,z;
    ifstream fin("city.txt");
    if(!fin){
        cerr << "can't open file" <<endl;
        return 1;
    }

    fin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(i == j)
                e[i][j] = 0;
            else
                e[i][j] = 99999999;
        }
    for(int i=1; i<=m; i++){
        fin >> x >> y >> z;
        e[x][y] = z;
    }

    book[1] = 1;
    dfs(1,0);
    cout << Min <<endl;
    return 0;
}
