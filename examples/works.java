class Sum {
   public static void main(String [] a)
   {
      System.out.println(new Test().Sum(100 + 1, 1));
   }
} 

class Test {
public int Sum(int a, int num) {
   int sum;
   sum = 0;
   while(0 < num) 
   {
      sum = sum + num;
      while(0 < num)
      {
         sum = sum - num;
      }
   } 
   return sum;
   }
}