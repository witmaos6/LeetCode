class Solution {
public:
    int idealArrays(int n, int maxValue) {
        C_n_k(kMaxVal + 1, kMaxVal + 1); // Precompute combinations

        // Imagine we build strictly asceding ideal array
        // Compute combinations per length and expand to n
        long long res = 0;
        int len_lim = min<int>(precalc.uniq_len_2_acc_last_val_2_count.size(), n + 1);
        for (int len = 0; len < len_lim; ++len) // length of asceding ideal array with uniq elems
            res += expand_uniq(len, n) * precalc.uniq_len_2_acc_last_val_2_count[len][maxValue];
        return res % kMod;
    }

private:
    static constexpr long long kMod = 1e9 + 7;
    static constexpr long long kMaxVal = 1e4;

    static vector<long long> fact, invf;

    template<int MaxV> // Counts unique divisible sequences
    struct PreCalc {
        vector<array<long long, MaxV + 1>> uniq_len_2_acc_last_val_2_count;

        PreCalc(int target_len) {
            uniq_len_2_acc_last_val_2_count.reserve(15);
            dfs(target_len, MaxV);
            // Accumulate to prefix sums
            for (auto& acc_count : uniq_len_2_acc_last_val_2_count)
                for (int i = 1; i < acc_count.size(); ++i)
                    acc_count[i] = (acc_count[i] + acc_count[i - 1]) % kMod;
        }

        void dfs(int target_len, int max_val, int prefix_len = 0, int last_val = -1) {
            int add = prefix_len ? last_val : 1;
            int beg = add + (prefix_len ? last_val : 0);
            int len = prefix_len + 1;
            for (int v = beg; v <= max_val; v += add) {
                if (uniq_len_2_acc_last_val_2_count.size() <= len)
                    uniq_len_2_acc_last_val_2_count.resize(len + 1);
                ++uniq_len_2_acc_last_val_2_count[len][v];
                if (len < target_len)
                    dfs(target_len, max_val, len, v);
            }
        }
    };

    static PreCalc<kMaxVal> precalc;

    // Calculate ways to expand unique sequence to length n using stars and bars
    long long expand_uniq(int uniq_iarr_len, int expand_size) {
        if (uniq_iarr_len == 0) return 0;
        return C_n_k(expand_size - 1, uniq_iarr_len - 1);
    }

    long long C_n_k(int N, int k) {
        fact.reserve(N + 1);
        invf.reserve(N + 1);
        while (fact.size() < N + 1) {
            fact.push_back(fact.back() * fact.size() % kMod);
            invf.push_back(qpow(fact.back(), kMod - 2)); // Inverse using little Fermat theorem
        }
        return fact[N] * invf[k] % kMod * invf[N - k] % kMod;
    }

    long long qpow(long long b, long long p) {
        long long res = 1;
        for (; p > 0; p >>= 1, b = b * b % kMod)
            if (p & 1)
                res = res * b % kMod;
        return res;
    }
};

vector<long long> Solution::fact(1, 1);
vector<long long> Solution::invf(1, 1);

Solution::PreCalc<Solution::kMaxVal> Solution::precalc(Solution::kMaxVal);