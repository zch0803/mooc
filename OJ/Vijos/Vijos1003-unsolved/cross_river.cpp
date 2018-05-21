#include<iostream>
using namespace std;

int L, S, T, M;
int Stone[101];

int mini(int *a)
{
    int minn = 100;
    for (int i=0;i<9;i++)
    {
        //cout << a[i] << endl;
        if(minn>a[i])
            minn = a[i];
    }
    return minn;
}

int isStone(int location)
{
    for (int l=0;l<M+1;l++)
    {
        if (location==Stone[l])
            return 1;
    }
    return 0;
}

int MinStone(int start, int end)
{
    if (start>=L-T and start<=L-S)
        return isStone(start);
    else {
        int result[9] = {100,100,100,100,100,100,100,100,100};
        for (int i=S; i<=T; i++)
        {
            if (start+i<=L){
                result[i-S] = isStone(start+i)+MinStone(start+i, end);
            }
        }
        return mini(result);
    }
}

int main()
{
    cin >> L;
    cin >> S >> T >> M;
    
    for (int i=0; i<M; i++)
    {
        cin >> Stone[i];
    }
    cout << MinStone(0, L);
}
