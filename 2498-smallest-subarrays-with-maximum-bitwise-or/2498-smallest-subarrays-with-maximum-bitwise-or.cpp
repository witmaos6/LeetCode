class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        vector<int> LastSeen(30);
        vector<int> Result(N, 1);
        for(int i = N - 1; i >= 0; i--)
        {
            for(int Bit = 0; Bit < 30; Bit++)
            {
                if((nums[i] & (1 << Bit)) > 0)
                {
                    LastSeen[Bit] = i;
                }
                Result[i] = max(Result[i], LastSeen[Bit] - i + 1);
            }
        }
        return Result;
    }
};