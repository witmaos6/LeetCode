class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        for(int i = 0; i <= N - (2 * k); i++)
        {
            bool Prev = IncreasingSubarray(nums, i, k);
            bool Post = IncreasingSubarray(nums, i + k, k);

            if(Prev && Post)
                return true;
        }
        return false;
    }

private:
    bool IncreasingSubarray(vector<int>& Nums, int i, int k)
    {
        for(int j = i; j < i + k - 1; j++)
        {
            if(Nums[j] >= Nums[j + 1])
            {
                return false;
            }
        }
        return true;
    }
};