class Solution {
public:
    int maxFrequencyElements(vector<int>& nums)
    {
        int MaxFreq = 0;
        vector<int> Table(101);

        for(int& Num : nums)
        {
            Table[Num]++;
            MaxFreq = max(MaxFreq, Table[Num]);
        }

        int Count = 0;
        for(int& Num : Table)
        {
            if(Num == MaxFreq)
            {
                Count += Num;
            }
        }
        return Count;
    }
};