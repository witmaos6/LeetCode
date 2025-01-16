class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2)
    {
        const int Nums1Size = static_cast<int>(nums1.size());
        const int Nums2Size = static_cast<int>(nums2.size());

        int XOR1 = 0;
        int XOR2 = 0;

        if((Nums1Size & 1) == 1)
        {
            for(int& Num : nums2)
            {
                XOR2 ^= Num;
            }
        }
        if((Nums2Size & 1) == 1)
        {
            for(int& Num : nums1)
            {
                XOR1 ^= Num;
            }
        }

        return XOR1 ^ XOR2;
    }
};