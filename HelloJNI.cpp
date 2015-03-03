#include <jni.h>
#include <iostream>
#include <string>
#include "HelloJNI.h"

using namespace std;

typedef unsigned char BYTE;
 
JNIEXPORT jstring JNICALL Java_HelloJNI_getNativeString(JNIEnv *env, jobject thisObj, jstring scalaStr) {
  
  const char *str = env->GetStringUTFChars(scalaStr, 0);
  cout << "In C++ - Scala sent: " << str << endl;
  env->ReleaseStringUTFChars(scalaStr, str);

  cout << "In C++ - Enter string to be sent to Scala: ";
  string in;
  getline(cin, in);
  return env->NewStringUTF((char*)in.c_str());
}

JNIEXPORT jboolean JNICALL Java_HelloJNI_getNativeBoolean(JNIEnv *env, jobject thisObj, jboolean scalaBool) {

  const bool nativeBool = (bool) scalaBool;
  cout << "In C++ - received Boolean from Scala: " << boolalpha << nativeBool << endl;
  return nativeBool;
}

JNIEXPORT jbyte JNICALL Java_HelloJNI_getNativeByte(JNIEnv *env, jobject thisObj, jbyte scalaByte) {

  const BYTE nativeByte = (BYTE) scalaByte;
  cout << "In C++ - received byte from Scala: " << (int) nativeByte << endl;
  return nativeByte;
}

JNIEXPORT jchar JNICALL Java_HelloJNI_getNativeChar(JNIEnv *env, jobject thisObj, jchar scalaChar) {

  const char nativeChar = (char) scalaChar;
  cout << "In C++ - received char from Scala: " << nativeChar << endl;
  return nativeChar;
}

JNIEXPORT jshort JNICALL Java_HelloJNI_getNativeShort(JNIEnv *env, jobject thisObj, jshort scalaShort) {

  const short nativeShort = (short) scalaShort;
  cout << "In C++ - received short from Scala: " << nativeShort << endl;
  return nativeShort;
}

JNIEXPORT jint JNICALL Java_HelloJNI_getNativeInt(JNIEnv *env, jobject thisObj, jint scalaInt) {

  const int nativeInt = (int) scalaInt;
  cout << "In C++ - received int from Scala: " << nativeInt << endl;
  return nativeInt;
}

JNIEXPORT jlong JNICALL Java_HelloJNI_getNativeLong(JNIEnv *env, jobject thisObj, jlong scalaLong) {

  const long long nativeLong = (long) scalaLong;
  cout << "In C++ - received long from Scala: " << nativeLong << endl;
  return nativeLong;
}

JNIEXPORT jfloat JNICALL Java_HelloJNI_getNativeFloat(JNIEnv *env, jobject thisObj, jfloat scalaFloat) {

  const float nativeFloat = (float) scalaFloat;
  cout << "In C++ - received float from Scala: " << nativeFloat << endl;
  return nativeFloat;
}

JNIEXPORT jdouble JNICALL Java_HelloJNI_getNativeDouble(JNIEnv *env, jobject thisObj, jdouble scalaDouble) {

  const double nativeDouble = (double) scalaDouble;
  cout << "In C++ - received doubla from Scala: " << nativeDouble << endl;
  return nativeDouble;
}