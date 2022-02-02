class Main {
   public static void main(String[] args){
      Abc.m();
   }
}

class Abc{
   int var1;
   public void m(int c){
      int a;
      a = c + 1;
      a = var1;
      a = var2;
   }
   public void p(int c){
      this.m();
   }
}