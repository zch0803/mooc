#include <iostream>

using namespace std;

int main()
{
    int a[11]={0};
    int t;
    for(int i=1;i<=5;i++){
        cin >> t;
        a[t]++;
    }

    for(int i=0;i<=10;i++)
    {
        for(int j=i;j<=a[i];j++)
            cout << i <<" ";
    }
    getchar();
    //system("pause");
    return 0;
}
