//
// Created by Uncle叶 on 2018/10/31.
//
#include <jni.h>
#include <string>

jstring getHelloWorld(JNIEnv *env, jobject thiz) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

static JNINativeMethod methods[] = {
        {"stringFromJNI", "()Ljava/lang/String;", (void *) (getHelloWorld)}
};

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }

    jclass sampleRuntimeClazz = env->FindClass("water/android/io/snakejni/runtime/SampleRuntimeJNI");
    if (sampleRuntimeClazz == NULL) {
        return JNI_ERR;
    }

    if (env->RegisterNatives(sampleRuntimeClazz, methods, sizeof(methods) / sizeof(methods[0])) < 0) {
        return JNI_ERR;
    }

    return JNI_VERSION_1_6;
}
