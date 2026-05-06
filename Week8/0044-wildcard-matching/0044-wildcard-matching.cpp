class Solution {
public:
    bool isMatch(string s, string p) {
        // 將 std::string 轉為 C 形式的字串指標
        const char* sc = s.c_str();
        const char* pc = p.c_str();
        
        const char* star = nullptr;
        const char* ss = sc;
        
        while (*sc) {
            // 1. 如果字元匹配，或者 pattern 是 '?'，兩者同時前進
            if ((*pc == '?') || (*pc == *sc)) {
                sc++;
                pc++;
                continue;
            }

            // 2. 遇到 '*'，記錄星號位置，嘗試讓 '*' 匹配 0 個字元（先跳過星號）
            if (*pc == '*') {
                star = pc++; // 記錄星號位置，pc 移到下一個
                ss = sc;     // 記錄當前 s 的位置
                continue;
            }

            // 3. 如果當前不匹配，但之前出現過 '*'，則進行回溯
            // 讓之前的 '*' 多匹配一個 s 的字元
            if (star) {
                pc = star + 1; // pattern 回到星號的下一個位置
                sc = ++ss;     // s 從上次嘗試的下一個位置開始
                continue;
            }

            // 4. 不匹配且之前沒星號，直接判斷失敗
            return false;
        }

        // 5. 處理 pattern 末尾剩餘的 '*'
        while (*pc == '*') {
            pc++;
        }

        // 如果 pattern 也剛好結束，則匹配成功
        return !*pc;
    }
};