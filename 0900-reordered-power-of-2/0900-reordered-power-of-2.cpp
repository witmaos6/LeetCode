class Solution {
public:
    bool reorderedPowerOf2(int n)
    {
        string SortedN = to_string(n);
        sort(SortedN.begin(), SortedN.end());
        for (int i = 0; i < 30; i++)
        {
            string Comparison = to_string(1 << i);
            sort(Comparison.begin(), Comparison.end());
            if(SortedN == Comparison)
            {
                return true;
            }
        }
        return false;
    }
};