#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

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
    int x;
    cin >> x;
    if(is_prime(x) && (is_prime(x - 6) || is_prime(x + 6)))
    {   
        cout << "Yes" << endl;
        if(is_prime(x - 6)) cout << x - 6 << endl;
        else if(is_prime(x + 6)) cout << x + 6 << endl;
    }
    else
    {
        cout << "No" << endl;
        while(!is_prime(x) || !(is_prime(x - 6) || is_prime(x + 6))) x ++;
        cout << x << endl;
    }

    return 0;
}