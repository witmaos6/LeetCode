class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference)
    {
        unordered_map<int, int> Table;
        int Result = 1;
        
        for(int& Num : arr)
        {
            int Prev = Num - difference;
            
            if(Table.find(Prev) != Table.end())
            {
                Table[Num] = Table[Prev] + 1;
                Result = max(Result, Table[Num]);
            }
            else
            {
                Table[Num] = 1;
            }
        }
        
        return Result;
    }
};