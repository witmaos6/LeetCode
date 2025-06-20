class Solution {
public:
    int maxDistance(string s, int k)
    {
        unordered_map<char, int> Table = {{'N', 0},{'S', 0},{'E', 0},{'W', 0}};
        
        int Result = 0;
        int i = 0;
        for(char& C : s)
        {
            Table[C]++;

            int X = abs(Table['N'] - Table['S']);
            int Y = abs(Table['E'] - Table['W']);
            int MD = X + Y;
            int Distance = MD + min(2 * k, i + 1 - MD);
            Result = max(Result, Distance);
            i++;
        }
        return Result;
    }
};