class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        int AllXOR = 0;
        for(int& Num : nums)
        {
            AllXOR ^= Num;
        }
        
        int Mask = 1;
        while(!(AllXOR & Mask))
        {
            Mask <<= 1;
        }
        
        int UniqueNum = 0;
        for(int& Num : nums)
        {
            if(Num & Mask)
            {
                UniqueNum ^= Num;
            }
        }
        
        return {UniqueNum, AllXOR ^ UniqueNum};
    }
};