#ifndef INCLUDED_LETTER_
#define INCLUDED_LETTER_

#include "../promisebase.h"
#include "../awaiter/awaiter.h"

#include "../start/start.h"
#include "../digit/digit.h"
#include "../done/done.h"

// this is also the Awaiter class
class Letter: public Awaiter
{
    struct State: public PromiseBase<Letter, State>
    {
    };

    std::coroutine_handle<State> d_handle;

    public:
        using promise_type = State;
        using Handle = std::coroutine_handle<State>;

        explicit Letter(Handle handle);
        ~Letter();

        template <typename HandleType>
        std::coroutine_handle<State> await_suspend(HandleType const &handle);
};

template <typename HandleType>
inline std::coroutine_handle<Letter::State> Letter::await_suspend(
                                                  HandleType const &handle)
{
    return d_handle;
}

extern Letter g_letter;

#endif
