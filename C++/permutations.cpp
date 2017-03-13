#include <iostream>

using namespace std;
int a[10],book[10],n;

void dfs(int step){
    if(step == n+1){
        for(int i=1;i<=n;i++)
        {
            cout<< a[i] <<" ";
        }
        cout<<endl;
    }
    for(int i = 1; i<=n ; i++){
        if(book[i]!=1){
            a[step] = i;
            book[i] = 1;
            dfs(step+1);
            book[i] = 0; //这一步至关重要，在向下搜索返回后，通过这一步回收刚刚放出的值，可以继续向下搜索。
        }
    }
    return;
}

int main()
{
    cin >> n;
    dfs(1);
    return 0;
}
