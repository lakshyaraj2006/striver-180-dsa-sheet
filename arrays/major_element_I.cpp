#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorElementI(vector<int> &nums)
    {
        int n = nums.size();

        // Brute Force Approach
        /*
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int temp = nums[i];
            count = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] == temp)
                count++;
            }
            if (count > n / 2)
            return nums[i];
        }
        */

        // Better Approach
        // unordered_map<int, int> freq;

        // for (int i = 0; i < n; i++)
        // {
        //     freq[nums[i]]++;
        //     if (freq[nums[i]] > n / 2)
        //         return nums[i];
        // }

        // Optimal Approach: Boyer-Moore Voting Algorithm
        int count = 0, candidate = 0;

        for (int i = 0; i < n; i++)
        {
            if (count == 0)
                candidate = nums[i];

            if (nums[i] == candidate)
                count++;
            else
                count--;
        }

        return candidate;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> nums(n);

        for (int i = 0; i < n; i++)
            cin >> nums[i];

        Solution sol;
        auto result = sol.majorElementI(nums);

        // Place your output code here
        cout << result << endl;
    }

    return 0;
}