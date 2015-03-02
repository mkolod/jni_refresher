#include <jni.h>
#include <iostream>
#include <string>
#include "HelloJNI.h"

using namespace std;
 
JNIEXPORT jstring JNICALL Java_HelloJNI_getNativeString(JNIEnv *env, jobject thisObj, jstring scalaStr) {
  
  const char *str = env->GetStringUTFChars(scalaStr, 0);
  cout << "In C++ - Scala sent: " << str << endl;
  env->ReleaseStringUTFChars(scalaStr, str);

  cout << "In C++ - Enter string to be sent to Scala: ";
  string in;
  getline(cin, in);
  return env->NewStringUTF((char*)in.c_str());
}