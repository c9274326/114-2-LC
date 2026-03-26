class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Sort
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        
        // Step 2: Split
        int mid = (n + 1) / 2;
        
        vector<int> s1(temp.begin(), temp.begin() + mid); // smaller half
        vector<int> s2(temp.begin() + mid, temp.end());   // larger half
        
        // Step 3: Reverse both halves
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        
        // Step 4: Interleave
        int i = 0, j = 0;
        for(int k = 0; k < n; k++){
            if(k % 2 == 0){
                nums[k] = s1[i++];
            } else {
                nums[k] = s2[j++];
            }
        }
    }
};