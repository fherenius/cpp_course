union PointerUnion
{
  int (*fp)(int const &);
  void *vp;
};