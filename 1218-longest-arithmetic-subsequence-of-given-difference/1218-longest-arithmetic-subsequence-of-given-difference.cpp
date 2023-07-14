class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference)
    {
        unordered_map<int, int> Table;
        const int N = static_cast<int>(arr.size());
        int Result = 1;
        
        for(int i = 0; i < N; i++)
        {
            int Prev = arr[i] - difference;
            
            if(Table.find(Prev) != Table.end())
            {
                Table[arr[i]] = Table[Prev] + 1;
                Result = max(Result, Table[arr[i]]);
            }
            else
            {
                Table[arr[i]] = 1;
            }
        }
        return Result;
    }
};