//
// Created by Uncle叶 on 2018/11/2.
//

#ifndef SAMPLEJNI_NATIVEBEAN_H
#define SAMPLEJNI_NATIVEBEAN_H

#include <jni.h>



void setInstance(JNIEnv *env, jobject thiz, jlong value);

jlong getInstance(JNIEnv *env, jobject thiz);

#endif //SAMPLEJNI_NATIVEBEAN_H
