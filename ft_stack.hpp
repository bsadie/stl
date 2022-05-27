#ifndef FT_STACK_HPP
#define FT_STACK_HPP

# include <iostream>
# include <vector>

namespace ft
{
template<class T, class Container = std::vector<T> >
class stack
{
public:
    typedef             Container                   container_type;
    typedef typename    Container::value_type       value_type;
    typedef typename    Container::size_type        size_type;
    typedef typename    Container::reference        reference;
    typedef typename    Container::const_reference  const_reference;

protected:
    container_type _data;

public:
    explicit            stack(const Container& container = Container()): _data(container) {}
                        ~stack() {}
    stack&              operator=(const stack& rhs) {
                            this->_data = rhs._data;
                            return *this; }

    reference           top() { return _data.back(); }
    const_reference     top() const {return _data.back(); }
    bool                empty() const {return _data.empty(); }
    size_type           size() const {return _data.size(); }
    void                push(const value_type& value) {_data.push_back(value); }
    void                pop() {_data.pop_back(); }

    friend bool         operator==(const stack& lhs, const stack& rhs) {return lhs._data == rhs._data; }
    friend bool         operator!=(const stack& lhs, const stack& rhs) {return lhs._data != rhs._data; }
    friend bool         operator<(const stack& lhs, const stack& rhs) {return lhs._data < rhs._data; }
    friend bool         operator<=(const stack& lhs, const stack& rhs) {return lhs._data <= rhs._data; }
    friend bool         operator>(const stack& lhs, const stack& rhs) {return lhs._data > rhs._data; }
    friend bool         operator>=(const stack& lhs, const stack& rhs) {return lhs._data >= rhs._data; }

};
}


#endif