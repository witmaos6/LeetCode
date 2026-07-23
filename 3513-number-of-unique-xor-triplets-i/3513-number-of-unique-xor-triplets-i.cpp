class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums)
    {
        const int N = nums.size();
        if(N <= 2)
            return N;

        int Mask = 0;
        for(int& Num : nums)
        {
            Mask |= Num;
        }
        return Mask + 1;
    }
};