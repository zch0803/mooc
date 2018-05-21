#include<iostream>
#include<fstream>

using namespace std;

int main(){
    char first = 'a';
    char second = 'a';
    char third = 'a';
    char fourth = 'a';
    char fifth = 'a';
    
    char a, b_1, b_2, c, d, e;
    ifstream fin;
    fin.open("in");
    fin >> a >> b_1 >> b_2 >> c >> d >> e;
    cout << a << b_1 << b_2 << c << d << e;
    
    return 0;
}
