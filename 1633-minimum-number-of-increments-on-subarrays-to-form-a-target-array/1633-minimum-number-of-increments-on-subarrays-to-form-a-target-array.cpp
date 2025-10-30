class Solution {
public:
    int minNumberOperations(vector<int>& target)
    {
        const int N = static_cast<int>(target.size());
        int Result = target.front();

        for(int i = 1; i < N; i++)
        {
            Result += max(target[i] - target[i - 1], 0);
        }
        return Result;
    }
};