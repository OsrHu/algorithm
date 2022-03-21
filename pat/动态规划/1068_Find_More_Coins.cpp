#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 10010, M = 110;

int n ,m;
int a[N];
bool f[N][M];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)  cin >> a[i];

    sort(a + 1, a + n + 1, greater<int>());

    f[0][0] = true;

    for(int i = 1; i <= n;i ++)
    {
        for(int j = 0; j <= m; j ++)
        {
            f[i][j] = f[i-1][j];
            if(j >= a[i]) f[i][j] |= f[i-1][j-a[i]];
        }
    }

    if(!f[n][m]) cout << "No Solution\n";
    else
    {   bool is_first = true;
        while(n)
        {          
            if(m >= a[n] && f[n - 1][m - a[n]])
            {
                if (is_first) is_first = false;
                else cout << ' ';
                cout << a[n];
                m -= a[n];
            }
            n -- ;
        }
    }

    return 0;
}
