class Main {
   public static void main(String[] args){
      System.out.println(5);
      BigBrain.run();
   }
}

class BigBrain{
   public void run()
   {
      int[] a;
      a = new int[4];
      a[a.length-2] = 0;
      System.out.println(a.length);
   }
}