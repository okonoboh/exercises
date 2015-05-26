public class Problem2 {
   public static void main(String[] args) {
      int i = 1;
      int j = 2;
      int temp;

      int sum = 2;
      
      do {
         temp = j;
         j = j + i;
         i = temp;

         if(j % 2 == 0) {
            sum += j;
         }
      } while(j <= 4000000);

      System.out.println(sum); // 4613732
   }
}
