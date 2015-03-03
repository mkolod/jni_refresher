#include <jni.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "HelloJNI.h"

using namespace std;

typedef unsigned char BYTE;
 
JNIEXPORT jstring JNICALL Java_HelloJNI_getNativeString(JNIEnv* const env, jobject const thisObj, jstring const scalaStr) {
  
  const char *str = env->GetStringUTFChars(scalaStr, 0);
  cout << "In C++ - Scala sent: " << str << endl;
  env->ReleaseStringUTFChars(scalaStr, str);

  cout << "In C++ - Enter string to be sent to Scala: ";
  string in;
  getline(cin, in);
  return env->NewStringUTF((char*) in.c_str());
}

JNIEXPORT jboolean JNICALL Java_HelloJNI_getNativeBoolean(JNIEnv* const env, jobject const thisObj, jboolean const scalaBool) {

  const bool nativeBool = (bool) scalaBool;
  cout << "In C++ - received Boolean from Scala: " << boolalpha << nativeBool << endl;
  return nativeBool;
}

JNIEXPORT jbyte JNICALL Java_HelloJNI_getNativeByte(JNIEnv* const env, jobject const thisObj, jbyte const scalaByte) {

  const BYTE nativeByte = (BYTE) scalaByte;
  cout << "In C++ - received byte from Scala: " << (int) nativeByte << endl;
  return nativeByte;
}

JNIEXPORT jchar JNICALL Java_HelloJNI_getNativeChar(JNIEnv* const env, jobject const thisObj, jchar const scalaChar) {

  const char nativeChar = (char) scalaChar;
  cout << "In C++ - received char from Scala: " << nativeChar << endl;
  return nativeChar;
}

JNIEXPORT jshort JNICALL Java_HelloJNI_getNativeShort(JNIEnv* const env, jobject const thisObj, jshort const scalaShort) {

  const short nativeShort = (short) scalaShort;
  cout << "In C++ - received short from Scala: " << nativeShort << endl;
  return nativeShort;
}

JNIEXPORT jint JNICALL Java_HelloJNI_getNativeInt(JNIEnv* const env, jobject const thisObj, jint const scalaInt) {

  const int nativeInt = (int) scalaInt;
  cout << "In C++ - received int from Scala: " << nativeInt << endl;
  return nativeInt;
}

JNIEXPORT jlong JNICALL Java_HelloJNI_getNativeLong(JNIEnv* const env, jobject const thisObj, jlong const scalaLong) {

  const long long nativeLong = (long) scalaLong;
  cout << "In C++ - received long from Scala: " << nativeLong << endl;
  return nativeLong;
}

JNIEXPORT jfloat JNICALL Java_HelloJNI_getNativeFloat(JNIEnv* const env, jobject const thisObj, jfloat const scalaFloat) {

  const float nativeFloat = (float) scalaFloat;
  cout << "In C++ - received float from Scala: " << nativeFloat << endl;
  return nativeFloat;
}

JNIEXPORT jdouble JNICALL Java_HelloJNI_getNativeDouble(JNIEnv* const env, jobject const thisObj, jdouble const scalaDouble) {

  const double nativeDouble = (double) scalaDouble;
  cout << "In C++ - received doubla from Scala: " << nativeDouble << endl;
  return nativeDouble;
}

string dblVecToString(vector<double> const vec) {

  ostringstream oss;

  if (!vec.empty()) {

    oss << "[";
    copy(vec.begin(), vec.end()-1, ostream_iterator<double>(oss, ", ")); 
    oss << vec.back() << "]";
  }

  return oss.str();
}

JNIEXPORT jdoubleArray JNICALL Java_HelloJNI_getNativeDoubleArray(JNIEnv* const env, jobject const thisObj, jdoubleArray const scalaDoubleArray) {

  const jsize size = env->GetArrayLength( scalaDoubleArray );
  vector<double> vec( (int) size );
  env->GetDoubleArrayRegion( scalaDoubleArray, 0, size, &vec[0] );

  cout << "In C++ - received double array from Scala: " << dblVecToString(vec) << endl;
  return scalaDoubleArray;
}



