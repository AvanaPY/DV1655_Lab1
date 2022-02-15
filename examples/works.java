class Main 
{
   public static void main(String[] args)
   {
      System.out.println(new BigBrain().main(true));
   }
}

class BigBrain 
{
   int size;
   public int main(boolean b){
      return new BigBrain();
   }
}

class SmallBrain extends BigBrain
{
   int a;
   public int b(){
      return this.main(true);
   }
   public int c()
   {
      int a;
      a = 5 + 5 + 5 - 2;
      return a;
   }
   public int d()
   {
      return 5;
   }
}