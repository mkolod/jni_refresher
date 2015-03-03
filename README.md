# jni_refresher

Just run the "run.sh" shell script. Note that you may need to change it to pick the correct JAVA_HOME export, or delete it if you already have JAVA_HOME set up. Also, I'm exporting a dylib on OS X, so feel free to change it to .so on Linux.

Also, note that this assumes that the JNI methods will be applied as instance methods. To call static methods/methods on Scala singleton objects, you may need scalah, which is a modified javah. This project can be found [here](https://github.com/wpc009/Scalah).
