class Solution {
public:
    long long kMirror(int k, int n)
    {
        long long Sum = 0;
        for(long long Len = 1; n > 0; Len *= 10)
        {
            for(long long i = Len; n > 0 && i < Len * 10; i++)
            {
                long long P = CreatePalindrome(i, true);
                if(IsPalindrome(P, k))
                {
                    Sum += P;
                    n--;
                }
            }
            for(long long i = Len; n > 0 && i < Len * 10; i++)
            {
                long long P = CreatePalindrome(i, false);
                if(IsPalindrome(P, k))
                {
                    Sum += P;
                    n--;
                }
            }
        }
        return Sum;
    }

private:
    long long CreatePalindrome(long long Num, bool Odd)
    {
        long long X = Num;
        if(Odd)
        {
            X /= 10;
        }
        while(X > 0)
        {
            Num = Num * 10 + X % 10;
            X /= 10;
        }
        return Num;
    }

    bool IsPalindrome(long long Num, int Base)
    {
        vector<int> Digits;
        while(Num > 0)
        {
            Digits.push_back(Num % Base);
            Num /= Base;
        }
        int i = 0, j = Digits.size() - 1;
        while(i < j)
        {
            if(Digits[i++] != Digits[j--])
            {
                return false;
            }
        }
        return true;
    }
};