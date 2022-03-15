#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

const int N = 1010;

int m, n, S;

string names[N];
unordered_map<string, bool> st;

int main()
{
    cin >> m >> n >> S;
    
    for(int i = 1; i <= m; i ++)
    {
        cin >> names[i];
    }

    bool flag = false;

    while(S <= m)
    {
        flag = true;

        if(!st[names[S]]) cout << names[S] << endl;
        else
        {
            S += 1;
            continue;
        }
        st[names[S]] = true;

        S += n;
    }

    if(!flag) cout << "Keep going..." << endl;


}