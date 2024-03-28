class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        unordered_map<int, int> Freq;
        int MaxFreq = 0;
        int CurrGood = 0;
        int MaxGood = 0;
        int Left = 0;
        
        for(int i = 0; i < N; i++)
        {
            Freq[nums[i]]++;
            MaxFreq = max(MaxFreq, Freq[nums[i]]);
            
            while(MaxFreq > k && Left < i)
            {
                Freq[nums[Left]]--;
                Left++;
                MaxFreq = Freq[nums[i]];
                CurrGood--;
            }
            CurrGood++;
            
            MaxGood = max(MaxGood, CurrGood);
        }
        
        return MaxGood;
    }
};