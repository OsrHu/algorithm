#include<iostream>
#include<algorithm>

using namespace std;


int main()
{
    int n;
    cin >> n;
    int s = 0, len = 0;
    for(int i = 2; i <= n / i ; i ++)
    {   
        int j = i;
        int tmp = n;
        while(tmp % j == 0)
        {   
            tmp = tmp / j;
            j++;    
            
        }
        if(j - i > len)
        {
            len = j - i ;
            s = i;
        }
    }

    if (len == 0 )
    {
         cout << 1 << endl << n;
    }
    else
    {
        cout << len << endl;
        for(int i = 0 ; i < len; i++)
        {
            if(i != 0) cout << "*";

            cout << s + i ; 
        }
    }
}