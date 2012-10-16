#include <jni.h>

static void sayHi(JNIEnv *env, jclass clazz, jstring who, jint times) {
  const char *name = (*env)->GetStringUTFChars(env, who, NULL);
  if (name != NULL) {
    jint i;
    for (i = 0; i < times; i++) {
      printf("Hello %s\n", name);
    }
    (*env)->ReleaseStringUTFChars(env, who, name);
  }
}

static JNINativeMethod method_table[] = {
  { "sayHi", "(Ljava/lang/String;I)V", (void *) sayHi }
};

static int method_table_size = sizeof(method_table) / sizeof(method_table[0]);

jint JNI_OnLoad(JavaVM* vm, void* reserved) {
  JNIEnv* env;
  if ((*vm)->GetEnv(vm, (void **) &env, JNI_VERSION_1_6) != JNI_OK) {
    return JNI_ERR;
  } else {
    jclass clazz = (*env)->FindClass(env, "com/marakana/jniexamples/Hello");
    if (clazz) {
      jint ret = (*env)->RegisterNatives(env, clazz, method_table, method_table_size);
      (*env)->DeleteLocalRef(env, clazz);
      return ret == 0 ? JNI_VERSION_1_6 : JNI_ERR;
    } else {
      return JNI_ERR;
    }
  }
}

