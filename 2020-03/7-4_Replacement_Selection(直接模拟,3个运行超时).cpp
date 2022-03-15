#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1e5 + 10;

int n, m;
vector<int> ans[N];
int a[N];

//7 3
// 81 94 11 96 12 99 35

int main()
{
    cin >> n >> m;
    int used = 0;
    vector<int> tmp;
    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }

    int cnt = 0;

    for(int i = 0; i < m; i ++)
    {
        tmp.push_back(a[i]);
        used++;
    }

    int total = n;
    int i = m - 1;
    while(1)
    {   
        if(tmp.size() == 0) break;

        sort(tmp.begin(), tmp.begin() + used);
        // cout << tmp.size() <<endl;
        //  for(auto x:tmp)
        // {
        //     cout <<x << " ";
        // }
        // cout << endl;
        int j = i + 1;
        // cout << used << " " << tmp[0] << " " << a[j] << endl;
        
        total --;
        if(j < n && a[j] >= tmp[0])
        {       

            // cout << "比第一个数大" << endl;
            ans[cnt].push_back(tmp[0]);
            tmp.erase(tmp.begin());
            tmp.push_back(a[j]);
            sort(tmp.begin(), tmp.end(), greater<int>());
            i = j;
            continue;
            
        }
        else if(j < n && a[j] < tmp[0])
        {       
            // cout << "比第一个数小" << endl;
            ans[cnt].push_back(tmp[0]);
            tmp.erase(tmp.begin());
            tmp.push_back(a[j]);
            sort(tmp.begin(), tmp.end(), greater<int>());
            used --;
            // cout << "减去了 " << used << endl;;
        }   
      

        
        
        i = j;
        
        if(j >= n)
        {   
            // cout << "进入j == n" << endl;
            
            int ss = tmp.size();
            int s = min(used, ss);
            //  for(auto x: tmp)
            // {
            //     cout << x << " ";
            // }
            // cout << s;
            // cout << endl;
            for(int i = 0; i < s; i ++)
            {   
                ans[cnt].push_back(tmp[0]);
                tmp.erase(tmp.begin());
            }
            // for(auto x: tmp)
            // {
            //     cout << x << " ";
            // }
            // cout << endl;
            

            used = 0;
        }

        if(used == 0)
        {   
            used = min((int)tmp.size(), m);
            cnt ++;
        }
    }

    for(int i = 0; i < cnt; i ++)
    {
        for(int j = 0; j < ans[i].size(); j ++)
        {
            if(j != 0) cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }
    // for(auto x: ans[0])
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
    // // cout << ans[0].size();
    // cout << ans[1].size() << endl;
    // for(auto x: ans[1])
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
    // for(auto x: ans[2])
    // {
    //     cout << x << " ";
    // }

}
