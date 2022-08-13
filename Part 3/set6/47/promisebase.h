#ifndef INCLUDED_PROMISEBASE_
#define INCLUDED_PROMISEBASE_

// base
#include <coroutine>
#include <cstddef>
#include <future>

// Base class for any Handler/State objects
// Implements base functions
template <typename Handler, typename State> struct PromiseBase
{
    // Returns handler (return object) during creation of coroutine
    Handler get_return_object();

    // Suspends coroutine after being created, before running the coroutine
    static std::suspend_always initial_suspend();
    // Called to suspend when either a co_return statement or an unhandled
    // exception is encountered.
    static std::suspend_always final_suspend() noexcept;
    // Called from catch-block of an exception, final_suspend() called after
    static void unhandled_exception();
    // Called when co_return statement is reached
    static void return_void();
};

template <typename Handler, typename State>
inline void PromiseBase<Handler, State>::return_void()
{
}

template <typename Handler, typename State>
inline std::suspend_always PromiseBase<Handler, State>::initial_suspend()
{
  return {}; // Return empty struct
}

template <typename Handler, typename State>
inline std::suspend_always PromiseBase<Handler, State>::final_suspend() noexcept
{
  return {}; // Return empty struct
}

template <typename Handler, typename State>
inline void PromiseBase<Handler, State>::unhandled_exception()
{
  // Rethrow exception to outside of coroutine
  std::rethrow_exception(std::current_exception());
}

template <typename Handler, typename State>
inline Handler PromiseBase<Handler, State>::get_return_object()
{
  return Handler { std::coroutine_handle<State>::from_promise(
      static_cast<State &>(*this)) };
}
//=
#endif
