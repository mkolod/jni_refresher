class HelloJNI {
	
  @native def getNativeString(scalaStr: String): String
}

object HelloJNI extends App {

  println(s"\njava.library.path=${System.getProperty("java.library.path")}\n\n")
  System.load(args(0))
  print("In Scala - enter string to be sent to C++: ")
  val str = readLine()
  println(s"\nIn Scala: the C++ user entered: ${new HelloJNI().getNativeString(str)}\n\n")
}
