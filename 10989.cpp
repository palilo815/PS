#include <stdio.h>

int cnt[10001];
int main()
{
    int N, n;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &n);
        ++cnt[n];
    }
    for (int i = 1;i < 10001;++i) {
        int t = cnt[i];
        while (t--) printf("%d\n", i);
    }
    return 0;
}