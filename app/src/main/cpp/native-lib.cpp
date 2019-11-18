#include <jni.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_jnistudy_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_jnistudy_MainActivity_formatName(JNIEnv *env, jobject thiz, jstring name) {
    jboolean isCopy = JNI_TRUE;
    const char *jniName = env->GetStringUTFChars(name, &isCopy);
    std::string another = jniName;
    transform(another.begin(), another.end(), another.begin(), ::toupper);
    jstring formatName = env->NewStringUTF(another.c_str());
//    env->ReleaseStringUTFChars(name,jniName);
    char *test = new char[1024*1024];
    char *nullTest = nullptr;
    nullTest++;
//    cout<<"nullTest"<< nullTest;
    return formatName;
}