#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int n, radix;

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
    while(cin >> n, n > 0)
    {
        cin >> radix;
        if(!is_prime(n))
        {
            cout << "No\n";
        }
        else
        {   
            int res = 0;
            while(n)
            {
                res = res * radix + n % radix;
                n /= radix;
            }

            if(is_prime(res))
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }

    return 0;
}