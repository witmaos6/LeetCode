class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        const int N = static_cast<int>(answerKey.size());
        int MaxFreq = 0;
        int NT = 0, NF = 0;
        int Left = 0;
        
        for(int Right = 0; Right < N; Right++)
        {
            char C = answerKey[Right];
            
            if(C == 'T')
            {
                NT++;
                MaxFreq = max(MaxFreq, NT);
            }
            else
            {
                NF++;
                MaxFreq = max(MaxFreq, NF);
            }
            
            if(Right - Left + 1 > MaxFreq + k)
            {
                if(answerKey[Left] == 'T')
                {
                    NT--;
                }
                else
                {
                    NF--;
                }
                Left++;
            }
        }
        
        return N - Left;
    }
};