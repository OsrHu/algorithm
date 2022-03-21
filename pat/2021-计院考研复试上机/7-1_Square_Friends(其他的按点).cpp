#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int n, maxA;

bool check(int A, int B)
{
    for (int i = 0; i < n; i++) {
        if (B * B / 1000 != A) return false;
        A++;
        B++;
    }
    return true;
}

int main()
{
    cin >> n >> maxA;   

    bool flag1 = false;
    for(int i = 1; i <= maxA; i ++)
    {
        string tmp = to_string(i) + string(3, '0');
        string tmp2 = to_string(i + 1) + string(3, '0');
        int s = to_string(i).size();
        int a, b;   
        a = ((int) (sqrt(stoi(tmp)))) ;
        b = ((int) sqrt(stoi(tmp2))) ;
        
        
        
        for(int j = a; j <= b; j ++)
        {               
            // cout << j << " " << j + n - 1 << endl;
            // int k = j;
            // int cnt = n;
            // int last = i;
            // bool flag = true;
            // while(cnt)
            // {   
            //     // cout << to_string(pow(k, 2)).substr(0, s) << " " << to_string(last) << endl;
            //     if(to_string(pow(k, 2)).substr(0, s) == to_string(last))
            //     {
            //             cnt--;
            //             k ++;
            //             last = last + 1;
            //     }
            //     else
            //     {   
            //         flag = false;
            //         break;
            //     }
            // }

            if(check(i, j))
            {
                flag1 = true;
                cout << i << " " << j << endl;
            }
        }
        
    }

    if(!flag1) cout <<  "No Solution." << endl;

    return 0;
}