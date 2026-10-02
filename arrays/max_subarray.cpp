#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int max_sum = INT_MIN;

        // // Brute Force
        // for (int i = 0; i < n; i++)
        // {
        //     int sum = 0;
        //     for (int j = i; j < n; j++)
        //     {
        //         sum += nums[j];
        //         max_sum = max(max_sum, sum);
        //     }
        // }

        // Optimal Approach: Kadane's Algorithm
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            max_sum = max(max_sum, sum);

            if (sum < 0)
                sum = 0;
        }

        return max_sum;
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
        auto result = sol.maxSubarray(nums);

        // Place your output code here
        cout << result << endl;
    }

    return 0;
}