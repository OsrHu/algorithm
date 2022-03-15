#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
    int k;
    int n, m;
    cin >> k;
    vector<int>num(k);

    for(int i = 0; i < k ; i ++)
    {
        int x;
        cin >> x;
        num[i] = x;
    }


    sort(num.begin(), num.end(), greater<int>());

    int mindis = INF;
    for(int i = 0; i <= k; i ++)
    {
        int j = 0;
        while(j < i && j * i != k) j ++;
        
        if(j * i == k)
        {
            if( i - j < mindis)
            {   
                mindis = i - j;
                n = j;
                m = i;

            }
        }
    }


    vector<vector<int>> ans(m, vector<int>(n));
    

    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
    int x = 0, y = 0;
    int d = 1;
    for(int i = 0; i < k; i ++)
    {
        ans[x][y] = num[i];
        
        int a = x + dx[d], b = y + dy[d];
        if(a < 0 || a >= m || b < 0 || b >= n || ans[a][b])
        {
            d = (d + 1) % 4;
            a = x + dx[d], b = y + dy[d];
        }
        x = a , y = b;
    }

    for(int i = 0 ; i < m; i ++)
    {
        cout << ans[i][0];
        for(int j = 1; j < n; j ++)
            cout << " " << ans[i][j];
        cout << endl;
    }

    return 0;


    


}