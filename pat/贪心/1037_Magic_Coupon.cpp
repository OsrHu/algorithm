#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int nc, np;
int a[N], b[N];

int main()
{
    cin >> nc;
    for(int i = 0; i < nc; i ++) cin >> a[i];
    cin >> np;
    for(int i = 0; i < np; i ++) cin >> b[i];

    sort(a, a + nc);
    sort(b, b + np);

    int res = 0;
    for(int i = 0, j = 0; i < nc && j < np; i ++ , j ++)
    {
        if(a[i] >= 0 || b[j] >= 0) break;
        res += a[i] * b[j];
    }

    for(int i = nc-1, j = np-1; i >= 0 && j >=0; i--, j--)
    {
        if(a[i] <= 0 || b[j] <= 0) break;
        res += a[i] * b[j];
    }

    cout << res << endl;

    return 0;
}