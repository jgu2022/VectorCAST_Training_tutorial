#include "inlines.h"

class_with_some_inlines_in_header::class_with_some_inlines_in_header(int i)
  : m_i( i )
{
}

inline int non_member_inline_in_source(void)
{
  return 1;
}


class class_with_some_inlines_in_source
{
public:
  class_with_some_inlines2(int i);
  static int use_int2();
  static int get_int2() { return 3; }

private:
	int m_i;
};