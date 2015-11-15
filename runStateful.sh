#!/bin/bash

echo "Exporting env vars"
export JAVA_HOME=`/usr/libexec/java_home -v 1.8`
export SCALA_LIB_HOME=/usr/local/Cellar/scala/2.11.5/libexec/lib/
export SCALA_CP=$SCALA_LIB_HOME/scala-library.jar:$SCALA_LIB_HOME/scala-reflect.jar

echo "Compiling Scala class file"
scalac HelloStatefulJNI.scala

echo "Creating C header"
javah -cp $SCALA_CP:. HelloStatefulJNI

echo "Compiling shared native library"
g++ -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/darwin" -shared -o libhellostateful.dylib HelloStatefulJNI.cpp

echo "Running native code from Scala"
scala HelloStatefulJNI -Djava.library.path=`pwd`
# `pwd`/HelloJNI.dylib
