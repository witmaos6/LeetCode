class Solution {
public:
    string answerString(string word, int numFriends)
    {
        if(numFriends == 1)
            return word;

        const int N = static_cast<int>(word.size());
        string Result;

        for(int i = 0; i < N; i++)
        {
            int Temp = min(N - numFriends + 1, N - i);
            string Sub = word.substr(i, Temp);
            if(Sub > Result)
            {
                Result = Sub;
            }
        }
        return Result;
    }
};