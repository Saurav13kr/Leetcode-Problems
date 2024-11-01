class Solution {
    public String makeFancyString(String s) {
        var counter = 1;
        var lastChar = s.charAt(0);
        var result = new StringBuilder(String.valueOf(lastChar));
        
        for (var i = 1; i < s.length(); i++) 
        {
            var currentChar = s.charAt(i);
            if (currentChar == lastChar) {
                counter++;
            } 
            else 
            {
                counter = 1;
                lastChar = currentChar;
            }
            if (counter <= 2) {
                result.append(s.charAt(i));
            }
        }
        return result.toString();
    }
}
