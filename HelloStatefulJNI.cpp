#include <jni.h>
#include <cstdlib>
#include "HelloStatefulJNI.h"

JNIEXPORT jlong JNICALL Java_HelloStatefulJNI_malloc(JNIEnv * const env, jobject const thisObj, const jint numEl) {
	return (jlong) (int *) malloc(numEl * sizeof(int));
}

JNIEXPORT void JNICALL Java_HelloStatefulJNI_putInt(JNIEnv * const env, jobject const thisObj, const jlong ptrAddr, const jint pos, const jint value) {
	*((int *) ptrAddr + pos) = value;
}

JNIEXPORT jint JNICALL Java_HelloStatefulJNI_getInt(JNIEnv * const env, jobject const thisObj, const jlong ptrAddr, const jint pos) {
    return (jint) *((int *) ptrAddr + pos);
}

JNIEXPORT void JNICALL Java_HelloStatefulJNI_free(JNIEnv * const env, jobject const thisObj, const jlong ptrAddr) {
	free((int *) ptrAddr);
}
