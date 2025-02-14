class ProductOfNumbers {
    vector<long long> Nums;
    int ZeroIndex = -1;
public:
    ProductOfNumbers()
    {
        
    }
    
    void add(int num)
    {
        if(Nums.empty() || Nums.back() == 0)
        {
            Nums.push_back(num);
        }
        else
        {
            long long Product = Nums.back() * num;
            Nums.push_back(Product);
        }
        if(Nums.back() == 0)
        {
            ZeroIndex = Nums.size() - 1;
        }
    }
    
    int getProduct(int k)
    {
        int LeftIndex = Nums.size() - k;
        if(LeftIndex <= ZeroIndex)
        {
            return 0;
        }

        if(LeftIndex == 0 || Nums[LeftIndex - 1] == 0)
        {
            return Nums.back();
        }

        return Nums.back() / Nums[LeftIndex - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */