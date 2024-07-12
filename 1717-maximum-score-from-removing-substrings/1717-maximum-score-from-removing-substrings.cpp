class Solution {
public:
    int maximumGain(string s, int x, int y)
    {
        int TotalScore = 0;
        string HighScorePair = x > y ? "ab" : "ba";
        string LowScorePair = HighScorePair == "ab" ? "ba" : "ab";

        const int N = static_cast<int>(s.size());
        string AfterFirstPass = RemoveSubstring(s, HighScorePair);
        int FirstSize = static_cast<int>(AfterFirstPass.size());
        int RemovedPairsCount = (N - FirstSize) / 2;

        TotalScore += RemovedPairsCount * max(x, y);

        string AfterSecondPass = RemoveSubstring(AfterFirstPass, LowScorePair);
        int SecondSize = static_cast<int>(AfterSecondPass.size());
        RemovedPairsCount = (FirstSize - SecondSize) / 2;

        TotalScore += RemovedPairsCount * min(x, y);

        return TotalScore;
    }

private:
    string RemoveSubstring(const string& Input, const string& TargetPair)
    {
        stack<char> St;
        
        for (char C : Input)
        {
            if (C == TargetPair[1] && !St.empty() && St.top() == TargetPair[0])
            {
                St.pop();
            }
            else
            {
                St.push(C);
            }
        }

        string RemainingChars;
        while (!St.empty())
        {
            RemainingChars += St.top();
            St.pop();
        }
        reverse(RemainingChars.begin(), RemainingChars.end());
        return RemainingChars;
    }
};