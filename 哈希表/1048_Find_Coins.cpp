#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;

int n, m;
int a[N];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
    {
        int tmp;
        cin >> tmp;
        a[tmp] ++;
    }

    for(int i = 0; i < N; i ++)
    {
        if(a[i] != 0 && a[m - i] != 0)
        {
            if(i == m - i && a[i] <= 1) continue;

            cout << i << " " << m - i << endl;

            return 0;
        }
    }

    cout << "No Solution" << endl;

    return 0;
}