#include "Person.h"

#include <jni.h>
#include <string>

// 将jstring转char
char * _Jstring2CStr( JNIEnv * env, jstring jstr )
{
    char * rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("GB2312");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr= (jbyteArray)env->CallObjectMethod(jstr,mid,strencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte * ba = env->GetByteArrayElements(barr,JNI_FALSE);
    if(alen > 0)
    {
        rtn = (char*)malloc(alen+1); //new char[alen+1];
        memcpy(rtn,ba,alen);
        rtn[alen]=0;
    }
    env->ReleaseByteArrayElements(barr,ba,0);

    return rtn;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_ailee_tutorialsjnilib_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jlong JNICALL
Java_com_ailee_tutorialsjnilib_PersonInterface_createNativeObjectJNI(JNIEnv *env, jobject thiz) {
    jlong result;
    result = (jlong) new Person();
    return result;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ailee_tutorialsjnilib_PersonInterface_setNameJNI(JNIEnv *env, jobject thiz, jlong addr,
                                                          jstring name) {
    // jString 转 cString
    char * cName = _Jstring2CStr(env, name);
    // 对象指针调用方法
    ((Person*)addr)->setName(std::string(cName));
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ailee_tutorialsjnilib_PersonInterface_setAgeJNI(JNIEnv *env, jobject thiz, jlong addr,
                                                         jint age) {
    ((Person*)addr)->setAge(age);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_ailee_tutorialsjnilib_PersonInterface_getNameJNI(JNIEnv *env, jobject thiz, jlong addr) {
    std::string cName = ((Person*)addr)->getName();
    return env->NewStringUTF(cName.c_str());
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_ailee_tutorialsjnilib_PersonInterface_getAgeJNI(JNIEnv *env, jobject thiz, jlong addr) {
    return ((Person*)addr)->getAge();
}