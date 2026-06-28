class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr)
    {
        sort(arr.begin(), arr.end());
        
        int Prev = 0;
        for(int Num : arr)
        {
            if(Num - Prev >= 2)
            {
                Prev = Prev + 1;
            }
            else
            {
                Prev = Num;
            }
        }
        return Prev;
    }
};