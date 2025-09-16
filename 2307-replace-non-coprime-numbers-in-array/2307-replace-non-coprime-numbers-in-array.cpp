class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        vector<int> Result;
        for(int i = 0; i < N; i++)
        {
            if(Result.empty() || GCD(Result.back(), nums[i]) <= 1)
            {
                Result.push_back(nums[i]);
            }
            else
            {
                int Back = Result.back();
                Result.pop_back();

                int CurrLCM = LCM(Back, nums[i]);
                Result.push_back(CurrLCM);

                while(Result.size() >= 2)
                {
                    const int M = static_cast<int>(Result.size());
                    if(GCD(Result[M - 1], Result[M - 2]) > 1)
                    {
                        int Num1 = Result[M - 1];
                        int Num2 = Result[M - 2];
                        Result.pop_back();
                        Result.pop_back();
                        int CurrLCM = LCM(Num1, Num2);
                        Result.push_back(CurrLCM);
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return Result;
    }

private:
    long long LCM(int a, int b)
    {
        long long Temp = 1;
        return Temp * a * b / GCD(a, b);
    }

    int GCD(int a, int b)
    {
        if(b > a)
        {
            return GCD(b, a);
        }
        while(b != 0)
        {
            int r = a % b;
            a = b;
            b = r;
        }
	    return a;
    }
};