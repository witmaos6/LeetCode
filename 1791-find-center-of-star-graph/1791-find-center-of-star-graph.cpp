class Solution {
public:
    int findCenter(vector<vector<int>>& edges)
    {
        unordered_set<int> Table;
        for(vector<int>& Edge : edges)
        {
            for(int Num : Edge)
            {
                if(Table.find(Num) != Table.end())
                {
                    return Num;
                }
                Table.insert(Num);
            }
        }
        
        return -1;
    }
};