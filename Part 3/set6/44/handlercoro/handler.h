//JB: ?
//JB: Another trivial leak, but otherwise fine.
//JB: There is a bit much inlining though. But hey, you're experienced C++
//JB: programmers now. You probably know best.

#ifndef INCLUDED_HANDLER_H
#define INCLUDED_HANDLER_H

#include <coroutine>
#include <future>
#include <iostream>

class Handler               // Handler class for caller to use coroutine
{
    class State             // In-Handler State class to handle coro state
    {
        bool d_valid = true;
        int d_value;

      public:

        Handler get_return_object();
        
        std::suspend_always yield_value(int value);

        static std::suspend_always initial_suspend();
        std::suspend_always final_suspend() noexcept;   // Non-static to change
                                                        // d_valid
        static void unhandled_exception();
        
        static void return_void();

        bool valid() const;
        int value() const;
        
    };

  private:
    using Handle = std::coroutine_handle<State>;
    Handle d_handle;

  public:
    using promise_type = State;         // Fullfill promise of having a
                                        // promise_type
    explicit Handler(Handle handle);

    bool next(int *iptr);

};

    // Coroutine fwd

Handler handlerCoro(char const *fileName);

    // Definitions of Handler member functions

inline Handler::Handler(Handler::Handle handle)
:
    d_handle(handle)
{}

inline bool Handler::next(int *iptr)
{
    d_handle.resume();

    if (d_handle.promise().valid())
        *iptr = d_handle.promise().value();

    return d_handle.promise().valid();
}


    // Definitions of Handler::State member functions

inline Handler Handler::State::get_return_object()
{
    return Handler { Handler::Handle::from_promise(*this) };
}

inline std::suspend_always Handler::State::yield_value(int value)
{
    d_value = value;
    return {};
}

inline std::suspend_always Handler::State::initial_suspend()
{
    return {};
}


inline std::suspend_always Handler::State::final_suspend() noexcept
{
    d_valid = false;
    return {};
}

inline void Handler::State::unhandled_exception()
{
    std::rethrow_exception(std::current_exception());
}

inline void Handler::State::return_void()
{}


inline int Handler::State::value() const
{
    return d_value;
}

inline bool Handler::State::valid() const
{
    return d_valid;
}

#endif

