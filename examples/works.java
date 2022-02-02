class Main {
   public static void main(String[] args){
      Abc.m(1, 2, 3);
   }
}

class Abc{
   int var1;
   int[] var2;
   int c;
   public void m(){
      int a;
      a = c + 1;
      a = var1;
      var2[var2.length-1] = 2;
   }
   public void p(int c){
      this.m();
   }
}