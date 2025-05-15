class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups)
    {
        vector<string> Result = {words[0]};
        const int N = static_cast<int>(groups.size());
        for(int i = 1; i < N; i++)
        {
            if(groups[i] != groups[i - 1])
            {
                Result.push_back(words[i]);
            }
        }
        return Result;
    }
};