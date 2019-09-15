//约瑟夫环//
#include <stdio.h>
//返回的是第K次出队的人的编号//
int ysfh(int n, int m, int k) {
    if (k == 1)
        return (n + m - 1) % n;
    else
        return (ysfh(n - 1, m, k - 1) + m) % n;
}
// n是总人数，m是隔多少个人出队,k是第几次//
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    //循环输出//
    for (int i = 1; i <= n; i++) {
        ysfh(n, m, i);
        m--;
    }
    printf("%d\n", ysfh(n, m, n) + 1);
}
