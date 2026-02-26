class Solution {
    int N = 0;
public:
    int numSteps(string s)
    {
        s = '0' + s;
        N = static_cast<int>(s.size());
        int Count = 0;

        while(!IsValid(s))
        {
            if(s.back() == '0')
            {
                DivideTwo(s);
            }
            else if(s.back() == '1')
            {
                AddOne(s);
            }
            
            Count++;
        }
        return Count;
    }

private:
    void AddOne(string& S)
    {
        S.back() = '0';
        for(int i = N - 2; i >= 0; i--)
        {
            if(S[i] == '1')
            {
                S[i] = '0';
            }
            else if(S[i] == '0')
            {
                S[i] = '1';
                break;
            }
        }
    }
    
    void DivideTwo(string& S)
    {
        for(int i = N - 1; i > 0; i--)
        {
            S[i] = S[i - 1];
        }
        S.front() = '0';
    }

    bool IsValid(string& S)
    {
        for(int i = 0; i < N - 1; i++)
        {
            if(S[i] == '1')
                return false;
        }
        return true;
    }
};