class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        
        vector<int> Memo(N + 1);
        Memo[0] = 1;
        int Nice = 0;
        int OddCount = 0;
        for(int Num : nums)
        {
            OddCount += (Num & 1);
            if(OddCount - k >= 0)
            {
                Nice += Memo[OddCount - k];
            }
            Memo[OddCount]++;
        }
        return Nice;
    }
};