class Solution {
    int N = 0;
public:
    bool rotateString(string s, string goal)
    {
        if(s.size() != goal.size())
            return false;
        
        N = static_cast<int>(s.size());
        
        for(int i = 0; i < N; ++i)
        {
            if(RotateString(s, goal, i))
                return true;
        }
        
        return false;
    }
    
private:
    bool RotateString(const string& S, const string& Goal, const int Index)
    {
        int GIndex = 0;
        for(int i = Index; i < N; ++i)
        {
            if(S[i] != Goal[GIndex])
                return false;
            
            ++GIndex;
        }
        
        for(int i = 0; i < Index; ++i)
        {
            if(S[i] != Goal[GIndex])
                return false;
            
            ++GIndex;
        }
        
        return true;
    }
};