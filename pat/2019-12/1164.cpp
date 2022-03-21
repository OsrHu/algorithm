#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

const int N = 26;

vector<string> letter[N];

vector<string> split(string words)
{   
    vector<string> res;
    int j = 0;
    for(int i = 0; i < words.size(); i ++)
    {   
        while(!(words[j] >=  'A' && words[j] <= 'Z'))
        {
            j ++; i ++;
        }
        if(!(words[i] >=  'A' && words[i] <= 'Z') )
        {
            string s = words.substr(j, i - j);
            res.push_back(s);
            j = i + 1;
        }
    }
    return res;
}

int main()
{
    for(int i = 0; i < N; i ++)
    {
        for(int j = 0; j < 7; j ++)
        {   
            string s;
            getline(cin, s);
            letter[i].push_back(s);
        }
    }

    string setence;
    getline(cin, setence);
    for(auto& c: setence)
    {
        if(!isalpha(c))
        {
            c = ' ';
        }
    }

    setence += " ";
    // cout << setence << endl;

    vector<string>words;

    string t;
    stringstream ssin(setence);
    
    while(ssin >> t)
    {
        words.push_back(t);
    }



    // for(int i = 0; i < words.size(); i ++)
    // {
    //     cout << words[i] << " " ;
    // }
    
    for(int i = 0; i < words.size(); i ++)
    {   
       
        string word = words[i];
        for(int j = 0; j < 7; j ++)
        {   
            string tmp;
            for(int k = 0; k < word.size(); k ++)
            {
                char alpha = word[k];
                if(k != 0) tmp += " ";
                tmp += letter[alpha - 'A'][j];
            }
            cout << tmp;
            cout << endl;
        }
        if(i != words.size() -1)cout << endl;

    }

}