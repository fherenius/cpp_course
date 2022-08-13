#ifndef INCLUDED_START_
#define INCLUDED_START_

#include "../awaiter/awaiter.h"
#include "../digit/digit.h"
#include "../done/done.h"
#include "../letter/letter.h"
#include "../promisebase.h"

// no operator co_await -> Start is the Awaiter

// start
class Start : public Awaiter
{
    // State struct, inherits from PromiseBase
    struct State : public PromiseBase<Start, State>
    {
    };

    std::coroutine_handle<State> d_handle; // Holds state of coroutine

  public:
    using promise_type = State; // Defines and controls behavior of coro
    using Handle       = std::coroutine_handle<State>; // Handler holds state

    explicit Start(Handle handle); // Constructor, no implicit conversion
    ~Start();                      // Destructor

    void go(); // Resume coroutine

    // this and the  members in Awaiter are required for Awaiters
    template <typename HandleType>
    std::coroutine_handle<State> await_suspend(HandleType &handle);
};

template <typename HandleType>
inline std::coroutine_handle<Start::State>
Start::await_suspend(HandleType &handle)
{
  return d_handle; // Stores handle in promise object
}
//=

extern Start g_start; // Initialise g_start

#endif
