//JB: 1
//JB: It's just that I find 'TraitCounter' a bit confusing.
//JB: It doesn't count traits, does it?
#ifndef INCLUDED_TRAITCOUNTER_H
#define INCLUDED_TRAITCOUNTER_H


template <typename TypeT>
class TraitCounter
{
    template <typename TypeParam>
    struct Counter
    {
        using type = TypeParam;
        enum { typeValue = 1 };
        //JB: NMN
    };


    template <typename TypeParam>
    struct Counter<TypeParam *>
    {
        using type = TypeParam;
        enum { typeValue = 2 };
    };


    template <typename TypeParam>
    struct Counter<TypeParam &>
    {
        using type = TypeParam;
        enum { typeValue = 3 };
    };


    template <typename TypeParam>
    struct Counter<TypeParam &&>
    {
        using type = TypeParam;
        enum { typeValue = 4 };
    };

  public:
    TraitCounter(TraitCounter const &other) = delete;

    using type = Counter<TypeT>::type;
    enum { value = Counter<TypeT>::typeValue };

};



#endif

