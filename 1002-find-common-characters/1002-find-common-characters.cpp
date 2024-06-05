class Solution {
public:
    vector<string> commonChars(vector<string>& words)
    {
        const int N = static_cast<int>(words.size());
        vector<int> Table(26, INT_MAX);
        
        for(string& Word : words)
        {
            vector<int> WordTable(26);
            for(char C : Word)
            {
                WordTable[C - 'a']++;
            }
            
            for(int i = 0; i < 26; i++)
            {
                Table[i] = min(Table[i], WordTable[i]);
            }
        }
        
        vector<string> Result;
        for(int i = 0; i < 26; i++)
        {
            for(int j = 0; j < Table[i]; j++)
            {
                string Temp = string(1, i + 'a');
                Result.push_back(Temp);
            }
        }
        
        return Result;
    }
};