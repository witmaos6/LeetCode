class Solution {
    const int Mod = 1e9 + 7;
    vector<int> PowerOfTwo;
public:
    Solution()
    {
        int Coefficient = 1;
        
        for(int i = 0; i < 22; i++)
        {
            PowerOfTwo.push_back(Coefficient);
            Coefficient <<= 1;
        }
    }
    
    int countPairs(vector<int>& deliciousness)
    {
        unordered_map<int, int> Table;
        int Count = 0;
        
        for(int& Food : deliciousness)
        {
            for(int& Power : PowerOfTwo)
            {
                int Temp = Power - Food;
                if(Temp >= 0 && Table.find(Temp) != Table.end())
                {
                    Count = (Count + Table[Temp]) % Mod;
                }
            }
            Table[Food]++;
        }
        
        return Count;
    }
};