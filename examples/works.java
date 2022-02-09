class Main 
{
   public static void main(String[] args)
   {
      System.out.println(BigBrain.main(true));
   }
}

class BigBrain 
{
   int size;
}

class SmallBrain extends BigBrain
{
   int a;
   public int b(){
      return 0;
   }
}