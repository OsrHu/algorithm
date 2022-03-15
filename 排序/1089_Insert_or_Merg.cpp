#include<iostream>
#include<algorithm>

using namespace std;

const int N = 110;

int n;
int a[N], b[N];

bool check()
{
    for (int i = 0; i < n; i ++ )
        if (a[i] != b[i])
            return false;
    return true;
}



int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }

    for(int i = 0; i < n; i ++)
    {
        cin >> b[i];
    }

    int k = 0;
    int kb = k;
    while(b[k] <= b[k + 1]) k ++;

    bool flag = true;
    for(int i = k + 1; i < n; i ++)
    {
        if(a[i]!= b[i])
        {
            flag = false;
            break;
        }
    }


    if(flag)
    {
        cout << "Insertion Sort\n";
        sort(b, b + k + 2);
        cout << b[0];

        for(int i = 1; i < n; i ++)
        {
            cout << " " << b[i];
        }

    }
    else
    {   
        int t = 1;
        while(true)
        {
            bool same = check();

            int len = 1 << t;
            for(int i = 0; i < n; i += len)
            {
                sort(a + i, a + min(n, i + len));
            }

            if(same) break;
            t ++;

        }

        cout << "Merge Sort\n";
        cout << a[0];
        for (int i = 1; i < n; i ++ ) cout << ' '<< a[i];
        cout << endl;


    }
}