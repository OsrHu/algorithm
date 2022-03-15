#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1100;

int n;
int w[N];
vector<vector<int> >paths;
vector<int> path;
int cnt;

void dfs(int u)
{   
    if(u > n) return;

    path.push_back(w[u]);

    if(u * 2 > n)
    {
        paths.push_back(path);
        cnt ++;
    }
    
    dfs(u * 2 + 1);
    dfs(u * 2);

    path.pop_back();
}

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i ++ )
    {
        cin >> w[i];
    }

    dfs(1);


    bool gt = false, ft = false;
    for(int i = 0;i < cnt;i ++)
    {   
        cout << paths[i][0];
        for(int j = 1; j < paths[i].size(); j ++)
        {   
            if(paths[i][j] > paths[i][j-1])  ft = true;
            if(paths[i][j] < paths[i][j-1])  gt = true;
            cout << " " << paths[i][j] ;
        }
        cout << endl;
    }

    if(gt && ft) cout << "Not Heap";
    else if(gt) cout << "Max Heap";
    else cout << "Min Heap";

}