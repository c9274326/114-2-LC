class Solution {
    vector<int> prefix;
    mt19937 gen;
    uniform_int_distribution<> dis;
public:
    Solution(int N, vector<int> blacklist): dis(0, N - int(blacklist.size()) - 1) {
        sort(blacklist.begin(), blacklist.end());
        for(int i = 0; i < blacklist.size(); i++) {
            prefix.push_back(blacklist[i] - i);
        }
        prefix.push_back(N - blacklist.size());
    }
    int pick() {
        int idx = dis(gen);
        return idx + (upper_bound(prefix.begin(), prefix.end(), idx) - prefix.begin());
    }
};
