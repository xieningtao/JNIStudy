//#include "com_example_jnistudy_AnotherJNIDemoActivity.h"
//#include "com_example_jnistudy_MainActivity.h"
#include <jni.h>

//extern "C" JNIEXPORT jdouble JNICALL Java_com_example_jnistudy_AnotherJNIDemoActivity_testObject
//        (JNIEnv *, jobject, jstring){
//
//}
//
//extern "C" JNIEXPORT jdouble JNICALL Java_com_example_jnistudy_AnotherJNIDemoActivity_testArray
//        (JNIEnv *, jobject, jintArray){
//
//}
//
///*
// * Class:     com_example_jnistudy_MainActivity
// * Method:    stringFromJNI
// * Signature: ()Ljava/lang/String;
// */
//extern "C" JNIEXPORT jstring JNICALL Java_com_example_jnistudy_MainActivity_stringFromJNI
//        (JNIEnv *, jobject){
//
//}
//
///*
// * Class:     com_example_jnistudy_MainActivity
// * Method:    formatName
// * Signature: (Ljava/lang/String;)Ljava/lang/String;
// */
//extern "C" JNIEXPORT jstring JNICALL Java_com_example_jnistudy_MainActivity_formatName
//        (JNIEnv *, jobject, jstring){
//
//}
//
///*
// * Class:     com_example_jnistudy_MainActivity
// * Method:    getValidToken
// * Signature: (Ljava/lang/Object;)Ljava/lang/String;
// */
//extern "C" JNIEXPORT jstring JNICALL Java_com_example_jnistudy_MainActivity_getValidToken
//        (JNIEnv *, jobject, jobject){
//
//}

JNIEXPORT jdouble JNICALL
Java_com_example_jnistudy_AnotherJNIDemoActivity_testBasic(JNIEnv *env, jobject thiz, jint value,jboolean a) {
    return 30.0;
}

JNIEXPORT jstring JNICALL
Java_com_example_jnistudy_MainActivity_formatName(JNIEnv *env, jobject thiz, jstring name) {
    jboolean isCopy;
    jstring  result;
    const char* buffer =  (*env)->GetStringUTFChars(env,name,&isCopy);
    result = (*env)->NewStringUTF(env,"hello a");
    (*env)->ReleaseStringUTFChars(env,name,buffer);
    return result;
}

JNIEXPORT jdouble JNICALL
Java_com_example_jnistudy_AnotherJNIDemoActivity_testObject(JNIEnv *env, jobject thiz,
                                                            jstring value) {
    // TODO: implement testObject()
}

JNIEXPORT jdouble JNICALL
Java_com_example_jnistudy_AnotherJNIDemoActivity_aaa(JNIEnv *env, jobject thiz, jint a, jdouble b) {
    // TODO: implement aaa()
}