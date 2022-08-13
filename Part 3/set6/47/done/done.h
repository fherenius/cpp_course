#ifndef INCLUDED_DONE_
#define INCLUDED_DONE_

#include "../promisebase.h"
#include "../awaiter/awaiter.h"

class Done: public Awaiter
{
    struct State: public PromiseBase<Done, State>
    {};

    std::coroutine_handle<State> d_handle;
    static size_t s_count;

    public:
        using promise_type = State;
        using Handle = std::coroutine_handle<State>;

        explicit Done(Handle handle);
        ~Done();

        template <typename HandleType>
        std::coroutine_handle<State> await_suspend(HandleType const &handle);
};

template <typename HandleType>
inline std::coroutine_handle<Done::State> Done::await_suspend(
                                              HandleType const &handle)
{
    return d_handle;
}

extern Done g_done;

#endif
