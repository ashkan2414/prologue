#ifdef _WIN32
    #define PROLOGUE_PLATFORM_WINDOWS
#elif __ANDROID__
    #define PROLOGUE_PLATFORM_ANDROID
#elif __linux__
    #define PROLOGUE_PLATFORM_LINUX
#elif __APPLE__
    #define PROLOGUE_PLATFORM_APPLE
#elif __UNIX__
    #define PROLOGUE_PLATFORM_UNIX
#endif

#ifndef __cplusplus
#error C++ is the only language supported
#endif

#if __cplusplus == 199711L
    #define PROLOGUE_CPP_VER 98
    #define PROLOGUE_CPP_VER_98
#elif __cplusplus == 201103L
    #define PROLOGUE_CPP_VER 11
    #define PROLOGUE_CPP_VER_11
#elif __cplusplus == 201402L
    #define PROLOGUE_CPP_VER 14
    #define PROLOGUE_CPP_VER_14
#elif __cplusplus == 201703L
    #define PROLOGUE_CPP_VER 17
    #define PROLOGUE_CPP_VER_17
#elif __cplusplus == 202002L
    #define PROLOGUE_CPP_VER 20
    #define PROLOGUE_CPP_VER_20
#elif __cplusplus == 202101L
    #define PROLOGUE_CPP_VER 23
    #define PROLOGUE_CPP_VER_23
#else
    #define PROLOGUE_CPP_VER 0
#endif

#define PROLOGUE_NO_VTABLE __declspec(novtable)

