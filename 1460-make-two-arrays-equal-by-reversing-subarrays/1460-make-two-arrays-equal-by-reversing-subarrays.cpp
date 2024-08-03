class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr)
    {
        vector<int> Table(1001);
        
        for(int Num : target)
        {
            Table[Num]++;
        }
        
        for(int Num : arr)
        {
            Table[Num]--;
        }
        
        for(int Freq : Table)
        {
            if(Freq != 0)
            {
                return false;
            }
        }
        
        return true;
    }
};