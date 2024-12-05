#include <jni.h>
#include <string.h>
#include <regex.h>

// Проверка, что строка является валидным email
int isValidEmail(const char *email) {
    regex_t regex; //структура, которая представляет собой скомпилированное регулярное выражение.
    int ret;

    // Паттерн для email
    const char *pattern = "^[a-zA-Z0-9_]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";

    ret = regcomp(&regex, pattern, REG_EXTENDED);
    if (ret) {
        return 0; // Не удалось скомпилировать регулярное выражение
    }

    ret = regexec(&regex, email, 0, NULL, 0);
    regfree(&regex);
    return ret == 0;
}

// Проверка, что пароль имеет хотя бы 6 символов
int isValidPassword(const char *password) {
    return strlen(password) >= 6;
}

// Проверка, что имя не равно "admin"
int isValidUsername(const char *username) {
    return strcmp(username, "admin") != 0;
}

// Основная функция для валидации всех данных
extern "C" JNIEXPORT jint JNICALL
Java_com_example_myapplication_RegisterActivity_validateInputsFromNative(JNIEnv *env, jobject thiz, jstring email, jstring password, jstring username) {
    /*
     * JNIEnv *env: Указатель на интерфейс JNI, используемый для взаимодействия с JVM (например, вызов методов, работа со строками).
     * jobject thiz: Это объект Java, из которого вызывается метод (экземпляр RegisterActivity).
     */
    //Преобразование jstring в C-строки
    const char *emailStr = env->GetStringUTFChars(email, nullptr);
    const char *passwordStr = env->GetStringUTFChars(password, nullptr);
    const char *usernameStr = env->GetStringUTFChars(username, nullptr);

    if (emailStr == nullptr || passwordStr == nullptr || usernameStr == nullptr) {
        return 0; // Ошибка: строки NULL
    }

    // Выполняем проверки
    if (strlen(emailStr) == 0 || strlen(passwordStr) == 0 || strlen(usernameStr) == 0) {
        env->ReleaseStringUTFChars(email, emailStr);
        env->ReleaseStringUTFChars(password, passwordStr);
        env->ReleaseStringUTFChars(username, usernameStr);
        return 0; // Ошибка: поля не должны быть пустыми
    }

    if (!isValidEmail(emailStr)) {
        env->ReleaseStringUTFChars(email, emailStr);
        env->ReleaseStringUTFChars(password, passwordStr);
        env->ReleaseStringUTFChars(username, usernameStr);
        return 1; // Некорректный email
    }

    if (!isValidPassword(passwordStr)) {
        env->ReleaseStringUTFChars(email, emailStr);
        env->ReleaseStringUTFChars(password, passwordStr);
        env->ReleaseStringUTFChars(username, usernameStr);
        return 2; // Пароль слишком короткий
    }

    if (!isValidUsername(usernameStr)) {
        env->ReleaseStringUTFChars(email, emailStr);
        env->ReleaseStringUTFChars(password, passwordStr);
        env->ReleaseStringUTFChars(username, usernameStr);
        return 3; // Имя занято
    }

    // Освобождаем память
    env->ReleaseStringUTFChars(email, emailStr);
    env->ReleaseStringUTFChars(password, passwordStr);
    env->ReleaseStringUTFChars(username, usernameStr);

    return 4; // Все проверки пройдены успешно
}

