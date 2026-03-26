class Solution {
    struct Node {
        long long v00, v10, v01, v11;

        Node() : v00(0), v10(0), v01(0), v11(0) {}
    };

    vector<Node> tree;

    inline void merge(int u) {
        int L = u * 2;
        int R = u * 2 + 1;
        
        tree[u].v00 = max(tree[L].v00 + tree[R].v00, max(tree[L].v00 + tree[R].v10, tree[L].v01 + tree[R].v00));
        tree[u].v01 = max(tree[L].v00 + tree[R].v01, max(tree[L].v00 + tree[R].v11, tree[L].v01 + tree[R].v01));
        tree[u].v10 = max(tree[L].v10 + tree[R].v10, max(tree[L].v11 + tree[R].v00, tree[L].v10 + tree[R].v00));
        tree[u].v11 = max(tree[L].v10 + tree[R].v01, max(tree[L].v11 + tree[R].v01, tree[L].v10 + tree[R].v11));
    }

    
    void build(int u, int l, int r, const vector<int>& nums) {
        if(l == r){
            tree[u].v11 = max(0, nums[l]);
            return;
        }
        int mid = l + (r - l) / 2;
        build(u * 2, l, mid, nums);
        build(u * 2 + 1 , mid + 1, r, nums);

        merge(u);
    }

    void update(int u, int l, int r, int idx, int val) {
        if(l == r){
            tree[u].v11 = max(0, val); // it is root node, so you can take nothing or val
            return;
        }
        int mid = l + (r - l) / 2;
        if(idx <= mid){
            update(u * 2, l, mid, idx, val);
        } else{
            update(u * 2 + 1, mid + 1, r, idx, val);
        }

        merge(u);
    }

public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        tree.assign(4 * n, {});

        long long ans = 0;
        const int MOD = 1e9 + 7;
        build(1, 0, n - 1, nums);
        for(const auto& q : queries){
            int pos = q[0];
            int val = q[1];
            update(1, 0, n - 1, pos, val);
            long long temp_max = max({tree[1].v00, tree[1].v01, tree[1].v10, tree[1].v11});
            ans += temp_max;
        }
        return ans % MOD;
    }
};