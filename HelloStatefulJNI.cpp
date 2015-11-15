#include <jni.h>
#include <cstdlib>
#include "HelloStatefulJNI.h"

JNIEXPORT jlong JNICALL Java_HelloStatefulJNI_malloc(JNIEnv * const env, jobject const thisObj, const jint numEl) {
	int * ptr = (int *) malloc(numEl * sizeof(int));
	return (jlong) ptr;
}

JNIEXPORT void JNICALL Java_HelloStatefulJNI_putInt(JNIEnv * const env, jobject const thisObj, const jlong ptrAddr, const jint pos, const jint value) {
	int * ptr = (int *) ptrAddr;
	*(ptr + pos) = value;
}

JNIEXPORT jint JNICALL Java_HelloStatefulJNI_getInt(JNIEnv * const env, jobject const thisObj, const jlong ptrAddr, const jint pos) {
	int * ptr = (int *) ptrAddr;
    return (jint) *(ptr + pos);
}

JNIEXPORT void JNICALL Java_HelloStatefulJNI_free(JNIEnv * const env, jobject const thisObj, const jlong ptrAddr) {
	int * ptr = (int *) ptrAddr;
	free(ptr);
}
