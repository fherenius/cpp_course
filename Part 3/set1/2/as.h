template <typename CastType, typename InpType>
CastType as(InpType const &toCast)
{
  return static_cast<CastType>(toCast);         // Call static_cast
}