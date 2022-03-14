class Bar {
	public static void main(String[] a) {
		System.out.println(new Bar1().foo());
	}
}

class Element 
{
   public int sum(int a, int b){
      return a + b;
   }
}

class Bar1 {
	public int foo() {
		int aux;
      aux = this.sum(1, 2);
		return aux;
   }
   public int sum(int a, int b){
      return a + b;
   }
}