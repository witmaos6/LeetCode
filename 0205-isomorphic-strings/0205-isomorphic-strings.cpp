class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        const int N = static_cast<int>(s.size());
        unordered_map<char, char> StoT, TtoS;
        
        for(int i = 0; i < N; i++)
        {
            char CS = s[i], CT = t[i];
            if (StoT.find(CS) == StoT.end() && TtoS.find(CT) == TtoS.end())
            {
                StoT[CS] = CT;
                TtoS[CT] = CS;
            } 
            else
            {
                if(StoT[CS] != CT || TtoS[CT] != CS)
                    return false;
            } 
        }
        
        return true;
    }
};