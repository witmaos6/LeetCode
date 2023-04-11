class Solution {
public:
    string oddString(vector<string>& words)
    {
        int RowSize = static_cast<int>(words.size());
        int ColSize = static_cast<int>(words[0].size());
        
        
        for(int col = 1; col < ColSize; col++)
        {
            vector<vector<int>> Temp;
            
            for(int row = 0; row < RowSize; row++)
            {
                int CurrValue = words[row][col] - words[row][col - 1];
                
                if(Temp.empty() || Temp.front()[0] != CurrValue)
                {
                    Temp.push_back({CurrValue, 1, row});
                }
                else
                {
                    Temp.front()[1]++;
                }
            }
            
            for(vector<int>& Value : Temp)
            {
                if(Value[1] == 1)
                {
                    return words[Value[2]];
                }
            }
        }
        
        return words[0];
    }
};