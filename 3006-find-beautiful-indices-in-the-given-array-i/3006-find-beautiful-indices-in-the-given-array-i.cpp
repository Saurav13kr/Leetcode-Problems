class Solution {
public:
    using VI = vector<int>;
    
    VI beautifulIndices(string s, string a, string b, int k, VI ok = {}) {
        auto f = [&](auto& it) {
            VI I;
            for (auto i{ 0 }; i <= (int)s.size() - (int)it.size(); ++i)
                if (s.substr(i, it.size()) == it)
                    I.push_back(i);
            return I;
        };
        auto [A, B] = make_pair(f(a), f(b));
        
        for (auto i: A) {
            auto it = lower_bound(B.begin(), B.end(), i - k);
            if (it != B.end() && abs(*it - i) <= k)
                ok.push_back(i);
        }
        return ok;
    }
};