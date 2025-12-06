class Solution {
public:
    int countPartitions(vector<int>& nums, int k)
    {
        const int Mod = 1e9 + 7;
        const int N = static_cast<int>(nums.size());
        long long Result = 0;
        multiset<int> Table;
        vector<int> Sum(N + 2);
        Sum[1] = 1;

        int L = 0;
        for(int R = 0; R < N; R++)
        {
            int X = nums[R];
            Table.insert(X);

            while(*Table.rbegin() - *Table.begin() > k)
            {
                auto It = Table.lower_bound(nums[L]);
                L++;
                Table.erase(It);
            }

            Result = (Mod + Sum[R + 1] - Sum[L]) % Mod;
            Sum[R + 2] = (Sum[R + 1] + Result) % Mod;
        }
        return Result;
    }
};