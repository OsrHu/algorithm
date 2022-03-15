#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>  n

using namespace std;

const int N = 30;

int n;
string w[N];
int l[N], r[N];
bool has_father[N];
int root = 1;

string dfs(int u)
{   
    string ans;

    if(u == -1) 
    {
        return "";
    }
    
    string left = dfs(l[u]);
    ans = w[u];
    string right = dfs(r[u]);
    if(u == root) ans =  left + ans + right ;
    else if(l[u] == -1 && r[u] == -1) ans =  left + ans + right ;
    else ans = "(" + left + ans + right + ")";

    return ans;
}

int main()
{
    cin >> n;
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    for(int i = 1; i<= n; i ++)
    {
        cin >> w[i];
        int ll, rr;
        cin >> ll >> rr;
        if(ll != -1)
        {
            l[i] = ll;
            has_father[ll] = true;
        }
        if(rr != -1)
        {
            r[i] = rr;
            has_father[rr] = true;
        }
    }
    while(has_father[root]) root ++;

    string res = dfs(root);

    cout << res << endl;
}