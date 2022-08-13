#include "msg.h"

class Handler: private MsgWrapper
{
    public:
        Handler(Msg Msg);
};

inline Handler::Handler(Msg msg)
:
    MsgWrapper(msg)
{}