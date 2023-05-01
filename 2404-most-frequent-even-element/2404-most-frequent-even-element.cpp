class Solution {
public:
    int mostFrequentEven(vector<int>& nums)
    {
        vector<int> Freq(50001);
        int MostFreq = 0;
        int MostFreqElement = -1;
        
        for(int& Num : nums)
        {
            if(!(Num & 1))
            {
                int Temp = ++Freq[Num >> 1];
                if(MostFreq < Temp)
                {
                    MostFreq = Temp;
                    MostFreqElement = Num;
                }
                else if(MostFreq == Temp)
                {
                    MostFreqElement = min(MostFreqElement, Num);
                }
            }
        }
        
        return MostFreqElement;
    }
};