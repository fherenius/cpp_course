//JB: 1
//JB: It does create the iterator and use it.
//JB: I'm assuming you'll fix the leak in the other two exercises that have it.
#ifndef INCLUDED_HANDLER_H
#define INCLUDED_HANDLER_H

#include <coroutine>
#include <future>

class Handler               // Handler class for caller to use coroutine
{
    class State             // In-Handler State class to handle coro state
    {
        size_t d_value;
        size_t d_nIterations;
        
      public:

            // State gets the start value and nr of iterations needed
            // propels nr of iterations to Handler
        State(size_t value, size_t iterations);
        
        Handler get_return_object();
        
        std::suspend_always yield_value(size_t value);

        static std::suspend_always initial_suspend();
        static std::suspend_always final_suspend() noexcept;
        static void unhandled_exception();
        
        static void return_void();

        size_t value() const;
        
    };

  public:
    
    class Iterator
    {
            // Needs a non-equality operator to work with RBFL
        friend bool operator!=(Iterator const &lhs, Iterator const &rhs);
        
        Handler &d_handler;

        size_t d_iterations;
      
      public:
        Iterator(Handler &handler, size_t iterations = 0);

        Iterator &operator++();
        size_t operator*() const;
    };

    friend class Iterator;

  private:
    using Handle = std::coroutine_handle<State>;
    Handle d_handle;

    size_t d_nIterations;

  public:
    using promise_type = State;         // Fullfill promise of having a
                                        // promise_type
    
        // Takes extra argument to know how much iterations need to be
        // performed
    explicit Handler(Handle handle, size_t iterations);

    size_t next();

    Iterator begin();                   // Get begin iterator
    Iterator end();                     // Get iterator to act as barrier

};

    // Coroutine fwd
Handler basicCoro(size_t value, size_t iterations);

    // Definitions of Handler member functions

inline Handler::Handler(Handler::Handle handle, size_t iterations)
:
    d_handle(handle), d_nIterations(iterations)
{}

inline size_t Handler::next()
{
    d_handle.resume();
    return d_handle.promise().value();
}

inline Handler::Iterator Handler::begin()
{
    return Iterator{ *this };                   // Return begin iterator
}

inline Handler::Iterator Handler::end()
{
    return Iterator{ *this, d_nIterations };    // End iterator has total
                                                // iteration value stored
}

    // Definitions of Handler::Iterator member functions

inline Handler::Iterator::Iterator(Handler &handler, size_t iterations)
:
    d_handler(handler), d_iterations(iterations)
{}

inline Handler::Iterator &          // Defined inline to keep away from
Handler::Iterator::operator++()     // function calls
{
    d_handler.d_handle.resume();    // Resume the coroutine
    ++d_iterations;                 // Increase iterations performed by this
    return *this;
}

inline size_t
Handler::Iterator::operator*() const
{
    return d_handler.d_handle.promise().value();    // Return value from State
}

inline bool 
operator!=(Handler::Iterator const &lhs, Handler::Iterator const &rhs)
{
    return lhs.d_iterations != rhs.d_iterations;
}

    // Definitions of Handler::State member functions

inline Handler::State::State(size_t value, size_t iterations)
:
    d_value(value), d_nIterations(iterations)
{}


inline Handler Handler::State::get_return_object()
{
    return Handler { Handler::Handle::from_promise(*this),
                     d_nIterations };
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

