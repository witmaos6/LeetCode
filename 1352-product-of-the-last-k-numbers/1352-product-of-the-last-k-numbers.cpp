class ProductOfNumbers {
    vector<int> Nums;
public:
    ProductOfNumbers()
    {
        
    }
    
    void add(int num)
    {
        Nums.push_back(num);
    }
    
    int getProduct(int k)
    {
        const int N = Nums.size();
        int Range = N - k;
        int Result = 1;
        for(int i = N - 1; i >= Range; i--)
        {
            Result *= Nums[i];
        }
        return Result;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */