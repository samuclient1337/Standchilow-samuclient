#include <jni.h>
#include <android/log.h>
#include <cmath>

#define LOG_TAG "MyCheat"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

bool g_EspEnabled = false;
bool g_AimEnabled = false;

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_games_VkQualityTest_VkQualityTestActivity_toggleESP(JNIEnv*, jobject, jboolean state) {
    g_EspEnabled = state;
    LOGI("ESP: %d", state);
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_games_VkQualityTest_VkQualityTestActivity_toggleAim(JNIEnv*, jobject, jboolean state) {
    g_AimEnabled = state;
    LOGI("Aim: %d", state);
}

extern "C" JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    LOGI("Library loaded!");
    return JNI_VERSION_1_6;
}
