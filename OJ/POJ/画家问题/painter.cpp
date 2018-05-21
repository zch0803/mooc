#include<iostream>
#include<stdlib.h>
//'y':0 'w':1
using namespace std;

int paint[16][17], press[16][17]; //paint为初始状态，press为画家需要画黄色的地方
int N;

//display为调试输出函数
void display(){
    for(int i=0;i<N+1;i++){
        for(int j=0;j<N+2;j++)
            cout << press[i][j] << " ";
        cout << endl;
    }
}

//guess为确定第一行的状态后，依次推理后面所有行的状态，并判断最后一行是否全部是黄色，如果是返回true，如果不是，返回false
bool guess(){
    int c,r;
    for(r=1;r<N;r++)
        for(c=1;c<N+1;c++)
            //通过上一行的状态来判定下一行位置应不应该涂颜色
            press[r+1][c] = (paint[r][c]+press[r][c-1]+press[r][c+1]+press[r-1][c]+press[r][c])%2;
    //判断最后一行是否全黄色
    for(c=1;c<N+1;c++)
        if((press[N][c-1]+press[N][c]+press[N][c+1]+press[N-1][c])%2!=paint[N][c])
        {
            return false;
        }
    return true;
}

//遍历第一行的所有状态，通过一个二进制的加法实现，就不用写循环了。如果能够找到满足条件的方法返回true，找不到返回false
bool enumerate(){
    int c;
    
    for(c=1;c<N+1;c++)
        press[1][c]=0;
    while(true){
        if(guess()==true) return true;
        press[1][1]++;
        c = 1;
        while(press[1][c]>1){
            press[1][c] = 0;
            c++;
            press[1][c] ++;
        }
        if(press[1][N+1]==1){
            return false;
        }
    }
}

int main(){
    cin >> N;
    char a;
    for(int j=0; j<N+2; j++)
        press[0][j] = 0;
    
    for(int i=0; i<N+1; i++)
        press[i][0] = press[i][N+1] = 0;
    
    for(int i=1; i<N+1; i++)
        for(int j=1; j<N+1; j++){
            cin >> a;
            if(a=='w'){
                paint[i][j] = 1;
            }
            else{
                paint[i][j] = 0;
            }
            //cout << i << " " << j << endl;
        }
    if(enumerate()){
        int sum = 0;
        for(int r=1;r<N+1;r++)
            for(int c=1;c<N+1;c++)
                if(press[r][c]==1)
                    sum++;
        cout<<sum<<endl;
    }
    else
        cout << "inf" <<endl;
    return 0;
}
