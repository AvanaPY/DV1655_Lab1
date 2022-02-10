class Main 
{
   public static void main(String[] args)
   {
      System.out.println(new BigBrain().run());
   }
}

class BigBrain 
{
    public int run()
    {
        int[] a;
        a = this.main();
        return a[4];
    }
    public int[] main(){
        int[] a;
        a = new int[10];
        a[4] = 1;
        return a;
    }
}