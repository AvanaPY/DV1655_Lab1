class Main{
    public static void main(String[] a){
       new Element();
    }
}

class Element {
   public Element abc(){
      Element e;
      Element e2;
      e = new Element();
      e2 = this;
      return e2;
   }
}