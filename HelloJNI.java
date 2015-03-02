public class HelloJNI {

   private native void sayHello();
   
   public static void main(final String[] args) {

       System.out.printf("\njava.library.path=%s\n\n", System.getProperty("java.library.path"));
       // System.loadLibrary("HelloJNI");
       System.load(args[0]);
       new HelloJNI().sayHello();  
   }
}
