/**
 置换群
 先自环，后与另一个环连接
 
 */
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;
int p[N];

int main()
{
    cin >> n;
    for(int i = 0;i < n; i ++)
    {
        int x;
        cin >> x;
        p[x] = i;
    }

    int res = 0;
    
    for(int i = 0; i < n;)
    {   
        while (p[0]) swap(p[0], p[p[0]]), res ++ ;
        while(i < n && p[i] == i) i ++;
        if(i < n) swap(p[0], p[i]), res ++;
    }
    
    cout << res << endl;

    return 0;
}