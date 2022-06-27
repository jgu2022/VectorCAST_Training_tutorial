#ifndef INLINES_H
#define INLINES_H

class class_with_some_inlines_in_header
{
public:
  class_with_some_inlines_in_header(int i);
  int get_int() { return m_i; }

private:
  int m_i;
};

class class_with_some_inlines_in_header2
{
public:
  class_with_some_inlines_in_header2(int i);
  int get_int() { return m_i; }

private:
  int m_i;
};

inline int non_member_inline_in_header(void)
{
  return 1;
}


#endif

