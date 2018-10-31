#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring JNICALL
Java_water_android_io_snakejni_runtime_SampleStaticJNI_stringFromJNI(JNIEnv *env,
                                                                     jobject instance) {

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}