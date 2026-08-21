class Solution {
public:
    using ll = long long;

    ll gcdll(ll a, ll b) {
        return std::gcd(a, b);
    }

    ll lcmLimited(ll a, ll b, ll limit) {
        ll g = gcdll(a, b);
        
        if (a / g > limit / b)
            return limit + 1;

        ll res = (a / g) * b;

        if (res > limit)
            return limit + 1;

        return res;
    }

    ll countMultiples(ll x, const vector<int>& coins) {
        int n = coins.size();
        ll ans = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            ll lcm = 1;
            int bits = 0;
            bool valid = true;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    lcm = lcmLimited(lcm, coins[i], x);

                    if (lcm > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
                continue;

            ll cnt = x / lcm;

            if (bits % 2 == 1)
                ans += cnt;
            else
                ans -= cnt;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());

        vector<int> filtered;

        for (int c : coins) {
            bool redundant = false;

            for (int d : filtered) {
                if (c % d == 0) {
                    redundant = true;
                    break;
                }
            }

            if (!redundant)
                filtered.push_back(c);
        }

        ll lo = 1;
        ll hi = 1LL * filtered[0] * k;

        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;

            if (countMultiples(mid, filtered) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};
