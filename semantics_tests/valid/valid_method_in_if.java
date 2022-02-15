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
        int a;
        if(this.main()){
            a = 1;
        } else {
            a = 2;
        }
        return a;
    }
    public boolean main(){
        return false;
    }
}