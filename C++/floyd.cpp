#include <iostream>
#include <fstream>

using namespace std;
int n,m;
int e[100][100];
int inf = 99999999;


int main(){
    ifstream fin("floyd.txt");
    if(!fin){
        cerr << "can't find file" <<endl;
        return 1;
    }
    fin >> n >> m;
    int x, y, z;
    for (int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==j) e[i][j] = 0;
            else e[i][j] = inf;
        }
    for(int i=1;i<=m;i++){
        fin >> x >> y >> z;
        e[x][y] = z;
    }
    //floyd算法的关键部分
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(e[i][k]+e[k][j]<e[i][j])
                    e[i][j] = e[i][k]+e[k][j];
            }
    //上面五行代码就是floyd算法
    for (int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        {
            cout<< e[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
