class Solution {
    public boolean isPalindrome(String s) {
        String str = "";
        for (char c : s.toCharArray()) {
            if (Character.isLetterOrDigit(c)) {
                str += Character.toLowerCase(c);
            }
        }
        String rev = new StringBuilder(str).reverse().toString();
        return str.equals(rev);
    }
}