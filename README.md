# JNI Refresher

Just run the "run.sh" shell script. Note that you may need to change it to pick the correct JAVA_HOME export, or delete it if you already have JAVA_HOME set up. Also, I'm exporting a dylib on OS X, so feel free to change it to .so on Linux.

Also, note that this assumes that the JNI methods will be applied as instance methods. To call static methods/methods on Scala singleton objects, you may need [scalah](https://github.com/wpc009/Scalah), which is a modified javah. 
### TODO:

Explore [JNI SBT plugin](https://github.com/joprice/sbt-jni) to conver this into an SBT build, with proper package conventions, without the shell script, etc.

### Notes:

The full JNI spec can be found [here](https://docs.oracle.com/javase/8/docs/technotes/guides/jni/spec/jniTOC.html).

If you'd like to learn more about JNI, check out [this tutorial](http://www3.ntu.edu.sg/home/ehchua/programming/java/JavaNativeInterface.html) (Java only, but you should get the idea for Scala).

For comparisons between JNI and JNA, see [here](http://blog.caplin.com/2014/12/01/jnajni/). I agree with the author of the JNI vs. JNA blog post that JNI is actually easier for non-trivial use cases, and it's faster. 

For better C++ (not just C) support, it may be worth trying out [JavaCpp](https://github.com/bytedeco/javacpp) instead of writing JNI directly.

Check out [this post](http://www.ibm.com/developerworks/library/j-jni/) for JNI best practices (warning: it's a bit dated (2009), but JNI hasn't evolved much in the last few years, so it's probably OK).
