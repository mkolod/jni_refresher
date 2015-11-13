class HelloJNI {
	
  @native def getNativeBoolean(scalaBool: Boolean): Boolean

  @native def getNativeByte(scalaByte: Byte): Byte

  @native def getNativeChar(scalaChar: Char): Char

  @native def getNativeShort(scalaShort: Short): Short

  @native def getNativeInt(scalaInt: Int): Int

  @native def getNativeLong(scalaLong: Long): Long

  @native def getNativeFloat(scalaFloat: Float): Float

  @native def getNativeDouble(scalaDouble: Double): Double

  // native representation: modified UTF-8 (http://docs.oracle.com/javase/1.5.0/docs/guide/jni/spec/types.html)
  @native def getNativeString(scalaStr: String): String

  @native def getNativeDoubleArray(scalaArr: Array[Double]): Array[Double]
}

object HelloJNI extends App {

  import java.util.Arrays

  println(s"\njava.library.path=${System.getProperty("java.library.path")}\n\n")
  // System.load(args(0))
  System.loadLibrary("hello")

  val helloJNI = new HelloJNI()

  print("In Scala - enter string to be sent to C++: ")
  val str = readLine()
  println(s"In Scala: the C++ user entered: ${helloJNI.getNativeString(str)}\n")
 
  val bool = true
  println(s"In Scala: sending Boolean value of $bool to C++")
  println(s"In Scala: C++ responded with Boolean value of ${helloJNI.getNativeBoolean(bool)}\n")

  val byte = 65.toByte
  println(s"""In Scala: sending byte value of $byte (letter ${byte.toChar}) to C++""")
  println(s"In Scala: C++ responded with byte value of ${helloJNI.getNativeByte(byte)}\n")

  val char = 'A'
  println(s"""In Scala: sending char $char to C++""")
  println(s"In Scala: C++ responded with char value of ${helloJNI.getNativeChar(char)}\n")
  
  val short = 1.toShort
  println(s"""In Scala: sending short $short to C++""")
  println(s"In Scala: C++ responded with short value of ${helloJNI.getNativeShort(short)}\n")
 
  val int = 1
  println(s"""In Scala: sending int $int to C++""")
  println(s"In Scala: C++ responded with int value of ${helloJNI.getNativeInt(int)}\n")

  val long = 1L
  println(s"""In Scala: sending long $long to C++""")
  println(s"In Scala: C++ responded with long value of ${helloJNI.getNativeLong(long)}\n")

  val float = 1.0F
  println(s"""In Scala: sending float $float to C++""")
  println(s"In Scala: C++ responded with float value of ${helloJNI.getNativeFloat(float)}\n")
 
  val double = 1.0D
  println(s"""In Scala: sending double $double to C++""")
  println(s"In Scala: C++ responded with doublt value of ${helloJNI.getNativeDouble(double)}\n")

  val doubleArr = Array[Double](1.0D, 2.0D, 3.0D)
  println(s"""In Scala: sending double array ${Arrays.toString(doubleArr)} to C++""")
  println(s"In Scala: C++ responded with double value of ${Arrays.toString(helloJNI.getNativeDoubleArray(doubleArr))}\n")
}


