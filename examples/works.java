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
   public int main(boolean b){
      return 0;
   }
}

class SmallBrain extends BigBrain
{
   int a;
   public int b(){
      return this.main(true);
   }
}