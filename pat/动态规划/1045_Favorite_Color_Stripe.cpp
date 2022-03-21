// 最长公共子序列的变种
#include<iostream>

using namespace std;

const int N = 210, M = 10010;

int n, m, l;
int p[N], s[M];
int f[N][M];

int main()
{
    cin >> n;
    cin >> m;
    for(int i = 1; i <= m; i ++) cin >> p[i];

    cin >> l;;
    for(int i = 1; i <= l; i ++) cin >> s[i];

    for(int i = 1; i <= m; i ++)
    {
        for(int j = 1; j <= l; j ++)
        {
            f[i][j] = max(f[i-1][j], f[i][j-1]);
            if(p[i] == s[j]) f[i][j] = max(f[i][j], f[i][j-1] + 1);
        }
    }

    cout << f[m][l] << endl;
    return 0;
}
