#include <jni.h>
#include <iostream>
#include <string>
#include "HelloJNI.h"

using namespace std;
 
JNIEXPORT jstring JNICALL Java_HelloJNI_getNativeString(JNIEnv *env, jobject thisObj) {
   cout << "In C++ - enter string to be printed by Scala: ";
   string in;
   getline(cin, in);
   cout << endl << "In C++ - string entered was " << in << endl;
   return env->NewStringUTF((char*)in.c_str());
}