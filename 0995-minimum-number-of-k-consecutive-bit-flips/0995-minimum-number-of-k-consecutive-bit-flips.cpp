class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        vector<int> Flips(N);
        int Fliped = 0;
        int Result = 0;
        
        for(int i = 0; i < N; i++)
        {
            if(i >= k)
            {
                Fliped ^= Flips[i - k];
            }
            if(Fliped == nums[i])
            {
                if(i + k > N)
                {
                    return -1;
                }
                Flips[i] = 1;
                Fliped ^= 1;
                Result++;
            }
        }
        return Result;
    }
};