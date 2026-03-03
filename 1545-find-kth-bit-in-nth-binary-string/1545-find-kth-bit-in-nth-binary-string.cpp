class Solution {
public:
    char findKthBit(int n, int k)
    {
        if(n == 1)
            return '0';

        int L = (1 << n) - 1;
        int Mid = L / 2 + 1;

        if(k == Mid)
            return '1';

        if(k < Mid)
            return findKthBit(n - 1, k);

        return findKthBit(n - 1, L - k + 1) == '0' ? '1' : '0';
    }
};