class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_seen;

        int left = 0;
        int max_len = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];

            if (last_seen.find(c) != last_seen.end()) {
                left = max(left, last_seen[c] + 1);
            }

            last_seen[c] = right;

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};

