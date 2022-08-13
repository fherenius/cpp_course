//JB: ?
//JB: The Handler leaks. Easy fix.

#ifndef INCLUDED_HANDLER_H
#define INCLUDED_HANDLER_H

#include <coroutine>
#include <future>

class Handler               // Handler class for caller to use coroutine
{
    class State             // In-Handler State class to handle coro state
    {
        size_t d_value;

      public:
        
        Handler get_return_object();
        
        std::suspend_always yield_value(size_t value);

        static std::suspend_always initial_suspend();
        static std::suspend_always final_suspend() noexcept;
        static void unhandled_exception();
        
        static void return_void();

        size_t value() const;
        
    };

  private:
    using Handle = std::coroutine_handle<State>;
    Handle d_handle;

  public:
    using promise_type = State;         // Fullfill promise of having a
                                        // promise_type
    explicit Handler(Handle handle);

    size_t next();

};

    // Coroutine fwd

Handler basicCoro(size_t value);

    // Definitions of Handler member functions

inline Handler::Handler(Handler::Handle handle)
:
    d_handle(handle)
{}

inline size_t Handler::next()
{
    d_handle.resume();
    return d_handle.promise().value();
}


    // Definitions of Handler::State member functions

inline Handler Handler::State::get_return_object()
{
    return Handler { Handler::Handle::from_promise(*this) };
}

inline std::suspend_always Handler::State::yield_value(size_t value)
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
    return {};
}

inline void Handler::State::unhandled_exception()
{
    std::rethrow_exception(std::current_exception());
}

inline void Handler::State::return_void()
{}


inline size_t Handler::State::value() const
{
    return d_value;
}


#endif

