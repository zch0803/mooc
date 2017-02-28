#include <iostream>

using namespace std;

int n;

void quicksort(int left, int right, int *a){
    //cout << "i am quicksort"<<left <<" "<<right <<endl;
    int temp = a[left];
    int i=left;
    int j=right;
    int t;
    for (int xx=left; xx<right+1; xx++)
        cout << a[xx];
    cout << endl;
    if(left == right)
        return;
    while(i!=j){
        while (a[j]<temp && i<j)    //while(a[j]<=temp && i<j)
            j--;
        while (a[i]>temp && i<j)    //while(a[i]>=temp && i<j)
            i++;
        //cout << i << " " << j << endl;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    t = temp;
    temp = a[i];
    a[i] = temp;
    if (i>left)                   //if in loop you use a[j]<= temp and a[i]>=temp
        quicksort(left,i-1,a);    //there won't need to add if
    if (i< right)                 //you can write quicksort(left,i-1,a);quicksort(i+1,right,a);
        quicksort(i+1,right,a);
    //cout << "i'm out!" <<endl;
}

int main() {
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    //cout << "enter quicksort"<<endl;
    quicksort(0,n-1,a);
    for (int i=0; i<n; i++)
        cout << a[i] << " ";
    delete []a;
    return 0;
}
