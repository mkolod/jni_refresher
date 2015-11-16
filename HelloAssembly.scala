class HelloAssembly {
	

  @native def helloAssembly(): Unit
 
}

object HelloAssembly extends App {

  System.loadLibrary("helloassembly")

  val jni = new HelloAssembly()
  println("\nCalling assembly from Scala")
  try {
  jni.helloAssembly()
  } catch {
  	case x: Throwable => 
  }
  println("Back in Scala\n")
}


