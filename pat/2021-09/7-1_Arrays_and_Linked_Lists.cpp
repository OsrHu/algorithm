#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e4 + 10;

int n, k;
struct Space
{
    int address, l;
}spaces[N];

int main()
{
    cin >> n >> k;
    int total = 0;
    for(int i = 0; i < n; i ++)
    {
        cin >> spaces[i].address >> spaces[i].l;
        total += spaces[i].l;
    }

    int maxx = 1;
    while(k --)
    {
        int q;
        cin >> q;
        if(q >= total)
        {
            cout << "Illegal Access" << endl;
            continue;
        } 
        else
        {   
            for(int i = 0; i < n; i ++)
            {       
                maxx = max(i + 1, maxx);
                if(q < spaces[i].l)
                {   
                    cout << spaces[i].address + 4 * q << endl;
                    break;;
                }           
                q -= spaces[i].l;
                
            }
        }
    }
    cout << maxx << endl;

    return 0;
}