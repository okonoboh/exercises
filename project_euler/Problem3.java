public class Problem3 {
   public static boolean isPalindrome(String s) {
      int strLen = s.length() - 1;
      for(int i = 0, j = strLen; i < j; ++i, --j) {
         if(s.charAt(i) != s.charAt(j)) {
            return false;
         }
      }

      return true;
   }

   public static void main(String[] args) {
      int k;
      int max = 0;
      for(int i = 100; i < 1000; ++i) {
         for(int j = 100; j < 1000; ++j) {
            k = i * j;
            if(isPalindrome(String.valueOf(k)) && k > max) {
               max = k;
            }
         }
      }

      System.out.println(max); // 906609
   }
}
