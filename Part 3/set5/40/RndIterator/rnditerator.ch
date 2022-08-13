#ifndef INCLUDED_RNDITERATOR_CH
#define INCLUDED_RNDITERATOR_CH

#include "dereferenceable.ch"
#include "incrementable.ch"
#include "decrementable.ch"
#include "stepable.ch"

template <typename TypeT>
concept RndIterator =
    Dereferenceable<TypeT> and Stepable<TypeT> and
    Incrementable<TypeT> and Decrementable<TypeT>;

#endif