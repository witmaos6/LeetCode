class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x)
    {
        vector<int> Result;

        const int N = static_cast<int>(words.size());
        for(int i = 0; i < N; i++)
        {
            bool bIsExist = false;
            for(char C : words[i])
            {
                if(C == x)
                {
                    bIsExist = true;
                    break;
                }
            }
            if(bIsExist)
            {
                Result.push_back(i);
            }
        }
        return Result;
    }
};