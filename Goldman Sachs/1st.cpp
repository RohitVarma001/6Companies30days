#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> Anagrams(vector<string> &string_list)
{
    //code here
    int n = string_list.size();
    vector<vector<string>> ans;
    unordered_map<string, bool> m;
    vector<string> sot;
    for (int i = 0; i < n; i++)
    {
        string s = string_list[i];
        sort(s.begin(), s.end());
        sot.push_back(s);
    }
    for (int i = 0; i < n; i++)
    {
        string s = sot[i];
        vector<string> temp;
        if (m.find(s) == m.end())
        {
            temp.push_back(string_list[i]);
            for (int j = i + 1; j < n; j++)
            {
                if (s == sot[j])
                    temp.push_back(string_list[j]);
            }
            m[s] = true;
            ans.push_back(temp);
        }
    }
    return ans;
}

// Problem Link: https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/#