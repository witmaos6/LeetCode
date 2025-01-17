class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived)
    {
        int XOR = 0;
        for(int& Num : derived)
        {
            XOR ^= Num;
        }
        return XOR == 0;
    }
};