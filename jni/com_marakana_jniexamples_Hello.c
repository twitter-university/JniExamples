#include "com_marakana_jniexamples_Hello.h"

JNIEXPORT void JNICALL Java_com_marakana_jniexamples_Hello_sayHi
  (JNIEnv *env, jclass clazz, jstring who, jint times) {
  const char *name = (*env)->GetStringUTFChars(env, who, NULL);
  if (name != NULL) {
    jint i;
    for (i = 0; i < times; i++) {
      printf("Hello %s\n", name);
    }
    (*env)->ReleaseStringUTFChars(env, who, name);
  }
}
