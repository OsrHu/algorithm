#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N], cnt[N];

int main()
{
    cin >> n;

    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];
        cnt[a[i]] ++;
    }

    bool flag = false;
    for(int i = 0; i < n; i ++)
    {
        if(cnt[a[i]] == 1)
        {
            cout << a[i] << endl;
            return 0;
        }
    }

    if(!flag) cout << "None\n";

    return 0;
}