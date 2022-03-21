#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_set>

using namespace std;

const int N = 10100;

int n, m;
int a[N];
// unordered_map<int, unordered_map<int, bool>> g;
struct Egde
{
    int a, b;
}edges[N];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
    {
        cin >> edges[i].a >> edges[i].b;
    }

    while(m --)
    {
        int k;
        cin >> k;
        unordered_set<int> s;

        for(int i = 0; i < k; i ++)
        {
            int a;
            cin >> a;
            s.insert(a);
        }

        bool success = true;
        for(int i = 0; i < n; i ++)
        {   
            auto t = edges[i];
            if(s.count(t.a) && s.count(t.b))
            {
                success = false;
                break;
            }
        }

        if(success) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}