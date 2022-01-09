// Problem Link : https://leetcode.com/problems/greatest-common-divisor-of-strings/

#include <bits/stdc++.h>
using namespace std;

string gcdOfStrings(string str1, string str2)
{
    if (str1.size() < str2.size())
        return gcdOfStrings(str2, str1);
    if (str2.empty())
        return str1;
    if (str1.substr(0, str2.size()) != str2)
        return "";
    return gcdOfStrings(str1.substr(str2.size()), str2);
}

string gcdOfStrings(string a, string b)
{
    return (a + b == b + a) ? a.substr(0, gcd(a.length(), b.length())) : "";
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}