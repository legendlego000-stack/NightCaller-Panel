#include <jni.h>
#include <string>
#include <vector>

// ==========================================
// 1. ЗМІННІ СТАНУ (Налаштування меню)
// Тут зберігаються значення твоїх повзунків і кнопок
// ==========================================

// Налаштування [ AIMBOT ]
bool aim_instant = false;
bool no_recoil = false;
int aim_fov = 30;         // Радіус захвату: від 30 до 180
int aim_target = 0;       // 0 - Голова, 1 - Шия

// Налаштування [ VISUALS ]
bool esp_box = false;
bool esp_line = false;
bool esp_hp = false;
bool esp_dist_limit = false; // Обмеження дистанції (150м)


// ==========================================
// 2. ІНТЕРФЕЙС МЕНЮ (JNI Bridge)
// Зв'язок твоєї панелі з цим C++ кодом
// ==========================================

extern "C" {

// Функція, яка передає список кнопок у твою панель
JNIEXPORT jobjectArray JNICALL
Java_com_soft_panel_GetFeatureList(JNIEnv *env, jobject context) {
    const char *features[] = {
        // --- Вкладка AIMBOT ---
        "Category_[ AIMBOT ]",
        "Toggle_Aim Lock (0.1ms)",
        "Toggle_No Recoil",
        "SeekBar_FOV Radius_30_180",
        "SeekBar_Target (0-Head/1-Neck)_0_1",

        // --- Вкладка VISUALS ---
        "Category_[ VISUALS ]",
        "Toggle_ESP Box",
