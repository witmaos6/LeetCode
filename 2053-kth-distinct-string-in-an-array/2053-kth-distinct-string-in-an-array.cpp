class Solution {
public:
    string kthDistinct(vector<string>& arr, int k)
    {
        const int NotDistinct = -1;
        const int N = static_cast<int>(arr.size());
        unordered_map<string, int> Table;
        
        for(int i = 0; i < N; i++)
        {
            if(Table.find(arr[i]) != Table.end())
            {
                Table[arr[i]] = NotDistinct;
            }
            else
            {
                Table[arr[i]] = i;
            }
        }
        
        vector<int> ResultIndex;
        for(auto&[Str, Index] : Table)
        {
            if(Index != NotDistinct)
            {
                ResultIndex.push_back(Index);
            }
        }
        
        sort(ResultIndex.begin(), ResultIndex.end());
        
        if(k > ResultIndex.size())
        {
            return "";
        }
        return arr[ResultIndex[k - 1]];
    }
};