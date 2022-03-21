#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<string>
#include<set>

using namespace std;

const int N = 30, M = 20, K = 60, digit = 110;

int n, m, k;

vector<int> product;
set<int> rset;
vector<string>tmp;
vector<vector<string>> path;
bool st[digit];
struct Product
{
    string equation;
    vector<int> reactant;

    bool operator<(const Product& t) const
    {
        int pos = equation.find('-');
        int post = t.equation.find('-');

        int mint = min(pos, post);

        return equation.substr(0, mint) < t.equation.substr(0, mint);
    }
};
unordered_map<string, vector<Product>> equations;



vector<int> getreactant(string e)
{   
    vector<int> res;
    int i = 0;
    while(i < e.size())
    {
        string s = e.substr(i, 2);
        res.push_back(stoi(s));
        i += 3;
        if(e[i] == '+') i += 2;
        else if(e[i] == '-') break;
    }

    return res;
}

void dfs(int idx)
{   
    if(idx == m)
    {
        path.push_back(tmp);

        return ;

    }

    if(idx >= m) return;

  
    int r = product[idx];
    string res = to_string(r);
    res = string(2 - res.size(), '0') + res;

    sort(equations[res].begin(), equations[res].end());
    for(int j = 0; j < equations[res].size(); j ++)
    {       
        bool flag = true;
        for(int k = 0; k < equations[res][j].reactant.size(); k ++)
        {   
            
            if(st[equations[res][j].reactant[k]] == true)
            {   
                flag = false;
                break;
            }
        }
        
        if(flag)
        {   

            tmp.push_back(equations[res][j].equation);
            for(int k = 0; k < equations[res][j].reactant.size(); k ++) st[equations[res][j].reactant[k]] = true;
            dfs(idx + 1);
            for(int k = 0; k < equations[res][j].reactant.size(); k ++) st[equations[res][j].reactant[k]] = false;
            tmp.pop_back();
        }
           
    }    


}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {   
        int r;
        cin >> r;
        rset.insert(r);
    }

    cin >> m;
    for(int i = 0; i < m; i ++)
    {   
        int p;
        cin >> p;
        product.push_back(p);
    }
    
    cin >> k;
    getchar();
    for(int i = 0; i < k; i ++)
    {
        string s;
        getline(cin, s);
        vector<int> reactant;
        reactant = getreactant(s);
        bool flag = true;
        for(int i = 0; i < reactant.size(); i ++)
        {
            if(rset.count(reactant[i]) == 0)
            {
                flag = false;
                break;
            }
        }
        if(!flag) continue;
        Product product;
        product.equation = s;
        product.reactant = reactant;
        equations[s.substr(s.size() - 2)].push_back(product);
    }

    for(int i = 0; i < m; i ++)
    {
        int r = product[i];
        string res = to_string(r);
        res = string(2 - res.size(), '0') + res;
        string e = res + " -> " + res;
        
        Product product;
        product.equation = e;
        product.reactant.push_back(r);
        equations[res].push_back(product);
    }
    dfs(0);
    
    // for(int i = 0; i < m; i ++)
    // {   
    //     int r = product[i];
    //     string res = to_string(r);
    //     res = string(1, '0') + res;

    //     sort(equations[res].begin(), equations[res].end());
    //     for(int j = 0; j < equations[res].size(); j ++)
    //     {   
    //         cout << equations[res][j].equation << endl;
    //         for(int k = 0; k < equations[res][j].reactant.size(); k ++)
    //         {           
    //             int t = equations[res][j].reactant[k];
    //             cout << equations[res][j].reactant[k] << " " ;
    
    //         }
    //         cout << endl;
    //     }   
    // }

    tmp = path[0];
    if(tmp.size() == m)
    {
        for(int i = 0; i < m; i ++)
    {
        cout << tmp[i] << endl;
    }

    }

}