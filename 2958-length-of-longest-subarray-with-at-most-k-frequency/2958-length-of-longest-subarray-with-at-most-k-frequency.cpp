class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        unordered_map<int, int> Freq;
        int MaxGood = 0;
        int Left = 0;
        
        for(int i = 0; i < N; i++)
        {
            Freq[nums[i]]++;
            
            while(Freq[nums[i]] > k)
            {
                Freq[nums[Left]]--;
                Left++;
            }
            
            MaxGood = max(MaxGood, i - Left + 1);
        }
        
        return MaxGood;
    }
};