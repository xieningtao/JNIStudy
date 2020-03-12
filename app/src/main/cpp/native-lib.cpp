#include <jni.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 *这个key就是要用来加密传输内容的rsa的公钥
 */
const char* AUTH_KEY = "1111";

/**
 * 发布的app 签名,只有和本签名一致的app 才会返回 AUTH_KEY
 * 这个RELEASE_SIGN的值是上一步用java代码获取的值
 */
const char* RELEASE_SIGN = "xxxxxx30102020440625908300d06092a864886f70d01010b0500305a310b3009060355040613023836310e300c060355040813056875626569310e300c06035504071305777568616e310d300b060355040a130468656865310d300b060355040b130468656865310d300b0603550403130463616c6c301e170d3136303932393130303234355a170d3436303932323130303234355a305a310b3009060355040613023836310e300c060355040813056875626569310e300c06035504071305777568616e310d300b060355040a130468656865310d300b060355040b130468656865310d300b0603550403130463616c6c30820122300d06092a864886f70d01010105000382010f003082010a0282010100b508259dd7e36da221a2b5de5158e6e1f310f2b11073b359b4a3e49d80f0b8c741c167e1364e0d3054af4a084d70a7a793cc51c47818c6b862ccb11d8316cc29c9f26ae5d543288b3392d36ad7556673621d25c6ad0dc469b8355d75ead3799d7806878c1f925dad789173c8e09d196b1197a300d73ecee78228c5def17c483138db50376c5d7c1ce0aaea3e7e90b37fa8d94f3418056f25aa12522356005678065b1f559b164758dfa470c0a63f6678400abba1983db0621422eac20d2f5406d4667f6d9175084641dd12180a1a1b048836864bb0336b9ad439d5ee059562352037473460e6885ac85362a5258d9438266a07085ae8044303049b2df6a0340f0203010001a321301f301d0603551d0e04160414fcc824f06f53f2a8c8efa1b97c8fcd43f5bcfff3300d06092a864886f70d01010b050003820101004f09129e656dc9ba39082615a112ce68a08383e518dbe9fe6c12d2b67fcf4287ee7d89faadbd189f31a374be641167ec366d2ae16b82a215fef9a33f468877a1d7edc395f5224fb0a4237fdfa4e960b42a99b082f66fbc37c991b7ee0306fdfd565e432ec6e11807e6c541aad33bd221fc793484519e932b82d963694df6605e2af3d66996188cc78d9e76a2e9b5d2ab60ea481384d327f3b62efef7eab79eb6df447cfadfc6a5c0717b9b3a22592080eec1822c22380f1fa37bc0119d30878f3b8a78d93da2d3d06fd6b45f4eac4afed8fac66393b04666e6436c86f0a68e31e3013634c1a6c93ed70256f3a3bf47506baab07bfb578d48922eaeea881bacd7";

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_jnistudy_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_jnistudy_MainActivity_formatName(JNIEnv *env, jobject thiz, jstring name) {
    jboolean isCopy = NULL;
    const char *jniName = env->GetStringUTFChars(name, &isCopy);
    std::string another = jniName;
    transform(another.begin(), another.end(), another.begin(), ::toupper);
    jstring formatName = env->NewStringUTF(another.c_str());
    env->ReleaseStringUTFChars(name,jniName);
    char *test = new char[1024*1024];
    char *nullTest = nullptr;
//    nullTest++;
    cout<<"nullTest"<< nullTest;
    return formatName;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_jnistudy_MainActivity_getValidToken(JNIEnv *env, jobject thiz, jobject contextObject){

    //调用java方法获取签名
    jclass native_class = env->GetObjectClass(contextObject);
    jmethodID pm_id = env->GetMethodID(native_class, "getPackageManager", "()Landroid/content/pm/PackageManager;");
    jobject pm_obj = env->CallObjectMethod(contextObject, pm_id);
    jclass pm_clazz = env->GetObjectClass(pm_obj);
// 得到 getPackageInfo 方法的 ID
    jmethodID package_info_id = env->GetMethodID(pm_clazz, "getPackageInfo","(Ljava/lang/String;I)Landroid/content/pm/PackageInfo;");
    jclass native_classs = env->GetObjectClass(contextObject);
    jmethodID mId = env->GetMethodID(native_classs, "getPackageName", "()Ljava/lang/String;");
    jstring pkg_str = static_cast<jstring>(env->CallObjectMethod(contextObject, mId));
// 获得应用包的信息
    jobject pi_obj = env->CallObjectMethod(pm_obj, package_info_id, pkg_str, 64);
// 获得 PackageInfo 类
    jclass pi_clazz = env->GetObjectClass(pi_obj);
// 获得签名数组属性的 ID
    jfieldID signatures_fieldId = env->GetFieldID(pi_clazz, "signatures", "[Landroid/content/pm/Signature;");
    jobject signatures_obj = env->GetObjectField(pi_obj, signatures_fieldId);
    jobjectArray signaturesArray = (jobjectArray)signatures_obj;
    jsize size = env->GetArrayLength(signaturesArray);
    jobject signature_obj = env->GetObjectArrayElement(signaturesArray, 0);
    jclass signature_clazz = env->GetObjectClass(signature_obj);
    jmethodID string_id = env->GetMethodID(signature_clazz, "toCharsString", "()Ljava/lang/String;");
    jstring str = static_cast<jstring>(env->CallObjectMethod(signature_obj, string_id));
    char *c_msg = (char*)env->GetStringUTFChars(str,0);
    //return str;
    if(strcmp(c_msg,RELEASE_SIGN)==0)//签名一致  返回合法的 api key，否则返回错误
    {
        return (env)->NewStringUTF(AUTH_KEY);
    }else
    {
        return (env)->NewStringUTF("error");
    }
}