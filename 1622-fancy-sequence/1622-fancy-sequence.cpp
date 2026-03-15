class Fancy {
    const int Mod = 1e9 + 7;
    vector<long long> Val;
    long long A;
    long long B;
    long long ModPow(long long X, long long Y, long long Mod)
    {
        long long Result = 1;
        X %= Mod;
        while(Y > 0)
        {
            if(Y % 2 == 1)
            {
                Result = (Result * X) % Mod;
            }
            Y /= 2;
            X = (X * X) % Mod;
        }
        return Result;
    }
public:
    Fancy() : A(1), B(0) {}
    
    void append(int val)
    {
        long long X = (val - B + Mod) % Mod;
        Val.push_back((X * ModPow(A, Mod - 2, Mod)) % Mod);
    }
    
    void addAll(int inc)
    {
        B = (B + inc) % Mod;
    }
    
    void multAll(int m)
    {
        A = (A * m) % Mod;
        B = (B * m) % Mod;
    }
    
    int getIndex(int idx)
    {
        if(idx >= Val.size())
            return -1;
        
        return (A * Val[idx] + B) % Mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */