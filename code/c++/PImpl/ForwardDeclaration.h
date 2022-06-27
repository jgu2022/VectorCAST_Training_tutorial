
#ifndef FORWARD_H
#define FORWARD_H
#include <memory>

class ptr_vector_base
{
    struct impl; // 前置声明
    std::unique_ptr<impl> pImpl;
protected:
    void push_back_fwd(void*);
    void print() const;

public:
    ptr_vector_base();
    ~ptr_vector_base();
};
 
template<class T>
class ptr_vector : private ptr_vector_base
{
public:
    void push_back(T* p) { push_back_fwd(p); }
    void print() const { ptr_vector_base::print(); }
};

#endif

