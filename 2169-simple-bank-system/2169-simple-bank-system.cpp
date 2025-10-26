class Bank {
    vector<long long> Bal;
    int N = 0;

    bool Valid(int n)
    {
        return n > 0 && n <= N;
    }
public:
    Bank(vector<long long>& balance)
    {
        Bal = balance;
        N = static_cast<int>(Bal.size());
    }
    
    bool transfer(int account1, int account2, long long money)
    {
        if(!Valid(account1) || !Valid(account2) || Bal[account1 - 1] < money)
            return false;
        Bal[account1 - 1] -= money;
        Bal[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money)
    {
        if(!Valid(account))
            return false;
        Bal[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money)
    {
        if(!Valid(account) || Bal[account - 1] < money)
            return false;
        Bal[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */