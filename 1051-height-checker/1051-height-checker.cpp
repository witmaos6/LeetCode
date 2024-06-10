class Solution {
public:
    int heightChecker(vector<int>& heights)
    {
        const int N = static_cast<int>(heights.size());
        
        vector<int> SortedArr(heights.begin(), heights.end());
        sort(SortedArr.begin(), SortedArr.end());
        
        int Count = 0;
        for(int i = 0; i < N; i++)
        {
            if(heights[i] != SortedArr[i])
            {
                Count++;
            }
        }
        
        return Count;
    }
};