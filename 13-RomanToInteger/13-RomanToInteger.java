// Last updated: 7/8/2025, 11:58:46 PM
class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> map = new HashMap <Character, Integer>();
		map.put('I', 1);
		map.put('V', 5);
		map.put('X',10);
		map.put('L',50);
		map.put('C',100);
		map.put('D',500);
		map.put('M',1000);
		
		int result = 0;
		for (int i=0; i<s.length(); i++) {
			if (i == s.length()-1){
				result += map.get(s.charAt(i));
				break;
			}
			if (map.get(s.charAt(i)) < map.get(s.charAt(i+1))){
				result -= map.get(s.charAt(i));
			} else {
				result += map.get(s.charAt(i));
			}
		}
		return result;
    }
}