#ifndef INCLUDED_AWAITER_
#define INCLUDED_AWAITER_

// class
struct Awaiter
{
    // Halts coroutine, but does not suspend. This can be used instead of
    // await_suspend when tasks are done synchronously and the coroutine
    // does not need to store it's current state somewhere to fetch once
    // it's being resumed again.
    static bool await_ready();
    // Resumes coroutine again after suspension or halting.
    static void await_resume();
};

inline bool Awaiter::await_ready()
{
  return false;
}

inline void Awaiter::await_resume() {}
//=

#endif
