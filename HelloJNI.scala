class HelloJNI {

	@native def getNativeString(): String
}

object HelloJNI extends App {

	println(s"\njava.library.path=${System.getProperty("java.library.path")}\n\n")
	System.load(args(0))
	println(s"\nIn Scala: the C++ user entered: ${new HelloJNI().getNativeString()}\n\n")
}