class Main {
   public static void main(String[] args){
      System.out.println(new Foo().bar());
   }
}

class Foo
{
   public int bar()
   {
      int a;
      int b;
      a = 5;
      b = 4;
      while(a > 0){
         if(a < b)
         {
            b = b - 1;
         }
         else
         {
            a = a - 1;
         }
      }
      return a;
   }
}