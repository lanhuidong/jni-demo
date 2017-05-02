#include "demo.h"
#include <string.h>
JNIEXPORT jint JNICALL Java_Demo_square(JNIEnv *env, jobject obj, jint num){
    return num * num;
}

JNIEXPORT jboolean JNICALL Java_Demo_reverse(JNIEnv *env, jobject obj, jboolean boolean){
    return !boolean;
}

JNIEXPORT jstring JNICALL Java_Demo_upper(JNIEnv *env, jobject obj, jstring string){
    const char *str = (*env)->GetStringUTFChars(env, string, 0);
    char cap[128];
    strcpy(cap, str);
    (*env)->ReleaseStringUTFChars(env, string, str);
    int i = 0;
    for(i = 0; cap[i] != '\0'; i++){
        cap[i] = cap[i] - 32;
    }
    return (*env)->NewStringUTF(env, cap);
}

JNIEXPORT jint JNICALL Java_Demo_sum(JNIEnv *env, jobject obj, jintArray array){
    int i, sum = 0;
    jsize len = (*env)->GetArrayLength(env, array);
    jint *body = (*env)->GetIntArrayElements(env, array, 0);
    for(i = 0; i < len; i++) {
        sum += body[i];
    }
    (*env)->ReleaseIntArrayElements(env, array, body, 0);
    return sum;
}
