class Solution {
public:
    int maxOperations(vector<int>& nums, int k)
    {
        unordered_map<int, int> Table;
        int Count = 0;
        
        for(int& Num : nums)
        {
            int Temp = k - Num;
            
            if(Temp > 0)
            {
                if(Table[Temp] > 0)
                {
                    Table[Temp]--;
                    Count++;
                }
                else
                {
                    Table[Num]++;
                }
            }
        }
        
        return Count;
    }
};