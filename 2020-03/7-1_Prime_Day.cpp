#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e8 + 10;

bool is_prime(int x)
{
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i ++)
    {
        if(x % i == 0) return false;
    }

    return true;
}

int len(int x)
{   
    int len = 0;

}

int main()
{

    string s;
    cin >> s;
    bool flag = true;
    int k = s.size();
    while(s.size())
    {      
        int num = stoi(s); 

        if(is_prime(num))
        {
            cout << s << " " << "Yes" << endl;
        }
        else
        {
            cout << s << " " << "No" << endl;
            flag = false;
        }

        s = s.substr(1);
        
    }

    if(flag) cout << "All Prime!" << endl;

    return 0;
}