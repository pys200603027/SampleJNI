//
// Created by Uncle叶 on 2018/10/31.
//
#include "utils/log.h"
#include "utils/inithelper.h"
#include <string>
#include <jni.h>

jstring getHelloWorld(JNIEnv *env, jobject thiz) {
    std::string hello_world = "helloWorld";
    LOGD("my printf:%s", hello_world.c_str());
    return env->NewStringUTF(hello_world.c_str());
}

JNINativeMethod methods[] = {
        {"getHelloWorld", "()Ljava/lang/String;", (void *) (getHelloWorld)}
};

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    const char *className = "water/android/io/snakejni/SnakeJNI";
    return JNI_OnLoad_Wrapper(vm, reserved, className, methods, sizeof(methods) / sizeof(methods[0]));
}


