// Problem Link: https://practice.geeksforgeeks.org/problems/run-length-encoding/1/

#include <bits/stdc++.h>
using namespace std;

// o(n)
string encode(string s)
{
    // Your code here
    int n = s.size();
    string ans = "";
    for (int i = 0; i < n - 1; i++)
    {
        int c = 1;
        while (s[i] == s[i + 1])
            c++, i++;
        ans = ans + s[i] + to_string(c);
    }
    if (s[n - 2] != s[n - 1])
        ans = ans + s[n - 1] + "1";
    return ans;
}

// o(n)

void printRLE(string str)
{
    int n = str.length();
    for (int i = 0; i < n; i++)
    {

        // Count occurrences of current character
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1])
        {
            count++;
            i++;
        }

        // Print character and its count
        cout << str[i] << count;
    }
}
