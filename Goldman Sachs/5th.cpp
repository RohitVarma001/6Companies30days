// Problem Link: https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/#

#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull getNthUglyNo(int n)
{
    // code here
    priority_queue<ull, vector<ull>, greater<ull>> pq;
    pq.push(1);
    set<ull> s;
    s.insert(1);
    if (n == 1)
        return 1;
    int i = 1;
    while (i < n)
    {
        ull x = pq.top();
        pq.pop();
        s.erase(x);
        if (s.find(x * 2) == s.end())
            pq.push(x * 2), s.insert(x * 2);
        if (s.find(x * 3) == s.end())
            pq.push(x * 3), s.insert(x * 3);
        if (s.find(x * 5) == s.end())
            pq.push(x * 5), s.insert(x * 5);
        i++;
    }
    return pq.top();
}

//-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

int maxDivide(int a, int b)
{
    while (a % b == 0)
        a = a / b;

    return a;
}

// Function to check if a number is ugly or not
int isUgly(int no)
{
    no = maxDivide(no, 2);
    no = maxDivide(no, 3);
    no = maxDivide(no, 5);

    return (no == 1) ? 1 : 0;
}

// Function to get the nth ugly number
int getNthUglyNo1(int n)
{
    int i = 1;

    // Ugly number count
    int count = 1;

    // Check for all integers until ugly
    // count becomes n
    while (n > count)
    {
        i++;
        if (isUgly(i))
            count++;
    }
    return i;
}

//-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

unsigned getNthUglyNo2(unsigned n)
{
    // To store ugly numbers
    unsigned ugly[n];
    unsigned i2 = 0, i3 = 0, i5 = 0;
    unsigned next_multiple_of_2 = 2;
    unsigned next_multiple_of_3 = 3;
    unsigned next_multiple_of_5 = 5;
    unsigned next_ugly_no = 1;

    ugly[0] = 1;
    for (int i = 1; i < n; i++)
    {
        next_ugly_no = min(
            next_multiple_of_2,
            min(next_multiple_of_3, next_multiple_of_5));
        ugly[i] = next_ugly_no;
        if (next_ugly_no == next_multiple_of_2)
        {
            i2 = i2 + 1;
            next_multiple_of_2 = ugly[i2] * 2;
        }
        if (next_ugly_no == next_multiple_of_3)
        {
            i3 = i3 + 1;
            next_multiple_of_3 = ugly[i3] * 3;
        }
        if (next_ugly_no == next_multiple_of_5)
        {
            i5 = i5 + 1;
            next_multiple_of_5 = ugly[i5] * 5;
        }
    }

    // End of for loop (i=1; i<n; i++)
    return next_ugly_no;
}
//-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

int nthUglyNumber3(int n)
{
    // Base cases...
    if (n == 1 or n == 2 or n == 3 or n == 4 or n == 5)
        return n;

    set<long long int> s;
    s.insert(1);
    n--;

    while (n)
    {
        auto it = s.begin();

        // Get the beginning element of the set
        long long int x = *it;

        // Deleting the ith element
        s.erase(it);

        // Inserting all the other options
        s.insert(x * 2);
        s.insert(x * 3);
        s.insert(x * 5);
        n--;
    }

    // The top of the set represents the nth ugly number
    return *s.begin();
}

// --------------------------------------------------------------------------

int nthUglyNumber4(int n)
{

    int pow[40] = {1};

    // stored powers of 2 from
    // pow(2,0) to pow(2,30)
    for (int i = 1; i <= 30; ++i)
        pow[i] = pow[i - 1] * 2;

    // Initialized low and high
    int l = 1, r = 2147483647;

    int ans = -1;

    // Applying Binary Search
    while (l <= r)
    {

        // Found mid
        int mid = l + ((r - l) / 2);

        // cnt stores total numbers of ugly
        // number less than mid
        int cnt = 0;

        // Iterate from 1 to mid
        for (long long i = 1; i <= mid; i *= 5)

        {
            // Possible powers of i less than mid is i
            for (long long j = 1; j * i <= mid; j *= 3)

            {
                // possible powers of 3 and 5 such that
                // their product is less than mid

                // using the power array of 2 (pow) we are
                // trying to find the max power of 2 such
                // that i*J*power of 2 is less than mid

                cnt += upper_bound(pow, pow + 31,
                                   mid / (i * j)) -
                       pow;
            }
        }

        // If total numbers of ugly number
        // less than equal
        // to mid is less than n we update l
        if (cnt < n)
            l = mid + 1;

        // If total numbers of ugly number
        // less than qual to
        // mid is greater than n we update
        // r and ans simultaneously.
        else
            r = mid - 1, ans = mid;
    }

    return ans;
}