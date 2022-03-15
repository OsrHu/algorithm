// 推理题基本都是枚举题
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 510;

int n;
int a[N];

bool judge(int k, int i, int j)
{
    int t = a[k];
    if(t > 0)
    {
        if(t == i || t ==j) return 1;
        return 0;
    }

    t = -t;
    if(t == i || t == j) return 0;
    return 1;

}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i ++)
    {
        for(int j = i + 1; j <= n; j ++)
        {   
            int s = judge(i, i, j) + judge(j, i ,j);
            if(s != 1) continue;

            s = 0;
            for(int k = 1; k <= n; k ++)
            {
                s += judge(k, i, j);
            }

            if(s != 2) continue;

            cout << i << " " << j << endl;
            return 0;
        }
    }

    cout << "No Solution" << endl;

    return 0;
}