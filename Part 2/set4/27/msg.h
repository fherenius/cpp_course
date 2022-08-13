#ifndef INCLUDED_MSG_H_
#define INCLUDED_MSG_H_

#include <cstddef>

enum class Msg
{
    NONE = 0,
    DEBUG   = 1 << 0,
    INFO    = 1 << 1,
    NOTICE  = 1 << 2,
    WARNING = 1 << 3,
    ERR     = 1 << 4,
    CRIT    = 1 << 5,
    ALERT   = 1 << 6,
    EMERG   = 1 << 7,
    ALL = (1 << 8) - 1,
};

class MsgWrapper
{
    Msg d_msg;

    public:
        MsgWrapper(Msg msg);
        constexpr size_t valueOf(Msg msg);
        constexpr Msg beginMsg();
        constexpr Msg endMsg();
        Msg &operator++();        // no ++ if Msg == NONE
        constexpr bool operator!();
        constexpr Msg operator|(Msg rhs);
        constexpr Msg operator&(Msg rhs);
        constexpr Msg operator^(Msg rhs);
        constexpr Msg operator~();
};

inline MsgWrapper::MsgWrapper(Msg msg)
:
    d_msg(msg)
{}


inline constexpr size_t MsgWrapper::valueOf(Msg msg)
{
    return static_cast<size_t>(msg);
}
    
inline constexpr Msg  MsgWrapper::beginMsg()           // allow for-stmnts
{
    return Msg::DEBUG;
}

inline constexpr Msg MsgWrapper::endMsg()
{
    return static_cast<Msg>(valueOf(Msg::ALL) + 1);
}

inline Msg &MsgWrapper::operator++()        // no ++ if Msg == NONE
{
    return reinterpret_cast<Msg &>(reinterpret_cast<int &>(d_msg) <<= 1);
}

inline constexpr bool MsgWrapper::operator!()
{
    return d_msg == Msg::NONE;
}

inline constexpr Msg MsgWrapper::operator|(Msg rhs)
{
    return static_cast<Msg>(
                valueOf(d_msg) | valueOf(rhs)
            );
}

inline constexpr Msg MsgWrapper::operator&(Msg rhs)
{
    return static_cast<Msg>(
                valueOf(d_msg) & valueOf(rhs)
            );
}

inline constexpr Msg MsgWrapper::operator^(Msg rhs)
{
    return static_cast<Msg>(
                valueOf(d_msg) ^ valueOf(rhs)
            );
}

inline constexpr Msg MsgWrapper::operator~()
{
    return static_cast<Msg>(~valueOf(d_msg) & valueOf(Msg::ALL));
}

// operators == and != do not need separate implementations as 
// enums support these operations by default.

#endif