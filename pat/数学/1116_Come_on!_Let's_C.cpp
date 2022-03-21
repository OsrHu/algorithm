#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e4 + 10;

int n, k;
int check[N];
bool st[N];

bool is_prime(int x)
{
    if(x < 2) return false;

    for(int i = 2; i * i <= x; i ++)
    {
        if(x % i == 0) return false;
    }

    return true;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        int id;
        cin >> id;
        check[id] = i + 1;
    }

    cin >> k;
    for(int i = 1; i <= k; i ++)
    {
        int id;
        cin >> id;
        if(check[id])
        {   
            if(!st[id])
            {
                st[id] = true;
                if(check[id] == 1)
                {
                    printf("%04d: Mystery Award\n", id);
                }
                else if(is_prime(check[id]))
                {
                    printf("%04d: Minion\n", id);
                }
                else
                {
                    printf("%04d: Chocolate\n", id);
                }
            }
            else
            {
                printf("%04d: Checked\n", id);
            }
        }
        else
        {
            printf("%04d: Are you kidding?\n", id);
        }
    }

}