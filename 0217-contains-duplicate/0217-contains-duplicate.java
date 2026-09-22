class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> l1 = new HashSet<>();
        for (int num : nums) {
            l1.add(num);
        }
        if (nums.length == l1.size()) {
            return false;
        } else {
            return true;
        }
    }
}