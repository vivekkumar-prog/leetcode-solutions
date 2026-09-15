/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var maxPalindromes = function(s, k) {
    const n = s.length;

    // palindrome[l][r] = true if s[l...r] is a palindrome
    const palindrome = Array.from(
        { length: n },
        () => Array(n).fill(false)
    );

    // Build palindrome table
    for (let r = 0; r < n; r++) {
        for (let l = 0; l <= r; l++) {

            if (
                s[l] === s[r] &&
                (r - l <= 2 || palindrome[l + 1][r - 1])
            ) {
                palindrome[l][r] = true;
            }
        }
    }

    // dp[i] = maximum answer using first i characters
    const dp = Array(n + 1).fill(0);

    for (let r = 0; r < n; r++) {

        // Don't use a substring ending at r
        dp[r + 1] = dp[r];

        // Try every substring ending at r
        for (let l = 0; l <= r; l++) {

            // Length must be at least k
            if (r - l + 1 >= k && palindrome[l][r]) {
                dp[r + 1] = Math.max(
                    dp[r + 1],
                    dp[l] + 1
                );
            }
        }
    }

    return dp[n];
};