//JB: 1
#ifndef INCLUDED_TYPE_H
#define INCLUDED_TYPE_H


    // Generic definition, only specializations are used
template <typename Needle, typename ...HayStack>
struct Type;


    // Specialization where Needle and First type are not the same
    // (ensured by more specific specialization below)
    // Pass the Needle on to the next object with a new First.
template <typename Needle, typename First, typename ...HayStack>
struct Type<Needle, First, HayStack...>
{
        // "Recursively" count the index, or keep it zero if not found
    enum { located = (Type<Needle, HayStack...>::located)
                     ?
                       Type<Needle, HayStack...>::located + 1
                     :
                        0 
         };
};

    // Specialization where the first two types are the same
    // this sets the located to 1.
    // The index cannot be 0 any way since that is the needle.
    // 0 is used as not found
template <typename Needle, typename ...HayStack>
struct Type<Needle, Needle, HayStack...>
{
    enum { located = 1 };
};

    // Specialization where only the needle exists
    // located is thus 0.
template <typename Needle>
struct Type<Needle>
{
    enum { located = 0 };
};

#endif
