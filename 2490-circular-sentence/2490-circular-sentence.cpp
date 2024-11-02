class Solution {
public:
    bool isCircularSentence(string sentence)
    {
        const int N = static_cast<int>(sentence.size());
        
        if(sentence.front() != sentence.back())
            return false;
        
        for(int i = 0; i < N; ++i)
        {
            if(sentence[i] == ' ')
            {
                if(sentence[i - 1] != sentence[i + 1])
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};