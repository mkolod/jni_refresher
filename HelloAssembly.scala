class HelloAssembly {
	

  @native def helloAssembly(): Unit
 
}

object HelloAssembly extends App {

  System.loadLibrary("helloassembly")

  val jni = new HelloAssembly()
  println("\nCalling assembly from Scala")
  jni.helloAssembly()
  println("Back in Scala\n")
}


