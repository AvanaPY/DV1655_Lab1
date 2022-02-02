class Main {
   public static void main(String[] args){
      BigBrain.run();
   }
}

class BigBrain{
   int var1;
   public void run(){
      this.p(4);
   }
   public int p(int c){
      c = this.doAdvancedMaths();
      return c;
   }
   public int doAdvancedMaths(){
      int a;
      a = 2 + 2;
      return a;
   }
}