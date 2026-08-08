class Solution {
public:
    vector<int> validSequence(string word1, string word2)
    {
        const int N = word1.size();
        const int M = word2.size();

        int R = M - 1;
        int C = 0;
        vector<int> Right(N);
        for(int i = N - 1; i >= 0; i--)
        {
            Right[i] = C;
            if(R >= 0 && word1[i] == word2[R])
            {
                R--;
                C++;
            }
        }

        vector<int> Result;
        bool Change = false;
        int j = 0;
        for(int i = 0; i < N && j < M; i++)
        {
            if(word1[i] == word2[j])
            {
                Result.push_back(i);
                j++;
            }
            else if(!Change && Right[i] >= M - 1 - j)
            {
                Result.push_back(i);
                j++;
                Change = true;
            }
        }
        if(j == M)
            return Result;
        
        return {};
    }
};