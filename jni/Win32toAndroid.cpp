#include <jni.h>
#include <android/log.h>

#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

#include <Win32toAndroid.h>
#include <Engine.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define  LOG_TAG    "libWin32toAndroid"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

//Globals
//Engine * engine;
AAssetManager* assetMgr;
Engine* engine;
bool setupGraphics(int w, int h) {
	//init globals!!!
    LOGI("setupGraphics(%d, %d)", w, h);
    glViewport(0, 0, w, h);
    return true;
}

void renderFrame() 
{
	engine->Update();
	engine->Draw();
}


extern "C" {
    JNIEXPORT void JNICALL Java_com_android_Win32toAndroid_Win32toAndroidLib_init(JNIEnv * env, jobject obj,  jint width, jint height);
    JNIEXPORT void JNICALL Java_com_android_Win32toAndroid_Win32toAndroidLib_step(JNIEnv * env, jobject obj);
	JNIEXPORT void JNICALL Java_com_android_Win32toAndroid_Win32toAndroidLib_GetManager(JNIEnv* env, jclass clazz, jobject assetManager);
	JNIEXPORT void JNICALL Java_com_android_Win32toAndroid_Win32toAndroidLib_inputEvent(JNIEnv*  env, jobject  thiz, jint down, jint x, jint y);
};

JNIEXPORT void JNICALL Java_com_android_Win32toAndroid_Win32toAndroidLib_inputEvent( JNIEnv*  env, jobject  thiz, jint down, jint x, jint y )
{
	LOGI("inputEvent down=%d x=%d y=%d", down, x, y);
}

JNIEXPORT void JNICALL Java_com_android_Win32toAndroid_Win32toAndroidLib_GetManager(JNIEnv* env, jclass clazz, jobject assetManager)
{
  AAssetManager* mgr = AAssetManager_fromJava(env, assetManager);
  assetMgr = mgr;
}

JNIEXPORT void JNICALL Java_com_android_Win32toAndroid_Win32toAndroidLib_init(JNIEnv * env, jobject obj,  jint width, jint height)
{
	engine = new Engine();
    setupGraphics(width, height);
}

JNIEXPORT void JNICALL Java_com_android_Win32toAndroid_Win32toAndroidLib_step(JNIEnv * env, jobject obj)
{
    renderFrame();
}
