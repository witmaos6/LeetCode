class Solution {
public:
    int minOperations(vector<int>& nums)
    {
        unordered_map<int, int> Table;
        
        for(int Num : nums)
        {
            Table[Num]++;
        }
        
        int Result = 0;
        for(auto& [Num, Freq] : Table)
        {
            if(Freq == 1)
            {
                return -1;
            }
            
            int Count = (Freq / 3) + GetDivisionThree(Freq);
            Result += Count;
        }
        return Result;
    }
private:
    int GetDivisionThree(int Num)
    {
        if(Num % 3 == 0)
        {
            return 0;
        }
        return 1;
    }
};