class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr)
    {
        const int N = static_cast<int>(arr.size());
        sort(arr.begin(), arr.end());
        unordered_map<int, vector<int>> Table;
        int MinDiff = INT_MAX;

        for(int i = 1; i < N; i++)
        {
            int Diff = arr[i] - arr[i - 1];
            Table[Diff].push_back(i);
            MinDiff = min(MinDiff, Diff);
        }

        vector<vector<int>> Result;
        for(auto&[Diff, Indices] : Table)
        {
            if(MinDiff == Diff)
            {
                for(int& Index : Indices)
                {
                    Result.push_back({arr[Index - 1], arr[Index]});
                }
                break;
            }
        }
        return Result;
    }
};