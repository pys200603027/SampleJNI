//
// Created by Uncle叶 on 2018/10/31.
//

#ifndef SAMPLEJNI_INITHELPER_H
#define SAMPLEJNI_INITHELPER_H

#include <jni.h>

/**
 * jni动态注册辅助方法
 * @param classname :java类全名
 * @param methods : native方法 -- java 方法对应表
 * 例子：
 * classname: water/android/io/snakejni/runtime/SampleRuntimeJNI
 *
 * static JNINativeMethod methods[] = {
        {"stringFromJNI", "()Ljava/lang/String;", (void *) (getHelloWorld)}
    };
 *
 */
jint JNI_OnLoad_Wrapper(JavaVM *vm, void *reserved, const char *classname, JNINativeMethod* methods, int methodSize);

#endif //SAMPLEJNI_INITHELPER_H
