class Bar {
	public static void main(String[] a) {
		System.out.println(new Bar1().foo(100, 5));
	}
}

class Bar1 {
   public int foo(int a, int b)
   {
      int s;
      int f;
      s = this.sum(a);
      f = this.fac(b);

      System.out.println(s);
      System.out.println(f);
      return 1;
   }
   public int sum(int s){
      int sum;
      if(s == 1)
         sum = 1;
      else
         sum = s + this.sum(s - 1);
      return sum;
   }
   public int fac(int s)
   {
      int fac;
      if(s == 1)
         fac = 1;
      else
         fac = s * this.fac(s - 1);
      return fac;
   }
}