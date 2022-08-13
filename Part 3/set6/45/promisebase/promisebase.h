//JB: 1
#ifndef INCLUDED_PROMISE_BASE
#define INCLUDED_PROMISE_BASE

#define tHDR_ template <typename Handler, typename State>

#include <cstddef>
#include <future>
#include <coroutine>

template <typename Handler, typename State>    // Header kept here for clarity
struct PromiseBase                             // Offers default implementation
{                                              // of the required coroutine
    Handler get_return_object();               // functions

    static std::suspend_always initial_suspend();
    static std::suspend_always final_suspend() noexcept;
    static void unhandled_exception();
    static void return_void();

};

tHDR_ inline
Handler PromiseBase<Handler, State>::get_return_object()
{
        // Use object itself as promise for coroutine handle
        // ensuring it is seen as a State object through the cast
    return Handler { std::coroutine_handle<State>::
                     from_promise(static_cast<State &>(*this))
                   };
}

tHDR_ inline
std::suspend_always PromiseBase<Handler, State>::initial_suspend()
{
    return { };
}

tHDR_ inline
std::suspend_always PromiseBase<Handler, State>::final_suspend() noexcept
{
    return { };
}

tHDR_ inline
void PromiseBase<Handler, State>::unhandled_exception()
{
    std::rethrow_exception(std::current_exception());
}

tHDR_ inline
void PromiseBase<Handler, State>::return_void()
{}

#undef tHDR_

#endif

