#include <bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;++i)
#define P pair<int,int>

const int max_N = 100000;
P arr[max_N];
int main()
{
    int N; scanf("%d", &N);
    loop(i, N) scanf("%d %d", &arr[i].first, &arr[i].second);
    sort(arr, arr + N);
    loop(i, N) printf("%d %d\n", arr[i].first, arr[i].second);
    return 0;
}