class Solution {
public:
    int numSteps(string s)
    {
        reverse(s.begin(), s.end());
        s.push_back('0');
        const int N = static_cast<int>(s.size());

        int Count = 0;
        while(!IsOne(s, N))
        {
            if(s[0] == '1')
            {
                AddOne(s, N);
            }
            else
            {
                DivideTwo(s, N);
            }
            Count++;
        }

        return Count;
    }
    
private:
    void AddOne(string& S, const int N)
    {
        if(S[0] == '0')
        {
            S[0] = '1';
            return;
        }
        else if(S[0] == '1')
        {
            S[0] = '0';
        }
            
        for(int i = 1; i < N; i++)
        {
            if(S[i] == '0')
            {
                S[i] = '1';
                break;
            }
            else
            {
                S[i] = '0';
            }
        }
    }
    
    void DivideTwo(string& S, const int N)
    {
        for(int i = 1; i < N; i++)
        {
            S[i - 1] = S[i];
        }
        S.back() = '0';
    }
    
    bool IsOne(const string& S, const int N)
    {
        if(S[0] == '1')
        {
            for(int i = 1; i < N; i++)
            {
                if(S[i] == '1')
                    return false;
            }
            return true;
        }
        return false;
    }
};