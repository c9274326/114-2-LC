class Solution {
public:
    using ll = long long;

    int minimumPairRemoval(vector<int>& nums) {
        using ll = long long;
        if(nums.size() <= 1)
            return 0;
        vector<ll> arr(nums.begin(), nums.end());
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        int sorted = 0;
        for(int i = 1; i < nums.size(); i++){
            pq.emplace(arr[i - 1]+arr[i], i - 1);
            if(arr[i - 1] <= arr[i])
                sorted++;
        }
        if(sorted == nums.size() - 1){
            return 0;
        }
        vector<int> prev(nums.size()), next(nums.size());
        for(int i = 0; i < nums.size(); i++){
            prev[i] = i - 1;
            next[i] = i + 1;
        }
        vector<bool> removed(nums.size(), false);
        int remain = nums.size();
        while(remain > 1){
            auto [sum, left] = pq.top();
            pq.pop();

            int right = next[left];

            if(right >= nums.size() || removed[left] || removed[right]
                || arr[left] + arr[right] != sum){
                continue;
            }
            int pre = prev[left];
            int nxt = next[right];
            if(pre != -1 && arr[pre] <= arr[left]) sorted--;
            if(arr[left] <= arr[right]) sorted--;
            if(nxt != nums.size() && arr[right] <= arr[nxt]) sorted--;

            arr[left] = arr[left] + arr[right];
            removed[right] = true;
            remain--;

            if(pre == -1){
                prev[left] = -1;
            }else{
                pq.emplace(arr[left] + arr[pre], pre);
                if(arr[pre] <= arr[left]) sorted++;
            }
            
            if(nxt == nums.size()){
                next[left] = nums.size();
            }else{
                prev[nxt] = left;
                next[left] = nxt;
                pq.emplace(arr[left] + arr[nxt], left);
                if(arr[left] <= arr[nxt]) sorted++;
            }
            if(sorted == remain - 1)
                return nums.size() - remain;
        }
        return nums.size();
    }
};
