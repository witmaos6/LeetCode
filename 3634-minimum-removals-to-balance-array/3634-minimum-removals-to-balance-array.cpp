class Solution {
public:
    int minRemoval(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        if(N == 1)
            return 0;

        sort(nums.begin(), nums.end());
        int MaxLen = 1;
        int L = 0;

        for(int i = 0; i < N; i++)
        {
            while((long long)nums[i] > (long long)nums[L] * k)
            {
                L++;
            }
            MaxLen = max(MaxLen, i - L + 1);
        }
        return N - MaxLen;
    }
};