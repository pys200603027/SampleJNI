//
// Created by Uncle叶 on 2018/10/31.
//
#include "inithelper.h"

jint JNI_OnLoad_Wrapper(JavaVM *vm, void *reserved, const char *classname, JNINativeMethod *methods,int methodSize) {
    JNIEnv *env;
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }

    jclass sampleRuntimeClazz = env->FindClass(classname);
    if (sampleRuntimeClazz == NULL) {
        return JNI_ERR;
    }

    if (env->RegisterNatives(sampleRuntimeClazz, methods, methodSize) < 0) {
        return JNI_ERR;
    }

    return JNI_VERSION_1_6;
}