//
// Created by Uncle叶 on 2018/11/2.
//

#include "nativebean.h"

/**
 * Java中用于存储的native实例的变量名字，这里规定为long
 */
const char *fielName = "nativeInstance";

void setInstance(JNIEnv *env, jobject thiz, jlong value) {
    jclass ins = env->GetObjectClass(thiz);
    jfieldID fileId = env->GetFieldID(ins, fielName, "J");
    env->SetLongField(thiz, fileId, value);
}

jlong getInstance(JNIEnv *env, jobject thiz) {
    jclass ins = env->GetObjectClass(thiz);
    jfieldID fileId = env->GetFieldID(ins, fielName, "J");
    return env->GetLongField(thiz, fileId);
}
