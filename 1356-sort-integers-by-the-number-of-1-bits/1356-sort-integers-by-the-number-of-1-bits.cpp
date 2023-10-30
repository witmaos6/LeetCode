class Solution {
    typedef pair<int, int> BitPair;
public:
    vector<int> sortByBits(vector<int>& arr)
    {
        map<int, vector<int>> BitCountMap;
        for(int Num : arr)
        {
            bitset<32> Bit(Num);
            int BitCount = Bit.count();
            
            BitCountMap[BitCount].push_back(Num);
        }
        
        vector<int> Result;
        for(auto&[Bit, Nums] : BitCountMap)
        {
            sort(Nums.begin(), Nums.end());
            
            for(int Num : Nums)
            {
                Result.push_back(Num);
            }
        }
        
        return Result;
    }
};