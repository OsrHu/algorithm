#include<iostream>
#include<cstring>
#include<algorithm>
#include<deque>
#include<unordered_set>
#include<vector>

using namespace std;

int n, k;

int main()
{
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];

    while(k --)
    {       
        deque<int> q;
        vector<int> tmp(n);
        // unordered_set<int> inserted;
        for(int i = 0; i < n; i ++)
        {
            cin >> tmp[i];
        }

        for(int i = 0, j = 0; i < n; i ++)
        {   
            q.push_back(a[i]);

            while(q.size() && (q.front() == tmp[j] || q.back() == tmp[j]) )
            {
                if(q.front() == tmp[j])
                {
                    q.pop_front();
                    j ++;
                }
                else if(q.back() == tmp[j])
                {
                    q.pop_back();
                    j ++;
                }
            }
        }
        if(q.size() == 0) cout << "yes" << endl;
        else cout << "no" << endl;
        
    }
}