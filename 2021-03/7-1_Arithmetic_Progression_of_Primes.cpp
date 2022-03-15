#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 10010;

int n, maxp;
int cnt; //9592
int a[N];

bool is_prime(int x)
{
    if(x < 2) return false;

    for(int i = 2; i * i <= x; i ++)
    {
        if(x % i == 0) return false;
    }

    return true;
}

void init()
{
    int x = 2;
    while(cnt < N)
    {   
        if(x > 1e5) break;
        if(is_prime(x)) a[cnt ++] = x;
        x++;
    }
}

int main()
{
    init();

    cin >> n >> maxp;

    int diff;
    if(n != 1) diff = maxp / (n - 1);
    else diff = 0;

    bool flag = false;
    int ans_s = -1, ans_diff = -1;
    while(diff--)
    {   
        if(flag) break;
        for(int i = 0; i < cnt; i ++)
        {   
            bool flag2 = true;
            if(a[i] + diff * (n - 1) > maxp) continue;
            else
            {
                for(int j = 1; j < n; j ++)
                {   
                    if(!is_prime(a[i] + diff * j))
                    {
                        flag2 = false;
                        break;
                    }
                }

                if(flag2)
                {
                    ans_s = a[i];
                    ans_diff = diff;
                    flag = true;
                }
            }
        }
    }

    if(ans_diff == 0|| diff == -1)
    {   
        int i = 0;
        while(a[i] <= maxp && i < cnt) i ++;
        cout << a[i - 1];
    }
    else
    {   

        cout << ans_s;
        for(int i = 1; i < n; i ++)
        {
            cout << " "  << ans_s + ans_diff * i;
        }
    }
    
    
    
}