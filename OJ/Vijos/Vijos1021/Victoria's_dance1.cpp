#include "stdio.h"
using namespace std;

int main(){
    int n, k, x, ans=0;
    scanf("%d%d", &n, &k);
    
    while(n--){
        int tot = 0;
        while(scanf("%d",&x)&&x) tot++;
        if(tot >= k)
            ans++;
    }
    printf("%d", ans);
    return 0;
}
