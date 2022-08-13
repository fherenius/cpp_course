#include "msg.h"

class Processor: public MsgWrapper
{
    public:
        Processor(Msg msg);
};

inline Processor::Processor(Msg msg)
:
    MsgWrapper(msg)
{}