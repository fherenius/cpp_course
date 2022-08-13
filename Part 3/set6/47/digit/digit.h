#ifndef INCLUDED_DIGIT_
#define INCLUDED_DIGIT_

#include "../promisebase.h"
#include "../awaiter/awaiter.h"

#include "../start/start.h"
#include "../letter/letter.h"
#include "../done/done.h"

class Digit: public Awaiter
{
    struct State: public PromiseBase<Digit, State>
    {
    };

    std::coroutine_handle<State> d_handle;

    public:
        using promise_type = State;
        using Handle = std::coroutine_handle<State>;

        explicit Digit(Handle handle);
        ~Digit();

        template <typename HandleType>
        std::coroutine_handle<State> await_suspend(HandleType const &handle);
};

template <typename HandleType>
inline std::coroutine_handle<Digit::State> Digit::await_suspend(
                                                HandleType const &handle)
{
    return d_handle;
}

extern Digit g_digit;

#endif
