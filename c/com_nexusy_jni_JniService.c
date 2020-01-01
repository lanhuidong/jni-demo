#include "com_nexusy_jni_JniService.h"

jclass c_list;
jmethodID m_list_get;
jmethodID m_list_size;

jclass c_person;
jfieldID f_person_age;
jmethodID m_person_get_name;

JNIEXPORT void JNICALL Java_com_nexusy_jni_JniService_init
  (JNIEnv *env, jobject obj){
  /*
   * FindClass，GetMethodID，GetFieldID这些方法速度很快，如果处于性能考虑可不用缓存，这里只是为了后续如有多处使用时方便
   * jclass缓存需要全局引用，否则在多线程环境下可能会造成JVM奔溃
   */
  c_list = (*env)->NewGlobalRef(env, (*env)->FindClass(env, "java/util/List"));
  m_list_get = (*env)->GetMethodID(env, c_list, "get", "(I)Ljava/lang/Object;");
  m_list_size = (*env)->GetMethodID(env, c_list, "size", "()I");

  c_person = (*env)->NewGlobalRef(env, (*env)->FindClass(env, "com/nexusy/jni/Person"));
  f_person_age = (*env)->GetFieldID(env, c_person, "age", "I");
  m_person_get_name = (*env)->GetMethodID(env, c_person, "getName", "()Ljava/lang/String;");
}

JNIEXPORT void JNICALL Java_com_nexusy_jni_JniService_uninit
  (JNIEnv *env, jobject obj){
  (*env)->DeleteGlobalRef(env, c_list);
  (*env)->DeleteGlobalRef(env, c_person);
}

JNIEXPORT jint JNICALL Java_com_nexusy_jni_JniService_square
  (JNIEnv *env, jobject obj, jint num){
    return num * num;
}

JNIEXPORT jint JNICALL Java_com_nexusy_jni_JniService_sum
  (JNIEnv *env, jobject obj, jintArray array){
    int i, sum = 0;
    jsize len = (*env)->GetArrayLength(env, array);
    jint *body = (*env)->GetIntArrayElements(env, array, 0);
    for(i = 0; i < len; i++) {
        sum += body[i];
    }
    (*env)->ReleaseIntArrayElements(env, array, body, JNI_ABORT);
    return sum;
}

JNIEXPORT jstring JNICALL Java_com_nexusy_jni_JniService_getSuffix
  (JNIEnv *env, jobject obj, jobject img){
  /*
   * 直接获取内存地址，减少拷贝，对于大数组性能提升显著
   */
  unsigned char *content = (*env)->GetDirectBufferAddress(env, img);
  char *suffix;
  // "cafe babe"共4字节
  if(content[0] == 202 && content[1] == 254 && content[2] == 186 && content[3] == 190){
      suffix = ".class";
      return (*env)->NewStringUTF(env, suffix);
  }
  suffix = "UNKNOWN";
  return (*env)->NewStringUTF(env, suffix);
}

JNIEXPORT void JNICALL Java_com_nexusy_jni_JniService_parse
  (JNIEnv *env, jobject obj, jobject list){
  jint size = (*env)->CallIntMethod(env, list, m_list_size);
  jint i;
  for(i = 0; i < size; i++){
      jobject person = (*env)->CallObjectMethod(env, list, m_list_get, i);
      jint age = (*env)->GetIntField(env, person, f_person_age);
      jstring name = (*env)->CallObjectMethod(env, person, m_person_get_name);
      jsize len = (*env)->GetStringUTFLength(env, name);
      (*env)->SetIntField(env, person, f_person_age, len);
      const char *cname = (*env)->GetStringUTFChars(env, name, 0);
      printf("person name: %s\n", cname);
      (*env)->ReleaseStringUTFChars(env, name, cname);
  }
}