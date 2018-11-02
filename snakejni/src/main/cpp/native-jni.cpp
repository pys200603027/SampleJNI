//
// Created by Uncle叶 on 2018/10/31.
//
#include "utils/log.h"
#include "utils/inithelper.h"
#include "utils/nativebean.h
#include <string>
#include <jni.h>

static void create(JNIEnv *env, jobject thiz) {
    jstring tmpString = env->NewStringUTF("hellohellohello");
    jstring globalString = static_cast<jstring>(env->NewGlobalRef(tmpString));
    env->DeleteLocalRef(tmpString);
    setInstance(env, thiz, reinterpret_cast<jlong>(globalString));
}

static void destrory(JNIEnv *env, jobject thiz) {
    jstring globalString = reinterpret_cast<jstring>(getInstance(env, thiz));
    const char *str = env->GetStringUTFChars(globalString, 0);
    LOGD("globalString %s", str);
    env->DeleteGlobalRef(globalString);
}


JNINativeMethod methods[] = {
        {"nativeCreate",  "()V", (void *) (create)},
        {"nativeDestroy", "()V", (void *) (destrory)},
};

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    const char *className = "water/android/io/snake/SnakeJNI";
    return JNI_OnLoad_Wrapper(vm, reserved, className, methods,
                              sizeof(methods) / sizeof(methods[0]));
}


