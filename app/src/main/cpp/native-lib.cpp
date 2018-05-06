#include <jni.h>
#include <string>
#include <openssl/crypto.h>
#include <openssl/md5.h>

extern "C" JNIEXPORT jstring

JNICALL
Java_tk_stystudio_fileencryptor_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = OpenSSL_version(OPENSSL_VERSION);
    return env->NewStringUTF(hello.c_str());
}
