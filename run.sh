#!/bin/bash

echo "Exporting env vars"
export JAVA_HOME=`/usr/libexec/java_home -v 1.8`
export SCALA_LIB_HOME=/usr/local/Cellar/scala/2.11.5/libexec/lib/
export SCALA_CP=$SCALA_LIB_HOME/scala-library.jar:$SCALA_LIB_HOME/scala-reflect.jar

echo "Compiling Scala class file"
scalac HelloJNI.scala

echo "Creating C header"
javah -cp $SCALA_CP:. HelloJNI

echo "Compiling shared native library"
g++ -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/darwin" -shared -o HelloJNI.dylib HelloJNI.cpp

echo "Running native code from Scala"
scala HelloJNI `pwd`/HelloJNI.dylib
