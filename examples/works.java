class Main{
    public static void main(String[] a){
       new Element();
    }
}

class Element {
   public Element abc(){
      int[] var;
      int sz;
      sz = 1;
      var = new int[sz];
      var[sz] = 0;
      System.out.println(var[sz]);
      return new Element();
   }
}