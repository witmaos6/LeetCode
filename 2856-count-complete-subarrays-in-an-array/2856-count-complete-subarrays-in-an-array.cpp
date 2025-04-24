class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums)
    {
        int DistinctNum = GetDistinctNum(nums);
        const int N = static_cast<int>(nums.size());
        int Count = 0;
        for(int i = 0; i < N; i++)
        {
            unordered_set<int> Table;
            for(int j = i; j < N; j++)
            {
                Table.insert(nums[j]);
                if(Table.size() == DistinctNum)
                {
                    Count += (N - j);
                    break;
                }
            }
        }
        return Count;
    }
private:
    int GetDistinctNum(vector<int>& Nums)
    {
        unordered_set<int> Table;
        for(int& Num : Nums)
        {
            Table.insert(Num);
        }
        return Table.size();
    }
};