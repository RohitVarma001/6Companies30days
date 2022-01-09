#include <bits/stdc++.h>
using namespace std;
bool canPair(vector<int> nums, int k)
{
    // Code here.
    unordered_map<int, int> m;
    for (auto i : nums)
        m[((i % k) + k) % k]++;
    int n = nums.size();
    if (n & 1)
        return 0;
    for (int i = 0; i < n; i++)
    {
        int x = ((nums[i] % k) + k) % k;
        if (x == 0)
        {
            if (m[x] % 2 != 0)
                return 0;
        }
        else if (m[x] != m[k - x])
            return 0;
    }
    return 1;
}