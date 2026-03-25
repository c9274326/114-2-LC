class Solution {
    // 建立線段樹節點
    struct Node {
        int mn, mx, lazy;
    };
    vector<Node> tree;

    void pushup(int u) {
        tree[u].mx = max(tree[u * 2].mx, tree[u * 2 + 1].mx);
        tree[u].mn = min(tree[u * 2].mn, tree[u * 2 + 1].mn);
    }


    void apply(int u, int v) {
        tree[u].mx += v;
        tree[u].mn += v;
        tree[u].lazy += v;
    }


    void pushdown(int u) {
        if(tree[u].lazy != 0){
            apply(u * 2, tree[u].lazy);
            apply(u * 2 + 1, tree[u].lazy);
            tree[u].lazy = 0;
        }       
    }


    void modify(int u, int l, int r, int L, int R, int v) {
        if(L <= l && r <= R){
            apply(u, v);
            return;
        }

        pushdown(u);
        int mid = l + (r - l) / 2;
        if(L <= mid) modify(u * 2, l, mid, L, R, v);
        if(R > mid) modify(u * 2 + 1, mid + 1, r, L, R, v);
        pushup(u);
    }


    int query(int u, int l, int r, int target) {
        if(l == r) return l;
        pushdown(u);
        int mid = l + (r - l) / 2;

        if(tree[u * 2].mn <= target && tree[u * 2]. mx >= target){
            return query(u * 2, l, mid, target);
        }
        return query(u * 2 + 1, mid + 1, r, target);
    }

public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int now = 0;
        tree.assign(4 * (n + 1), {0, 0, 0});
        unordered_map<int, int> last;
        for(int i = 1; i <= n; i++){
            int x = nums[i - 1];
            int det = (x % 2)? -1 : 1;
            
            if(last.count(x)){
                modify(1, 0, n, last[x], n, -det);
            }else{
                now += det;
            }

            last[x] = i;

            modify(1, 0, n, i, n, det);

            int pos = query(1, 0, n, now);
            ans = max(ans, i - pos);
        }
        return ans;
    }
};