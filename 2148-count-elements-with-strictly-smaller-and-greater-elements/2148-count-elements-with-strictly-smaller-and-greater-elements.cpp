class Solution {
public:
    int countElements(vector<int>& nums)
    {
        unordered_map<int, int> Table;
        
        int MinElement = 1e5;
        int MaxElement = -1e5;
        
        for(int& Num : nums)
        {
            Table[Num]++;
            
            MinElement = min(MinElement, Num);
            MaxElement = max(MaxElement, Num);
        }
        
        if(MinElement == MaxElement)
            return 0;
        
        return nums.size() - (Table[MinElement] + Table[MaxElement]);
    }
};