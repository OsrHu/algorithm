#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>

using namespace std;

const int N = 50;

int n;
set<int> s;
int sum(int x)
{   
    int res = 0;
    while(x)
    {
        res += x % 10;
        x /= 10;
    }

    return res;
}



int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        int x;
        cin >> x;
        s.insert(sum(x));
    }
    bool is_first = true;
    cout << s.size() << endl;
    for(auto x: s)
    {   
        if(!is_first) cout << " ";
        cout << x;
        if(is_first) is_first = false;
    }
}