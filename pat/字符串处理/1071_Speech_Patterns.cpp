#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

int main()
{
    string line;
    getline(cin, line);

    for(char& c: line):
        {
            if(isalpha)
        }

    for(int i = 0; i < line.length(); i ++)
    {
        line[i] = tolower(line[i]);
    }

    unordered_map<string, int> um;
    int maxn = -1;
    string ans, tmp;
    line += " ";
    for(int i = 0; i < line.length(); i ++)
    {   
        if(isalpha(line[i]) || isdigit(line[i]))
        {
            tmp += line[i];
        }
        else if(tmp.length() != 0)
        {   

            um[tmp] ++;

            if(um[tmp] > maxn)
            {
                maxn = um[tmp];
                ans = tmp;
            }else if(um[tmp] == maxn && tmp < ans)
            {
                ans = tmp;
            }
             tmp.clear();
        }

       
    }

    printf("%s %d", ans.c_str(), maxn);



}