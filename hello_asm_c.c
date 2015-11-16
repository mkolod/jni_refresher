#include "HelloAssembly.h"

void helloAsm(void);

JNIEXPORT void JNICALL Java_HelloAssembly_helloAssembly
  (JNIEnv * const env, jobject const thisObj) {
  	helloAsm();
  }