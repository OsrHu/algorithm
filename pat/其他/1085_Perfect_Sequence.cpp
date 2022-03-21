#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 100010;

int n,p;
int a[N];

int main()
{
    cin >> n >> p;

    for(int i = 1; i <= n; i ++) cin >> a[i];
    sort(a, a + n);
    int res = 0;
    for(int i = 1, j = 0; i <=n; i ++)
    {
        while(j < i && (long long)a[j] * p < a[i]) j ++;
        res = max(res, i - j + 1);
    }

    cout << res << endl;

    return 0;
}