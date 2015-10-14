#include "Foo_CallC.h"
#include <string.h>
#include <ctype.h>

JNIEXPORT jint JNICALL Java_Foo_CallC_intMethod
 (JNIEnv *env, jobject obj, jint num) {
  return num * num;
}

JNIEXPORT jboolean JNICALL Java_Foo_CallC_booleanMethod
  (JNIEnv *env, jobject obj, jboolean boolean) {
  return !boolean;
}

JNIEXPORT jstring JNICALL Java_Foo_CallC_stringMethod
  (JNIEnv *env, jobject obj, jstring string) {
    const char * str = env->GetStringUTFChars(string, 0);
    char cap[128];
    for (unsigned i = 0; ; ++i) {
        cap[i] = toupper(str[i]);
        if (cap[i] == 0) {
            break;
        }
    }
    env->ReleaseStringUTFChars(string, str);
    return env->NewStringUTF(cap);
}

JNIEXPORT jint JNICALL Java_Foo_CallC_intArrayMethod
  (JNIEnv *env, jobject obj, jintArray array) {
    int i, sum = 0;
    jsize len = env->GetArrayLength(array);
    jint *body = env->GetIntArrayElements(array, 0);
    for (i=0; i<len; i++)
    {	sum += body[i];
    }
    env->ReleaseIntArrayElements(array, body, 0);
    return sum;
}
