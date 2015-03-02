#!/bin/bash

echo "Exporting JAVA_HOME"
export JAVA_HOME=`/usr/libexec/java_home -v 1.8`

echo "Compiling Java class file"
javac HelloJNI.java 

echo "Creating C header"
javah HelloJNI

echo "Compiling shared native library"
g++ -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/darwin" -shared -o HelloJNI.dylib HelloJNI.cpp

echo "Running native code from Java"
java HelloJNI `pwd`/HelloJNI.dylib
