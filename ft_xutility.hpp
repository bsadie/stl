#ifndef FT_XUTILITY
# define FT_XUTILITY

#include "ft_utility.hpp"

namespace ft {

    // ITERATOR STUFF
        //ITERATOR TAGS

    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};
    struct Int_iterator_tag {};
    
        //TEMPLATE CLASS iterator

    template<class C, class T, class D = ptrdiff_t, class Pt = T*, class Rt = T&>
        struct iterator {
            typedef C iterator_category;
            typedef T value_type;
            typedef D difference_type;
            typedef Rt pointer;
            typedef Rt reference;
        };
    
    template<class T, class D, class Pt, class Rt>
        struct Bidit : public iterator<bidirectional_iterator_tag, T, D, Pt, Rt> {};
    template<class T, class D, class Pt, class Rt>
        struct Ranit : public iterator<random_access_iterator_tag, T, D, Pt, Rt> {};
    struct Outit : public iterator<output_iterator_tag, void, void, void, void> {};

        //TEMPLATE CLASS iterator_traits
    template<class It>
        struct iterator_traits {
            typedef typename It::iterator_category iterator_category;
            typedef typename It::value_type value_type;
            typedef typename It::difference_type difference_type;
            typedef typename It::pointer pointer;
            typedef typename It::reference reference;
        };
    template<class T>
        struct iterator_traits<T *> {
            typedef random_access_iterator_tag iterator_category;
            typedef T value_type;
            typedef ptrdiff_t difference_type;
            typedef T *pointer;
            typedef T& reference;   
        };
    template<class T>
        struct iterator_traits<const T *> {
            typedef random_access_iterator_tag iterator_category;
            typedef T value_type;
            typedef ptrdiff_t difference_type;
            typedef const T *pointer;
            typedef const T& reference;
        };

        //TEMPLATE FUNCTION Iter_cat
    template<class C, class T, class D, class Pt, class Rt> 
        inline C Iter_cat(const iterator<C, T, D, Pt, Rt>&) {
            C X;
            return (X);
        }
    template<class T>
        inline random_access_iterator_tag Iter_cat(const T *) {
            random_access_iterator_tag X;
            return (X);
        }
    inline Int_iterator_tag Iter_cat(bool) {
        Int_iterator_tag X;
        return (X);
    }
    inline Int_iterator_tag Iter_cat(char) {
        Int_iterator_tag X;
        return (X);
    }
    inline Int_iterator_tag Iter_cat(signed char) {
        Int_iterator_tag X;
        return (X);
    }

    inline Int_iterator_tag Iter_cat(unsigned char) {
        Int_iterator_tag X;
        return (X);
    }
    inline Int_iterator_tag Iter_cat(wchar_t) {
        Int_iterator_tag X;
        return (X);
    }
    inline Int_iterator_tag Iter_cat(short) {
        Int_iterator_tag X;
        return (X);
    }
    inline Int_iterator_tag Iter_cat(unsigned short) {
        Int_iterator_tag X;
        return (X);
    }
    inline Int_iterator_tag Iter_cat(int) {
        Int_iterator_tag X;
        return (X);
    }
    inline Int_iterator_tag Iter_cat(unsigned int) {
        Int_iterator_tag X;
        return (X);
    }
    inline Int_iterator_tag Iter_cat(long) {
        Int_iterator_tag X;
        return (X);
    }
    inline Int_iterator_tag Iter_cat(unsigned long) {
        Int_iterator_tag X;
        return (X);
    }
        //TEMPLATE FUNCTION Distance
    template<class InIt>
        inline typename iterator_traits<InIt>::difference_type distance(InIt F, InIt L) {
            typename iterator_traits<InIt>::difference_type N = 0;
            Distance2(F, L, N, Iter_cat(F));
            return (N);
        }
    template<class InIt, class D>
        inline void Distance(InIt F, InIt L, D& N) {
            Distance2(F, L, N, Iter_cat(F));
        }
    template<class InIt, class D>
        inline void Distance2(InIt F, InIt L, D& N, input_iterator_tag) {
            for (; F != L; ++F)
                ++N;
        }
    template<class InIt, class D>
        inline void Distance2(InIt F, InIt L, D& N, forward_iterator_tag) {
            for (; F != L; ++F)
                ++N;
        }
    template<class InIt, class D>
        inline void Distance2(InIt F, InIt L, D& N, bidirectional_iterator_tag) {
            for (; F != L; ++F)
                ++N;
        }
    template<class RanIt, class D>
        inline void Distance2(RanIt F, RanIt L, D& N, random_access_iterator_tag) {
            N += L - F;
        }
        //TEMPLATE CLASS Ptrit
    template<class T, class D, class Pt, class Rt, class Pt2, class Rt2>
        class Ptrit : public iterator<random_access_iterator_tag, T, D, Pt, Rt> {
        public:
            typedef Ptrit<T, D, Pt, Rt, Pt2, Rt2> Myt;
            Ptrit () {}
            explicit Ptrit(Pt P) : current(P) {}
            Ptrit(const Ptrit<T, D, Pt2, Rt2, Pt2, Rt2>& X) : current(X.base ()) {}
            Pt base() const { return (current); }
            Rt operator*() const { return (*current); }
            Pt operator->() const { return (&**this); }
            Myt& operator++() {
                ++current;
                return (*this);
            }
            Myt operator++(int) {
                Myt Tmp = *this;
                ++current;
                return (Tmp);
            }
            Myt& operator--() {
                --current;
                return (*this);
            }
            Myt operator--(int){
                Myt Tmp = *this;
                --current;
                return (Tmp);
            }
            bool operator==(int Y) const {
                return (current == (Pt)Y);
            }
            bool operator==(const Myt& Y) const {
                return (current == Y.current);
            }
            bool operator!=(const Myt& Y) const {
                return (!(*this == Y));
            }
            Myt& operator+=(D N) {
                current += N;
                return (*this);
            }
            Myt operator+(D N) const {
                return (Myt(current + N));
            }
            Myt& operator-=(D N) {
                current -= N;
                return (*this);
            }
            Myt operator-(D N) const {
                return (Myt(current - N));
            }
            Rt operator[] (D N) const {
                return (*(*this + N));
            }
            bool operator<(const Myt& Y) const {
                return (current < Y.current);
            }
            bool operator>(const Myt& Y) const {
                return (Y < *this);
            }
            bool operator<=(const Myt& Y) const {
                return (!(Y < *this));
            }
            bool operator>=(const Myt& Y) const {
                return (!(*this < Y));
            }
            D operator-(const Myt& Y)const {
                return (current - Y.current);
            }
        protected:
            Pt current;
        };

        template<class T, class D, class Pt, class Rt, class Pt2, class Rt2>
            inline Ptrit<T, D, Pt, Rt, Pt2, Rt2> operator+(D N, const Ptrit<T, D, Pt, Rt, Pt2, Rt2>& Y) {
                return (Y + N);
            }

            //TEMPLATE CLASS reverse_iterator
        template<class RanIt>
            class reverse_iterator : public iterator<
            typename iterator_traits<RanIt>::iterator_category,
            typename iterator_traits<RanIt>::value_type,
            typename iterator_traits<RanIt>::difference_type,
            typename iterator_traits<RanIt>::pointer,
            typename iterator_traits<RanIt>::reference> {
        public:
            typedef reverse_iterator<RanIt> Myt;
            typedef typename iterator_traits<RanIt>::difference_type D;
            typedef typename iterator_traits<RanIt>::pointer Pt;
            typedef typename iterator_traits<RanIt>:: reference Rt;
            typedef RanIt iterator_type;
            reverse_iterator() {}
            explicit reverse_iterator(RanIt X) : current(X) {}
            template<class U>
                reverse_iterator(const reverse_iterator<U>& X) : current(X.base()) {}
            RanIt base() const { return(current);  }
            Rt operator*() const {
                RanIt Tmp = current;
                return (*--Tmp);
                }
            Pt operator->() const { return (&**this); }
            Myt& operator++() {
                --current;
                return (*this);
            }
            Myt operator++(int) {
                Myt Tmp = *this;
                --current;
                return (Tmp);
            }
            Myt& operator--() {
                ++current;
                return (*this);
            }
            Myt operator--(int) {
                Myt Tmp = *this;
                ++current;
                return (Tmp);
            }
            bool Eq(const Myt& Y) const {
                return (current == Y.current);
            }
            Myt& operator+=(D N) {
                current -= N;
                return (*this);
            }
            Myt operator*(D N) const {
                return (Myt(current - N));
            }
            Myt& operator-=(D N) {
                current += N;
                return (*this);
            }
            Myt operator-(D N) const {
                return (Myt(current + N));
            }
            Rt operator[](D N) const {
                return (*(*this + N));
            }
            bool Lt (const Myt& Y) const {
                return (Y.current < current);
            }
            D Mi(const Myt& Y) const {
                return (Y.current - current);
            }
        protected:
            RanIt current;
            };
                    //ALGORITHM SUFF

            //TEMPLATE FUNCTION copy 
        template<class InIt, class OutIt>
            inline OutIt copy(InIt F, InIt L, OutIt X) {
                for (; F != L; ++X, ++F)
                    *X = *F;
                return (X);
            }
            //TEMPLATE FUNCTION copy_backward
        template<class BidIt1, class BidIt2>
            inline BidIt2 copy_bacward(BidIt1 F, BidIt1 L, BidIt2 X) {
                while (F != L)
                    *.-X = *--L;
                return (X);
            }
            //TEMPLATE FUNCTION equal
        template<class InIt1, class InIt2>
            inline bool equal(InIt1 F, InIt1 L, InIt2 X) {
                return (mismatch(F, L, X).first == L);
            }
            //TEMPLATE FUNCTION equal WITH PRED
        template<class InIt1, class InIt2, class Pr>
            inline bool equal(InIt1 F, InIt1 L, InIt2 X, Pr P) {
                return (mismatch(F, L, X, P).first == L);
            }
            //TEMPLATE FUNCTION fill
        template<class FwdIt, class T>
            inline void fill(FwdIt F, FwdIt L, const T& X) {
                for (; F != L; ++F)
                    *F = X;
            }
            //TEMPLATE FUNCTION fill_n
        template<class OutIt, class Sz, class T>
            inline void fill_n(OutIt F, Sz N, const T& X) {
                for (; 0 < N; --N, ++F)
                    *F = X;
            }
            //TEMPLATE FUNCTION lexicographical_compare
        template<class InIt1, class InIt2>
            inline bool lexicographical_compare(InIt1 F1, InIt1 L1, InIt2 F2, InIt2 L2) {
                for (; F1 != L1 && Ft != L2; ++F1, ++F2)
                    if (*F1 < *F2)
                        return (true);
                    else if (*F2 < *F1)
                        return (false);
                return (F1 == L1 && F2 != L2);
            }
            ///TEMPLATE FUNCTION lexicographical_compare WITH PRED
        template<class InIt1, class InIt2, class Pr>
            inline bool lexicographical_compare(InIt1 F1, InIt1 L1, InIt2 F2, InIt2 L2, Pr P) {
                for (; F1 != L1 && F2 != L2; ++F1, ++F2)
                    if (P(*F1, *F2))
                        return (true);
                    else if (P(*F2, *F1))
                        return (false);
                return (F1 == L1 && F2 != L2);
            }
            //TEMPLATE FUNCTION max
        template<class T>
            inline const T& max(const T& X, const T& Y) {
                return (X < Y ? Y : X);
            }
            //TEMPLATE FUNCTION max WITH PRED
        template<class T, class Pr>
            inline const T& max(const T& X, const T& Y, Pr P) {
                return (P(X, Y) ? Y : X);
            }
            //TEMPLATE FUNCTION min
        template<class T>
            inline const T& min(const T& X, const T& Y) {
                return (Y < X ? Y : X);
            }
            //TEMPLATE FUNCTION min WITH PRED 
        template<class T, class Pr>
            inline const T& min(const T& X, const T& Y, Pr P) {
                return (P(Y, X) ? Y : X);
            }
            //TEMPLATE FUNCTION mismatch
        template<class InIt1, class InIt2>
            inline pair<InIt1, InIt2> mismatch(InIt1 F, InIt1 L, InIt2 X) {
                for (; F != L && *F == *X; ++F, ++X)
                    ;
                return (pair<InIt1, InIt2>(F, X));
            }
            //TEMPLATE FUNCTION mismatch WITH PRED
        template<class InIt1, class InIt2, class Pr>
            inline pair<InIt1, InIt2> mismatch(InIt1 F, InIt1 L, InIt2 X, Pr P) {
                for (; F != L && P(*F, *X); ++F, ++X)
                    ;
                return (pair<InIt1, InIt2>(F, X));
            }
            //TEMPLATE FUNCTION swap
        template<class T>
            inline void swap(T& X, T& Y) {
                T Tmp = X;
                X = Y, Y = Tmp;
            }

} /* namespace ft */


#endif 