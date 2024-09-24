class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2)
    {
        unordered_map<string, int> Table;
        
        for(int Num : arr1)
        {
            string Str = to_string(Num);
            string Prefix;
            
            for(char C : Str)
            {
                Prefix += C;
                Table[Prefix]++;
            }
        }
        
        int MaxCount = 0;
        for(int Num : arr2)
        {
            string Str = to_string(Num);
            string Prefix;
            int Count = 0;
            
            for(char C : Str)
            {
                Prefix += C;
                Count++;
                
                if(Table.find(Prefix) != Table.end())
                {
                    MaxCount = max(MaxCount, Count);
                }
            }
        }
        
        return MaxCount;
    }
};