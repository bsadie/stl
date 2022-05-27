
#include <assert.h>
#include <iostream>
#include "ft_utility.hpp"
#include "ft_iterator.hpp"
#include <deque>

typedef ft::pair<int, char> Pair_ic;
Pair_ic p0;

class Int {
public:
    Int(int v) : val(v) {}
    bool operator==(Int x) const {
        return (val == x.val);
    }
    bool operator<(Int x) const {
        return (val < x.val);
    }
private:
    int val;
};

    //TESTING ITERATORS
    typedef char *PtrIt;

    void takes_ran_tag(ft::random_access_iterator_tag) {}
    void test_prop() {
        ft::random_access_iterator_tag *ran_tag = (ft::random_access_iterator_tag *)0;
        ft::bidirectional_iterator_tag *bid_tag = (ft::random_access_iterator_tag *)0;
        ft::forward_iterator_tag *fwd_tag = (ft::bidirectional_iterator_tag *)0;
        ft::input_iterator_tag *in_tag = (ft::forward_iterator_tag *)0;
        ft::output_iterator_tag *p_out_tag = 0;

        typedef ft::iterator<ft::input_iterator_tag, float, short, float *, float&> Iter;
        float f1;
        Iter::iterator_category *it_tag = (ft::input_iterator_tag *)0;
        Iter::value_type *it_val = (float *)0;
        Iter::difference_type *it_dist = (short *)0;
        Iter::pointer it_ptr = (float *)0;
        Iter::reference it_ref = f1;

        typedef ft::iterator_traits<Iter> Traits;
        Traits::iterator_category *tr_tag = (ft::input_iterator_tag *)0;
        Traits::value_type *tr_val = (float *)0;
        Traits::difference_type *tr_dist = (short *)0;
        Traits::pointer tr_ptr = (float *)0;
        Traits::reference tr_ref = f1;

        typedef ft::iterator_traits<PtrIt> Ptraits;
        char ch;
        takes_ran_tag(Ptraits::iterator_category());
        Ptraits::value_type *ptr_val = (char *)0;
        Ptraits::difference_type *ptr_dist = (ptrdiff_t *)0;
        Ptraits::pointer ptr_ptr = (char *)0;
        Ptraits::reference ptr_ref = ch;

        const char *pc = "abcdefg";
        std::advance(pc, 4);
        assert(*pc == 'e');
        std::advance(pc, -1);
        assert(*pc == 'd');
        assert(ft::distance(pc, pc + 3) == 3);
    }

    typedef ft::reverse_iterator<PtrIt> RevIt;
    class MyrevIt : public RevIt {
    public:
        MyrevIt(RevIt::iterator_type p) : RevIt(p) {}
        RevIt::iterator_type get_current() const { return (current); }
    };

    void test_revit() {
        ///using namespace ft;
        char *pc = (char *)"abcdefg" + 3;
        PtrIt pcit(pc);
        RevIt::iterator_type *p_iter = (PtrIt *)0;
        RevIt rit0, rit(pcit);
        assert(rit.base() == pcit);
        assert(*rit == 'c');
        assert(*++rit == 'b');
        assert(*rit++ == 'b' && *rit == 'a');
        assert(*--rit == 'b');
        assert(*rit-- == 'b' && *rit == 'c');
        assert(*(rit += 2) == 'a');
        assert(*(rit -= 2) == 'c');
        assert(*(rit + 2) == 'a' && *rit == 'c');
        assert(*(rit - 2) == 'e' && *rit == 'c');
        assert(rit[2] == 'a');
        assert(rit == rit);
        assert(!(rit < rit) && rit < rit + 1);
        assert((rit + 2) - rit == 2);

        MyrevIt myrit(pc);
        assert(myrit.get_current() == pcit);
    }

    //TEST INSERTION ITERATORS

    typedef std::deque<char, std::allocator<char> > Cont;
    typedef ft::back_insert_iterator<Cont> BackIt;
    class MybackIt : public BackIt {
    public:
        MybackIt(BackIt::container_type& c) : BackIt(c) {}
        BackIt::container_type *get_container() const {
            return (container);
        }
    };

    typedef ft::front_insert_iterator<Cont> FrontIt;
    class MyfrontIt : public FrontIt {
    public:
        MyfrontIt(FrontIt::container_type& c) : FrontIt(c) {}
        FrontIt::container_type *get_container() const {
            return (container);
        }
    };
    typedef ft::insert_iterator<Cont> InsIt;
    class MyinsIt : public InsIt {
    public:
        MyinsIt(InsIt::container_type& c, Cont::iterator it) : InsIt(c, it) {}
        InsIt::container_type *get_container () const {
            return (container);
        }
        Cont::iterator get_iterator() const {
            return (iter);
        }
    };

    void test_inserts() {
        Cont c0;
        char ch;
        BackIt::container_type *pbi_cont = (Cont *)0;
        BackIt::reference pbi_ref = ch;
        BackIt::value_type *pbi_val = (char *)0;
        BackIt bit(c0);
        *bit = 'a';
        *bit++ = 'b';
        assert (c0[0] == 'a' && c0[1] == 'b');
        MybackIt mybkit(c0);
        assert (mybkit.get_container() == &c0);
        *back_inserter (c0)++ = 'x';
        assert(c0[2] == 'x');

        FrontIt::container_type *pfi_cont = (Cont *)0;
        FrontIt::reference pfi_ref = ch;
        FrontIt::value_type *pfi_val = (char *)0;
        FrontIt fit(c0);
        *fit = 'c', ++fit;
        *fit++ = 'd';
        assert(c0[0] == 'd' && c0[1] == 'c');
        MyfrontIt myfrit(c0);
        assert (myfrit.get_container() == &c0);
        *front_inserter(c0)++ = 'y';
        assert(c0[0] == 'y');

        InsIt::container_type *pii_cont = (Cont *)0;
        InsIt::reference pii_ref = ch;
        InsIt::value_type *pii_val = (char *)0;
        InsIt iit(c0, c0.begin());
        *iit = 'e', ++iit;
        *iit++ = 'f';
        assert(c0[0] == 'e' && c0[1] == 'f');
        MyinsIt myinsit(c0, c0.begin());
        assert(myinsit.get_container()== &c0);
        assert(myinsit.get_iterator() == c0.begin());
        *inserter(c0, c0.begin())++ = 'z';
        assert(c0[0] == 'z');
    }





int main() {

    std::cout << "testing \"ft_utility\"" << "\n";
    Pair_ic p1 = p0;
    Pair_ic p2(3, 'a');

    assert (p1.first == 0);
    assert (p1.second == 0);
    assert (p2.first == 3);
    assert (p2.second = 'a');
    assert (p2 == ft::make_pair ((Pair_ic::first_type)3, (Pair_ic::second_type)'a'));
    assert (p2 < ft::make_pair((Pair_ic::first_type)4, (Pair_ic::second_type)'a'));
    assert (p2 < ft::make_pair((Pair_ic::first_type)3, (Pair_ic::second_type)'b'));
    assert (p1 != p2);
    assert (p2 > p1);
    assert (p2 <= p2);
    assert (p2 >= p2);

    Int a(2), b(3);
    using namespace ft::rel_ops;
    assert (a == a);
    assert (a < b);
    assert (ft::rel_ops::operator!=(a, b));
    assert (b > a);
    assert (a <= b);
    assert (b >= a);
    std::cout << "success testing \"ft_utility\"" << "\n";

    std::cout << "testing \"ft_iterator\"" << "\n";

    








}