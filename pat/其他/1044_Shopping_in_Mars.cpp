#include<iostream>
#include<cstring>

using namespace std;

const int N = 100010, INF = 1e9;

int n,m;
int s[N];

int main()
{
    cin >> n >> m;

    for(int i = 1; i<= n; i ++)
    {
        cin >> s[i];
        s[i] += s[i - 1];
    }

    int res = INF;

    for(int i = 1, j = 0; i <= n; i ++)
    {
        while(j < i && s[i] - s[j + 1] >= m) j ++; //对于每一个i,找最靠右边的j
        if(s[i] - s[j] >= m) res = min(res, s[i] - s[j]);
    }

    for (int i = 1, j = 0; i <= n; i ++ )
    {
        while(j < i && s[i] - s[j + 1] >= m) j ++ ;
        if (s[i] - s[j] == res) printf("%d-%d\n", j + 1, i);
    }

    return 0;
}

