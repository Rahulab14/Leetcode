

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();

        // Store dictionary words in a set for fast lookup.
        unordered_set<string> dict;

        for (string word : wordDict) {
            dict.insert(word);
        }

        // dp[i] = true if the first i characters of s
        // can be completely segmented into dictionary words.
        vector<bool> dp(n + 1, false);

        // Empty string can always be segmented.
        dp[0] = true;

        // Build the DP table from left to right.
        for (int i = 1; i <= n; i++) {

            // Try every possible previous cut position.
            for (int j = 0; j < i; j++) {

                // If the prefix before j is valid and
                // s[j..i-1] is a dictionary word,
                // then the first i characters are valid.
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

