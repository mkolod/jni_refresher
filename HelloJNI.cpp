#include <jni.h>
#include <iostream>
#include <string>
#include "HelloJNI.h"

using namespace std;
 
JNIEXPORT jstring JNICALL Java_HelloJNI_getNativeString(JNIEnv *env, jobject thisObj) {
   cout << "In C++ - enter string to be printed by Scala: ";
   string foo;
   cin >> foo;
   return env->NewStringUTF((char*)foo.c_str());
}