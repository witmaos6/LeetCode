class Solution {
public:
    int mostFrequentEven(vector<int>& nums)
    {
        map<int, int> Freq;
        
        for(int& Num : nums)
        {
            if(!(Num & 1))
            {
                Freq[Num]++;
            }
        }
        
        if(Freq.empty())
        {
            return -1;
        }
        
        int MostFreq = 0;
        int Result = 0;
        for(pair<const int, int>& E : Freq)
        {
            if(E.second > MostFreq)
            {
                Result = E.first;
                MostFreq = E.second;
            }
        }
        
        return Result;
    }
};