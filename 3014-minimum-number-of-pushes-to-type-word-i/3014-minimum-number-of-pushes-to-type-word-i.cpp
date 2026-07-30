class Solution {
public:
    int minimumPushes(string word)
    {
        int N = word.size();
        int Sum = 0;
        int Num = 1;

        while(N > 0)
        {
            int Remain = (N >= 8) ? 8 : N;
            Sum += Num * Remain;
            N -= 8;
            Num++;
        }
        return Sum;
    }
};