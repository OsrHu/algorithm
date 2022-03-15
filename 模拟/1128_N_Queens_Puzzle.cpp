#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;

int k, n;
int a[N];

int main()
{
    cin >> k;
    while(k --)
    {
        cin >> n;
        for(int i = 1; i <= n; i ++ )
            cin >> a[i];

        bool flag = true;
        for(int i = 1; i <= n; i ++)
        {
            for(int j = 1; j <= n; j ++)
            {
                if(i == j) continue;

                if(a[i] == a[j] || abs(i - j) == abs(a[i] - a[j]))
                {
                    flag = false;
                    break;
                }
            }
        }

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}