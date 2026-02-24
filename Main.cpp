#include <jni.h>
#include <string>
#include <vector>

// --- ЗМІННІ ДЛЯ ЗБЕРЕЖЕННЯ НАЛАШТУВАНЬ ---
bool aim_lock = false;
bool no_recoil = false;
int aim_fov = 30;
int aim_target = 0; // 0-Head, 1-Neck

bool esp_box = false;
bool esp_line = false;
bool esp_hp = false;
bool esp_dist_limit = false;

extern "C" {

// 1. ПЕРЕДАЧА СПИСКУ ФУНКЦІЙ У МЕНЮ
JNIEXPORT jobjectArray JNICALL
Java_com_soft_panel_GetFeatureList(JNIEnv *env, jobject context) {
    const char *features[] = {
        "Category_[ AIMBOT ]",
        "Toggle_Aim Lock (0.1ms)",
        "Toggle_No Recoil",
        "SeekBar_FOV Radius_30_180",
        "SeekBar_Target (0-Head/1-Neck)_0_1",
        
        "Category_[ VISUALS ]",
        "Toggle_ESP Box",
        "Toggle_ESP Line",
        "Toggle_ESP Health",
        "Toggle_Limit Distance (150m)"
    };

    int rowCount = sizeof(features) / sizeof(features[0]);
    jclass stringClass = env->FindClass("java/lang/String");
    jobjectArray jfeatures = env->NewObjectArray(rowCount, stringClass, env->NewStringUTF(""));

    for (int i = 0; i < rowCount; i++) {
        env->SetObjectArrayElement(jfeatures, i, env->NewStringUTF(features[i]));
    }
    return jfeatures;
}

// 2. ОБРОБКА КНОПОК
JNIEXPORT void JNICALL
Java_com_soft_panel_OnFeatureClick(JNIEnv *env, jobject context, jint featureNum, jboolean isActive) {
    // Тут буде логіка активації функцій у майбутньому
}

// 3. ОБРОБКА ПОВЗУНКІВ
JNIEXPORT void JNICALL
Java_com_soft_panel_OnSeekBarChange(JNIEnv *env, jobject context, jint featureNum, jint value) {
    // Тут буде зміна значень FOV та дистанції
}

} // Кінець коду
