#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_set>

using namespace std;

const int N = 510;

int n, r, k, m;
int g[N][N];
int animals[N];

int main()
{
    cin >> n >> r >> k;
    while(r --)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }

    cin >> m;
    while(m --)
    {
        unordered_set<int> s;
        for(int i = 1; i <= n; i ++)
        {
            cin >> animals[i];
            s.insert(animals[i]);
        }
        if(s.size() > k)
        {
            cout << "Error: Too many species." << endl;
        }
        else if(s.size() < k)
        {
            cout << "Error: Too few species." << endl;
        }
        else
        {   
            bool flag = true;
            for(int i = 1; i <= n; i ++)
            {
                for(int j = 1; j <= n; j ++)
                {
                    if(i != j && g[i][j])
                    {
                        if(animals[i] == animals[j])
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if(!flag) break;
            }

            if(!flag) cout << "No\n";
            else cout << "Yes\n";
        }
    }

    return 0;
}
