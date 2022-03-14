class Main 
{
   public static void main(String[] args)
   {
      System.out.println(new BigBrain().run(5, 2));
   }
}

class Element
{

   public int foo(int x, int y, int z)
   {
      int a; int b;
      int c; int d;

      a = x + y / x;
      b = y * x + a;
      c = z - b + a / b;
      while(a > 0)
      {
         b = b - 1;
         if(b < 5)
         {
            c = 5;
         }
         else 
         {
            c = 2;
         }
      }
      d = a + b + c;
      return d;
   }
}

class BigBrain 
{
   public int run(int x, int y){
      int[] a;
      int z;
      Element e;

      a = new int[69];
      e = new Element();
      
      z = e.foo(x, y, 420);
      return a[0];
   }
}