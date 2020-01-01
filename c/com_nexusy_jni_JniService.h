/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_nexusy_jni_JniService */

#ifndef _Included_com_nexusy_jni_JniService
#define _Included_com_nexusy_jni_JniService
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_nexusy_jni_JniService
 * Method:    init
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_nexusy_jni_JniService_init
  (JNIEnv *, jobject);

/*
 * Class:     com_nexusy_jni_JniService
 * Method:    uninit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_nexusy_jni_JniService_uninit
  (JNIEnv *, jobject);

/*
 * Class:     com_nexusy_jni_JniService
 * Method:    square
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_nexusy_jni_JniService_square
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_nexusy_jni_JniService
 * Method:    sum
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_com_nexusy_jni_JniService_sum
  (JNIEnv *, jobject, jintArray);

/*
 * Class:     com_nexusy_jni_JniService
 * Method:    getSuffix
 * Signature: (Ljava/nio/ByteBuffer;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_nexusy_jni_JniService_getSuffix
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_nexusy_jni_JniService
 * Method:    parse
 * Signature: (Ljava/util/List;)V
 */
JNIEXPORT void JNICALL Java_com_nexusy_jni_JniService_parse
  (JNIEnv *, jobject, jobject);

#ifdef __cplusplus
}
#endif
#endif