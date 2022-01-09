
// Problem Link : https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/#

#include <bits/stdc++.h>
using namespace std;

// o(n^2)
int countsubarray(int array[], int n, int k)
{
    int count = 0;
    int i, j, mul;

    for (i = 0; i < n; i++)
    {
        // Counter for single element
        if (array[i] < k)
            count++;

        mul = array[i];

        for (j = i + 1; j < n; j++)
        {
            // Multiple subarray
            mul = mul * array[j];
            // If this multiple is less
            // than k, then increment
            if (mul < k)
                count++;
            else
                break;
        }
    }

    return count;
}

// o(n)

int countsubarray(int array[], int n, int k)
{
    int count = 0;
    int i, j, mul;

    for (i = 0; i < n; i++)
    {
        // Counter for single element
        if (array[i] < k)
            count++;

        mul = array[i];

        for (j = i + 1; j < n; j++)
        {
            // Multiple subarray
            mul = mul * array[j];
            // If this multiple is less
            // than k, then increment
            if (mul < k)
                count++;
            else
                break;
        }
    }

    return count;
}