class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int res = 0;
        while (target > 1 && maxDoubles--) {
            res += 1 + target % 2;
            target /= 2;
        }
        return res + target - 1;
    }
};