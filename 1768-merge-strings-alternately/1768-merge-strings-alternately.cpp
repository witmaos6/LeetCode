class Solution {
public:
    string mergeAlternately(string word1, string word2)
    {
        int N = static_cast<int>(word1.size());
        int M = static_cast<int>(word2.size());

        int i = 0, j = 0;
        string MergeResult;

        while(i < N && j < M)
        {
            MergeResult += word1[i];
            MergeResult += word2[j];
            i++;
            j++;
        }

        while(i < N)
        {
            MergeResult += word1[i];
            i++;
        }
        while(j < M)
        {
            MergeResult += word2[j];
            j++;
        }

        return MergeResult;
    }
};