// Last updated: 4/8/2025, 9:40:11 PM
public class Solution {
    public bool IsPalindrome(int x) {
        var y = x.ToString().ToCharArray();
        Array.Reverse(y);
        return x.ToString() == new string(y);
    }
}