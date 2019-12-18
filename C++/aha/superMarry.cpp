/*
大家都知道"超级玛丽"是一个很善于跳跃的探险家，他的拿手好戏是跳跃，但它一次只能向前跳一步或两步。
有一次，他要经过一条长为n的羊肠小道，小道中有m个陷阱，这些陷阱都位于整数位置，分别是a1,a2,....am，陷入其中则必死无疑。
显然，如果有两个挨着的陷阱，则玛丽是无论如何也跳过不去的。
现在给出小道的长度n，陷阱的个数及位置。求出玛丽从位置1开始，有多少种跳跃方法能到达胜利的彼岸（到达位置n）
输入：
第一行为两个整数n,m
第二行为m个整数，表示陷阱的位置
数据规模：
40>=n>=3,m>=1
n>m;
陷阱不会位于1及n上
本题思路采用爬楼梯问题解法，即S(n)=S(n-1)+S(n-2)，但是因为可能会有陷阱，所以要根据情况判断。因为1和n不会有陷阱，
所以最坏情况为n=2时，一步过去，n=3时根据不同陷阱情况，有不同解法
*/
#include <iostream>

using namespace std;

int trap[40]={0};

int way(int n)
{
    if (n==2)
        return 1;
    if (n==3)
    {
        if (trap[n-1]==1)
            return 1;
        else
            return 2;
    }
    else {
        if (trap[n-1] == 1){
            if(trap[n-2] ==0)
                return way(n-2);
            else
                return 0;
        }
        else {
            if (trap[n-2]==1)
                return way(n-1);
            else
                return way(n-1)+way(n-2);
        }
    }

}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i=0;i<m;i++)
    {
        int t;
        cin >> t;
        trap[t] = 1;
    }
    cout << way(n) << endl;
    return 0;
}
