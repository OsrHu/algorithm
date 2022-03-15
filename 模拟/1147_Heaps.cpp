#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1110;



int m,n;
int tr[N];
int v[N];
vector<int> path;

void dfs(int u,int& k)
{   
    if(u > n) return;

    dfs(u * 2, k);
    dfs(u * 2  + 1, k);
    cout << v[u];
    if( ++ k != n) cout << " ";
    else cout << endl;
}


int main()
{
    cin >> m >> n;
    while(m --)
    {   
        bool gt = false , lt = false;
        int k = 0;
        path.clear();
        for(int i = 1; i <= n; i ++) // 细节之处 这里下标必须是1开始
        {
            cin >> v[i];
        }

        for(int i = 2; i <= n; i ++)
        {
            if(v[i] < v[i/2])  gt = true;
            if(v[i] > v[i/2])  lt = true;
        }
        
        if(gt && lt)
        {
            cout << "Not Heap" << endl;
        }
        else if(gt)
        {
            cout << "Max Heap" << endl;
        }
        else
        {
            cout << "Min Heap" << endl;
        }
        dfs(1, k);
    }

    return 0;
}