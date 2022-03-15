#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

const int N = 40;

int n;
stack<int> stk;
int l[N], r[N];

void dfs(int u,int& k)
{
    if(!u) return;
    
    dfs(l[u],k);
    dfs(r[u],k);
    
    if(k++ !=0) cout << ' ';
    cout << u ;
    
}

int main()
{
    cin >> n;
    int last = 0;
    int type;
    int root;
    for(int i = 0; i < n * 2; i ++)
    {
        string op;
        int x;
        cin >> op;
        if(op == "Push")
        {
            cin >> x;
            if(!last) root = x;
            else{
                if(type == 0)
                {
                    l[last] = x;
                }
                else{
                    r[last] = x;
                }
            }
            stk.push(x);
            last = x;
            type = 0;
        }
        else
        {
            last = stk.top();
            stk.pop();
            type = 1;
        }
    }
    int k = 0;
    dfs(root,k);
    
    return 0;
}