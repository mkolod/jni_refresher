class HelloStatefulJNI {
	

  @native def malloc(numInts: Int): Long
  @native def putInt(ptr: Long, pos: Int, value: Int): Unit
  @native def getInt(ptr: Long, pos: Int): Int
  @native def free(ptr: Long): Unit	
 
}

object HelloStatefulJNI extends App {

  System.loadLibrary("hellostateful")

  val jni = new HelloStatefulJNI()
  val ptr = jni.malloc(1000)
  val pos = 10
  jni.putInt(ptr, pos, 42)
  println(s"Expected to get 42, got ${jni.getInt(ptr, pos)}")
  jni.free(ptr)

}


