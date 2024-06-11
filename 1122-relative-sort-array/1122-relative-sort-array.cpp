class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
    {
        const int N = static_cast<int>(arr1.size());
        map<int, int> Table;
        for(int Num : arr1)
        {
            Table[Num]++;
        }
        
        vector<int> Result;
        Result.reserve(N);
        
        for(int Num : arr2)
        {
            if(Table.find(Num) != Table.end())
            {
                while(Table[Num] > 0)
                {
                    Table[Num]--;
                    Result.push_back(Num);
                }
                Table.erase(Num);
            }
        }
        
        for(auto& [Num, Freq] : Table)
        {
            while(Freq--)
            {
                Result.push_back(Num);
            }
        }
        return Result;
    }
};