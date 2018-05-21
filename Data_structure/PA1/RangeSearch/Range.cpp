#include<iostream>
#include "stdio.h"
using namespace std;

void quickSort(int s[], int l, int r)
{
    if (l< r)
    {
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j]>= x) // 从右向左找第一个小于x的数
                j--;
            if(i < j)
                s[i++] = s[j];
            while(i < j && s[i]< x) // 从左向右找第一个大于等于x的数
                i++;
            if(i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quickSort(s, l, i - 1); // 递归调用
        quickSort(s, i + 1, r);
    }
}

int BinarySearch(int a[], int value, int n){
    int low, high, mid;
    low = 0;
    high = n-1;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(a[mid]==value)
            return mid;
        if(a[mid]>value)
            high = mid-1;
        if(a[mid]<value)
            low = mid+1;
    }
    return low; //这里return low的话其实是在无法hit的情况，将大于要查找的数的第一个位置返回。这是在查找数在数组范围内的情况，如果不在数组范围内，则会相应返回两个边界值中的一个。
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
//    cout << n << ' ' << m << endl;
    int *range = new int[n];
    for(int i = 0;i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        range[i] = tmp;
    }
    quickSort(range, 0, n - 1);
    int *start = new int[m];
    int *end = new int[m];
    
    for(int i = 0;i < m; i++){
        scanf("%d %d", &start[i], &end[i]);
    }
    for(int i = 0;i < m; i++){
        
        int ans_start = BinarySearch(range, start[i], n-1);//注意这里只有使用二分查找或者更快的查找，才能在规定时间内完成，按照最传统的O(n)复杂度的算法无法通过
        int ans_end = BinarySearch(range, end[i], n-1);
        //根据二分查找的算法，这里分为两种情况，第一情况是右边界在数组中没有找到，这时会返回比右边界大的一个一个数，这种情况下，无论左边界在数组的位置如何，结果都是找到的位置直接相减即可。
        if (end[i] < range[ans_end]){
            printf("%d\n", ans_end - ans_start);
        }
        //第二种情况是右边界在数组有对应的值，或者右边界超过了数组的最大值，这时返回两个位置之差并加一即可，但是有一种情况除外，就是左边界也大于最大值，这时应该返回0，不能返回ans_end - ans_start + 1
        else if(end[i] >= range[ans_end]){
            if(start[i] > range[n-1]){
                printf("%d\n", 0);
                continue;
            }
            printf("%d\n", ans_end - ans_start + 1);
        }
    }
    delete [] start;
    delete [] end;
    return 0;
}
