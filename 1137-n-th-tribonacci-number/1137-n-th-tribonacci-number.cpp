class Solution {
    vector<int> Memo = {0,1,1};
public:
    int tribonacci(int n)
    {
        if(n <= 2)
        {
            return Memo[n];
        }
        else
        {
            Memo.resize(n + 1);
        }
        return Recursion(n);
    }

    int Recursion(int n)
    {
        if(n <= 2)
        {
            return Memo[n];
        }
        if(Memo[n] == 0)
        {
            Memo[n] = Recursion(n - 1) + Recursion(n - 2) + Recursion(n - 3);
        }
        return Memo[n];
    }
};