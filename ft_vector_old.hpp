#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <memory>
#include <iterator>

namespace ft
{
template<class T, class Allocator = std::allocator<T> >
class vector
{
public:
    typedef             T                           value_type;
    typedef             Allocator                   allocator_type;
    typedef typename    std::size_t                 size_type;
    typedef typename    std::ptrdiff_t              difference_type;
    typedef             value_type&                 reference;
    typedef             const value_type&           const_reference;
    typedef typename    Allocator::pointer          pointer;
    typedef typename    Allocator::const_pointer    const_pointer;
    //typedef                                       iterator
    //typedef                                       const_iterator
    //typedef typename    std::reverse_iterator<iterator> reverse_iterator;
    //typedef typename    std::reverse_iterator<const_iterator> const_reverse_iterator;

    vector() {}
    ~vector() {}

private:
   allocator_type alloc;



};

}


#endif

