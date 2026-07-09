class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries)
    {
        vector<int> Union(n);
        int Num = 0;

        for(int i = 1; i < n; i++)
        {
            if(nums[i] - nums[i - 1] > maxDiff)
            {
                Num++;
            }
            Union[i] = Num;
        }

        vector<bool> Result;
        Result.reserve(n);
        for(const vector<int>& Query : queries)
        {
            Result.push_back(Union[Query[0]] == Union[Query[1]]);
        }
        return Result;
    }
};