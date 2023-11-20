class Solution {
    const string GarbageType = "PGM";
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel)
    {
        map<char, int> Table;
        const int N = static_cast<int>(garbage.size());
        int Result = 0;        
        for(int i = 0; i < N; i++)
        {
            Result += static_cast<int>(garbage[i].size());
            for(char C : garbage[i])
            {
                Table[C] = i;
            }
        }
        
        for(int i = 1; i < N - 1; i++)
        {
            travel[i] += travel[i - 1];
        }
       
        for(char C : GarbageType)
        {
            if(Table[C] > 0)
            {
                Result += travel[Table[C] - 1];
            }
        }
        
        return Result;
    }
};