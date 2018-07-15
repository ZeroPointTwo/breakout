
#include <cstdarg>
#include <cstdio>

#include "custom_assert.h"

static bool asserts_enabled = true;
static bool assert_callback_enabled = true;
static fp_assert_callback assert_callback = nullptr;
static void* callback_data = nullptr;

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat-nonliteral" // Disable warning caused by clang bug. vsprintf needs a non-literal
#endif

void Assert_Enable(bool enabled)
{
    asserts_enabled = enabled;
}

void Assert_EnableCallback(bool enabled)
{
    assert_callback_enabled = enabled;
}

bool Assert_Enabled(void)
{
    return asserts_enabled;
}

bool Assert_CallbackEnabled(void)
{
    return assert_callback_enabled;
}

bool _Assert(bool* local_enabled, bool* local_callbacks_enabled, bool expression, const char* expression_string, const char* message_format, ...)
{
    auto should_break = false;

    if(!expression && assert_callback_enabled && *local_callbacks_enabled)
    {
        if(assert_callback_enabled && *local_callbacks_enabled)
        {
            char buffer[512];
            auto buffer_ptr = &buffer[0];
            va_list args;
            // cppcheck-suppress uninitvar
            // cppcheck-suppress va_list_usedBeforeStarted
            auto args_ptr = &args[0];
            va_start(args_ptr, message_format);
            vsprintf(buffer_ptr, message_format, args_ptr);
            va_end(args_ptr);

            printf("Assert (%s): %s\n", expression_string, buffer_ptr);
            fflush(stdout);

            if(assert_callback != nullptr)
            {
                assert_callback(local_enabled, local_callbacks_enabled, expression_string, buffer_ptr, callback_data);
            }
        }

        if(asserts_enabled && *local_enabled)
        {
            should_break = true;
        }
    }

    return should_break;
}

void Assert_SetCallback(fp_assert_callback fp, void *data)
{
    assert_callback = fp;
    callback_data = data;
}

#ifdef __clang__
#pragma clang diagnostic pop
#endif
