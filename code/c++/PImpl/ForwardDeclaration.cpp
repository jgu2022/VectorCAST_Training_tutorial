
#include "ForwardDeclaration.h"
#include <vector>
#include <iostream>
struct ptr_vector_base::impl
{
    std::vector<void*> vp;
 
    void push_back(void* p)
    {
        vp.push_back(p);
    }
 
    void print() const
    {
        for (void const * const p: vp) std::cout << p << '\n';
    }
};
 
void ptr_vector_base::push_back_fwd(void* p) { pImpl->push_back(p); }
ptr_vector_base::ptr_vector_base() : pImpl{std::make_unique<impl>()} {}
ptr_vector_base::~ptr_vector_base() {}
void ptr_vector_base::print() const { pImpl->print(); }
