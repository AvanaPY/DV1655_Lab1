class Main 
{
   public static void main(String[] args)
   {
      System.out.println(new BigBrain().run(5, 2));
   }
}

class BigBrain 
{
   public int run(int x, int y){
      return x + y;
   }
}