#include <iostream>

using namespace std;

int f[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int number(int x){
    int sum = 0;
    while(x/10 != 0){
        sum += f[x%10];
        x /= 10;
    }
    sum += f[x];
    return sum;
}

int main(){
    int n,c;
    cin >> n;
    for(int i=0;i<1112;i++)
        for(int j=0;j<1112;j++)
        {
            c = i+j;
            if(number(i)+number(j)+number(c)==(n-4))
                cout<< i <<"+"<< j << "=" << c <<endl;
        }
    return 0;
}
