#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

int n, k;
unordered_map<string, vector<int>> students;


int main()
{  
   cin >> n >> k;
   for(int i = 0; i < k ; i ++)
   {
       int idx, m;
       cin >> idx >> m;
       string s;
       for(int j = 0; j < m; j ++)
       {
           cin >> s;
           students[s].push_back(idx);
       }
   } 

   for(int i = 0; i < n; i ++)
   {
       string s;
       cin >> s;    
       auto t = students[s];
       cout << s << " " << t.size();
       sort(t.begin(), t.end());
       for(int j = 0; j < t.size(); j ++)
       {
           cout << " " << t[j];
       }
       cout << endl;
   }

   return 0;
}