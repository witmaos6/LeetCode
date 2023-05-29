class RangeFreqQuery
{
    unordered_map<int, vector<int>> IndexTable;
public:
    RangeFreqQuery(vector<int>& arr)
    {
        int N = static_cast<int>(arr.size());
        
        for(int i = 0; i < N; i++)
        {
            IndexTable[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value)
    {
        if(IndexTable.find(value) == IndexTable.end())
        {
            return 0;
        }

        vector<int>& FindArr = IndexTable[value];
        auto Begin = FindArr.begin();
        auto End = FindArr.end();
        
        int LeftIndex = lower_bound(Begin, End, left) - Begin;
        int RightIndex = upper_bound(Begin, End, right) - Begin;
        
        return RightIndex - LeftIndex;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */