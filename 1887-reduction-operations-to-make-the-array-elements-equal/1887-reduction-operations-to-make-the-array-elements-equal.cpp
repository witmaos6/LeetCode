class Solution {
public:
    int reductionOperations(vector<int>& nums)
    {
        map<int, int, greater<>> Tree;
        
        for(int Value : nums)
        {
            Tree[Value]++;
        }
        
        int Oper = static_cast<int>(Tree.size());
        int Min = -1;
        int Max = INT_MAX;
        int Result = 0;
        
        for(const auto& [Value, Num] : Tree)
        {
            if(Value > Min)
            {
                if(Value < Max)
                {
                    Oper--;
                    Max = Value;
                }
                Result += (Oper * Num);
            }
            else
            {
                break;
            }
        }
        
        return Result;
    }
};