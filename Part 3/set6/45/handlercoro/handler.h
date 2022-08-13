#ifndef INCLUDED_HANDLER_H
#define INCLUDED_HANDLER_H

#include "../promisebase/promisebase.h"

class Handler               // Handler class for caller to use coroutine
{
    class State : public PromiseBase<Handler, State>
    {
        bool d_valid = true;
        int d_value;

      public:

        std::suspend_always yield_value(int value);
            
            // Non default override of function of PromiseBase
        std::suspend_always final_suspend() noexcept;

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

inline std::suspend_always Handler::State::yield_value(int value)
{
    d_value = value;
    return {};
}

inline std::suspend_always Handler::State::final_suspend() noexcept
{
    d_valid = false;
    return { };
}

inline int Handler::State::value() const
{
    return d_value;
}

inline bool Handler::State::valid() const
{
    return d_valid;
}

#endif

