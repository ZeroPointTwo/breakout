
#pragma once

typedef void (*fp_assert_callback)(bool* local_enabled, bool* local_callbacks_enabled, const char* expression_string, const char* message, void* data);

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic" // Disable warning caused by varadic macros
#endif

#ifndef NDEBUG
    #ifdef _MSC_VER
        #define debug_break __debugbreak
    #else
        #include <csignal>
        #define debug_break std::raise(SIGTRAP)
    #endif

    void Assert_Enable(bool enabled);
    void Assert_EnableCallback(bool enabled);

    bool Assert_Enabled(void);
    bool Assert_CallbackEnabled(void);

    bool _Assert(bool* local_enabled, bool* local_callbacks_enabled, bool expression, const char* expression_string, const char* message_format, ...);
    void Assert_SetCallback(fp_assert_callback fp, void *data);

    // Using a macro so that the debugger breaks into the correct callstack function and each assertion can be enabled
    // or disabled individually.
    #define Assert(_exp, ...) do {  static auto local_enable = true;                                                \
                                    static auto local_callbacks_enabled = true;                                     \
                                    auto r = (_exp);                                                                \
                                    if(_Assert(&local_enable, &local_callbacks_enabled, r, static_cast<const char*>(#_exp), __VA_ARGS__))   \
                                    { debug_break; }                                                                \
                                    } while(false)
#else
    void Assert_Enable(bool enabled);
    void Assert_EnableCallback(bool enabled);

    bool Assert_Enabled(void);
    bool Assert_CallbackEnabled(void);

    #define Assert(exp, ...)
#endif

#ifdef __clang__
#pragma clang diagnostic pop
#endif

