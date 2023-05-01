class Solution {
public:
    int mostFrequentEven(vector<int>& nums)
    {
        vector<int> Freq(50001);
        
        for(int& Num : nums)
        {
            if(!(Num & 1))
            {
                Freq[Num >> 1]++;
            }
        }
        
        int MostFreq = 0;
        int MostFreqElement = -1;
        
        for(int i = 0; i <= 50000; i++)
        {
            if(Freq[i] > MostFreq)
            {
                MostFreq = Freq[i];
                MostFreqElement = i << 1;
            }
        }
        
        return MostFreqElement;
    }
};