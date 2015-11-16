#!/bin/bash

echo "Exporting env vars"
export JAVA_HOME=`/usr/libexec/java_home -v 1.8`
export SCALA_LIB_HOME=/usr/local/Cellar/scala/2.11.5/libexec/lib/
export SCALA_CP=$SCALA_LIB_HOME/scala-library.jar:$SCALA_LIB_HOME/scala-reflect.jar

echo "Compiling Scala class file"
scalac HelloAssembly.scala

echo "Creating C header"
javah -cp $SCALA_CP:. HelloAssembly

echo "Compiling shared native library"
gcc -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/darwin" -shared -o libhelloassembly.dylib hello_asm.S hello_asm_c.c

echo "Running native code from Scala"
scala HelloAssembly -Djava.library.path=`pwd`