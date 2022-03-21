#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int n, maxA;

int main()
{
    cin >> n >> maxA;   

    bool flag1 = false;
    for(int i = 1; i <= maxA; i ++)
    {
        string tmp = to_string(i) + string(3, '0');
        string tmp2 = to_string(i + n) + string(3, '0');
        int s = to_string(i).size();
        int a, b;   
        a = ((int) (sqrt(stoi(tmp)))) ;
        b = ((int) sqrt(stoi(tmp2)));
        
        
        
        for(int j = a; j + n - 1 <= b; j ++)
        {   
            // if(i == 99) cout << i << " " << j  << endl;
            // cout << j << " " << j + n - 1 << endl;
            s = to_string(i).size();
            int k = j;
            int cnt = n;
            int last = i;
            bool flag = true;
            while(cnt)
            {   
                // if(i == 99)
                // cout << to_string(pow(k, 2)).substr(0, s) << " " << to_string(last) << endl;
                if(to_string(pow(k, 2)).substr(0, s) == to_string(last))
                {
                        cnt--;
                        k ++;
                        last = last + 1;
                        s = to_string(last).size();

                }
                else
                {   
                    flag = false;
                    break;
                }
            }

            if(flag)
            {
                flag1 = true;
                cout << i << " " << j << endl;
            }
        }
        
    }

    if(!flag1) cout <<  "No Solution." << endl;

    return 0;
}