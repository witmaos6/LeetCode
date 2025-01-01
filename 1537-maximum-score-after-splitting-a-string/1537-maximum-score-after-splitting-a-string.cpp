class Solution {
public:
    int maxScore(string s)
    {
        const int N = static_cast<int>(s.size());
        int LeftZeros = (s[0] == '0') ? 1 : 0;
        int RightOnes = 0;
        for(int i = 1; i < N; i++)
        {
            if(s[i] == '1')
            {
                RightOnes++;
            }
        }

        int MaxScore = LeftZeros + RightOnes;
        for(int i = 1; i < N - 1; i++)
        {
            if(s[i] == '0')
            {
                LeftZeros++;
            }
            else if(s[i] == '1')
            {
                RightOnes--;
            }
            MaxScore = max(MaxScore, LeftZeros + RightOnes);
        }

        return MaxScore;
    }
};