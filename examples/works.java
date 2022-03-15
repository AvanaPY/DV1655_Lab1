class Bar {
	public static void main(String[] a) {
		System.out.println(new Bar1().foo(1, 2));
	}
}

class Bar1 {
   public int foo(int a, int b){
      int sum;
      sum = a + b;
      return sum;
   }
}