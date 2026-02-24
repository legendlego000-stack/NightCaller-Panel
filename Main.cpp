#include <jni.h>
#include <string>
#include <vector>

// =================================================================
// 1. ПЕРЕМІННІ СТАНУ (Тут зберігаються твої налаштування)
// =================================================================

// Категорія: AIMBOT
bool aim_lock = false;
bool no_recoil = false;
int aim_fov = 30;         // Початкове значення: 30
int aim_target = 0;       // 0 - Head, 1 - Neck

// Категорія: VISUALS
bool esp_box = false;
bool esp_line = false;
bool esp_hp = false;
bool esp_dist_limit = false; 
int max_dist = 150;       // Максимальна дистанція 150м

extern "C" {

// =================================================================
// 2. ПЕРЕДАЧА СПИСКУ ФУНКЦІЙ (Малювання меню)
// =================================================================
JNIEXPORT jobjectArray JNICALL
Java_com_soft_panel_GetFeatureList(JNIEnv *env, jobject context) {
    const char *features[] = {
        // Розділ АІМ
        "Category_[ AIMBOT ]",
        "Toggle_Aim Lock (0.1ms)",
        "Toggle_No Recoil",
        "SeekBar_FOV Radius_30_180",
        "SeekBar_Target (0-Head/1-Neck)_0_1",
        
        // Розділ ВХ
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
        // ВИПРАВЛЕНО: Використовуємо індекс 'i' для ітерації
        env->SetObjectArrayElement(jfeatures, i, env->NewStringUTF(features[i]));
    }
    return jfeatures;
}

// =================================================================
// 3. ОБРОБКА КНОПОК (Щоб меню "запам'ятовувало" натискання)
// =================================================================
JNIEXPORT void JNICALL
Java_com_soft_panel_OnFeatureClick(JNIEnv *env, jobject context, jint featureNum, jboolean isActive) {
    // Номери відповідають порядку у GetFeatureList (рахуючи з 0)
    switch (featureNum) {
        case 1: aim_lock = isActive; break;
        case 2: no_recoil = isActive; break;
        case 6: esp_box = isActive; break;
        case 7: esp_line = isActive; break;
        case 8: esp_hp = isActive; break;
        case 9: esp_dist_limit = isActive; break;
    }
}

// =================================================================
// 4. ОБРОБКА ПОВЗУНКІВ (Щоб цифри FOV змінювалися)
// =================================================================
JNIEXPORT void JNICALL
Java_com_soft_panel_OnSeekBarChange(JNIEnv *env, jobject context, jint featureNum, jint value) {
    switch (featureNum) {
        case 3: aim_fov = value; break;    // Змінює FOV від 30 до 180
        case 4: aim_target = value; break; // Змінює ціль (0 або 1)
    }
}

} // Кінець extern "C"
