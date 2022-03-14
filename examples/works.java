class Sum {
   public static void main(String [] a)
   {
      System.out.println(5);
      System.out.println(5 * 2 * 3);
      System.out.println(false && true);
   }
} 

class Test {
public int Sum(int num) {
   int sum;
   sum = 0;
   while(0 < num) {
      sum = sum + num;
      num = num - 1;
   } 
   return sum;
   }
}