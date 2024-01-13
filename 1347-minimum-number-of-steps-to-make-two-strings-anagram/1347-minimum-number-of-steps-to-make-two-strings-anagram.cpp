class Solution {
public:
    int minSteps(string s, string t)
    {
        vector<int> Table(26);
        
        for(char C : s)
        {
            Table[C - 'a']++;
        }
        
        for(char C : t)
        {
            Table[C - 'a']--;
        }
        
        int NrOfReplace = 0;
        for(int Num : Table)
        {
            NrOfReplace += abs(Num);
        }
        
        return NrOfReplace / 2;
    }
};