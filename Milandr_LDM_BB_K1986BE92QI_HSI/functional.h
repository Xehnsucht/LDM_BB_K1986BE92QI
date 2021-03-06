// -*- C++ -*-
/***************************************************************************
 *
 * functional - global template functions
 *
 * $Id$
 *
 ***************************************************************************
 *
 * Copyright (c) 1994
 * Hewlett-Packard Company
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Hewlett-Packard Company makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 *
 ***************************************************************************
 *
 * Copyright (c) 1994-2001 Rogue Wave Software, Inc.  All Rights Reserved.
 *
 * This computer software is owned by Rogue Wave Software, Inc. and is
 * protected by U.S. copyright laws and other laws and by international
 * treaties.  This computer software is furnished by Rogue Wave Software,
 * Inc. pursuant to a written license agreement and may be used, copied,
 * transmitted, and stored only in accordance with the terms of such
 * license and with the inclusion of the above copyright notice.  This
 * computer software or any other copies thereof may not be provided or
 * otherwise made available to any other person.
 *
 * U.S. Government Restricted Rights.  This computer software is provided
 * with Restricted Rights.  Use, duplication, or disclosure by the
 * Government is subject to restrictions as set forth in subparagraph (c)
 * (1) (ii) of The Rights in Technical Data and Computer Software clause
 * at DFARS 252.227-7013 or subparagraphs (c) (1) and (2) of the
 * Commercial Computer Software--Restricted Rights at 48 CFR 52.227-19,
 * as applicable.  Manufacturer is Rogue Wave Software, Inc., 5500
 * Flatiron Parkway, Boulder, Colorado 80301 USA.
 *
 **************************************************************************/

#ifndef _RWSTD_FUNCTIONAL_INCLUDED
#define _RWSTD_FUNCTIONAL_INCLUDED

#include <rw/_defs.h>


_RWSTD_NAMESPACE_BEGIN (std)


// 20.3.1 - Base
template <class _Arg, class _Result>
struct unary_function
{
    typedef _Arg    argument_type;
    typedef _Result result_type;
};


#define _RWSTD_UNARY_FUNCTION_TYPES(T, U)                                      \
    typedef _TYPENAME _STD::unary_function<T, U>::argument_type argument_type; \
    typedef _TYPENAME _STD::unary_function<T, U>::result_type   result_type


template <class _Arg1, class _Arg2, class _Result>
struct binary_function
{
    typedef _Arg1   first_argument_type;
    typedef _Arg2   second_argument_type;
    typedef _Result result_type;
};


#define _RWSTD_BINARY_FUNCTION_TYPES(T, U, V)                              \
    typedef _TYPENAME _STD::binary_function<T, U, V>::second_argument_type \
            second_argument_type;                                          \
    typedef _TYPENAME _STD::binary_function<T, U, V>::first_argument_type  \
            first_argument_type;                                           \
    typedef _TYPENAME _STD::binary_function<T, U, V>::result_type          \
            result_type


// 20.3.2 - Arithmetic operations

// 20.3.2, p2
template <class _TypeT>
struct plus : public binary_function<_TypeT, _TypeT, _TypeT>
{
    _RWSTD_BINARY_FUNCTION_TYPES (_TypeT, _TypeT, _TypeT);

    result_type operator() (const first_argument_type  &__x,
                            const second_argument_type &__y) const {
        return __x + __y;
    }
};


// 20.3.2, p3
template <class _TypeT>
struct minus : public binary_function<_TypeT, _TypeT, _TypeT>
{
    _RWSTD_BINARY_FUNCTION_TYPES (_TypeT, _TypeT, _TypeT);

    result_type operator() (const first_argument_type  &__x,
                            const second_argument_type &__y) const {
        return __x - __y;
    }
};


// 20.3.2, p4
template <class _TypeT>
struct multiplies : public binary_function<_TypeT, _TypeT, _TypeT>
{
    _RWSTD_BINARY_FUNCTION_TYPES (_TypeT, _TypeT, _TypeT);

    result_type operator() (const first_argument_type  &__x,
                            const second_argument_type &__y) const {
        return __x * __y;
    }
};


// 20.3.2, p5
template <class _TypeT>
struct divides : public binary_function<_TypeT, _TypeT, _TypeT>
{
    _RWSTD_BINARY_FUNCTION_TYPES (_TypeT, _TypeT, _TypeT);

    result_type operator() (const first_argument_type  &__x,
                            const second_argument_type &__y) const {
        return __x / __y;
    }
};


// 20.3.2, p6
template <class _TypeT>
struct modulus : public binary_function<_TypeT, _TypeT, _TypeT>
{
    _RWSTD_BINARY_FUNCTION_TYPES (_TypeT, _TypeT, _TypeT);

    result_type operator() (const first_argument_type  &__x,
                            const second_argument_type &__y) const {
        return __x % __y;
    }
};


// 20.3.2, p7
template <class _TypeT>
struct negate : public unary_function<_TypeT, _TypeT>
{
    _RWSTD_UNARY_FUNCTION_TYPES (_TypeT, _TypeT);

    result_type operator() (const argument_type &__x) const {
        return -__x;
    }
};


// 20.3.3 - Comparisons


// 20.3.3, p2
template <class _TypeT>
struct equal_to : public binary_function<_TypeT, _TypeT, bool>
{
    _RWSTD_BINARY_FUNCTION_TYPES (_TypeT, _TypeT, bool);

    result_type operator() (const first_argument_type  &__x,
                            const second_argument_type &__y) const {
        return __x == __y;
    }
};


// 20.3.3, p3
template <class _TypeT>
struct not_equal_to : public binary_function<_TypeT, _TypeT, bool>
{
    _RWSTD_BINARY_FUNCTION_TYPES (_TypeT, _TypeT, bool);

    result_type operator() (const first_argument_type  &__x,
                            const second_argument_type &__y) const {
        return __x != __y;
    }
};


// 20.3.3, p4
template <class _TypeT>
struct greater : public binary_function<_TypeT, _TypeT, bool>
{
    _RWSTD_BINARY_FUNCTION_TYPES (_TypeT, _TypeT, bool);

    result_type operator() (const first_argument_type  &__x,
                            const second_argument_type &__y) const {
        return __x > __y;
    }
};


// 20.3.3, p5
template <class _TypeT>
struct less : public binary_function<_TypeT, _TypeT, bool>
{
    _RWSTD_BINARY_FUNCTION_TYPES (_TypeT, _TypeT, bool);

    result_type operator() (const first_argument_type  &__x,
                            const second_argument_type &__y) const {
        return __x < __y;
    }
};


// 20.3.3, p6
template <class _TypeT>
struct greater_equal : public binary_function<_TypeT, _TypeT, bool>
{
    _RWSTD_BINARY_FUNCTION_TYPES (_TypeT, _TypeT, bool);

    result_type operator() (const first_argument_type  &__x,
                            const second_argument_type &__y) const {
        return __x >= __y;
    }
};


// 20.3.3, p7
template <class _TypeT>
struct less_equal : public binary_function<_TypeT, _TypeT, bool>
{
    _RWSTD_BINARY_FUNCTION_TYPES (_TypeT, _TypeT, bool);

    result_type operator() (const first_argument_type  &__x,
                            const second_argument_type &__y) const {
        return __x <= __y;
    }
};


// 20.3.4 - Logical operations

// 20.3.4, p2
template <class _TypeT>
struct logical_and : public binary_function<_TypeT, _TypeT, bool>
{
    _RWSTD_BINARY_FUNCTION_TYPES (_TypeT, _TypeT, bool);

    result_type operator() (const first_argument_type  &__x,
                            const second_argument_type &__y) const {
        return __x && __y;
    }
};


// 20.3.4, p3
template <class _TypeT>
struct logical_or : public binary_function<_TypeT, _TypeT, bool>
{
    _RWSTD_BINARY_FUNCTION_TYPES (_TypeT, _TypeT, bool);

    result_type operator() (const first_argument_type  &__x,
                            const second_argument_type &__y) const {
        return __x || __y;
    }
};

// 20.3.4, p4
template <class _TypeT>
struct logical_not : public unary_function<_TypeT, bool>
{
    _RWSTD_UNARY_FUNCTION_TYPES (_TypeT, bool);

    result_type operator() (const _TypeT &__x) const {
        return !__x;
    }
};


// 20.3.5 - Negators

// 20.3.5, p2
template <class _Predicate>
class unary_negate
    : public unary_function<_TYPENAME _Predicate::argument_type, bool>
{
    _Predicate _C_pred;
public:
    _RWSTD_UNARY_FUNCTION_TYPES (_TYPENAME _Predicate::argument_type, bool);

    _EXPLICIT unary_negate (const _Predicate &__pred) : _C_pred (__pred) { }

    result_type operator() (const argument_type &__x) const {
        return !_C_pred (__x);
    }
};


// 20.3.5, p3
template <class _Predicate>
inline unary_negate<_Predicate> not1 (const _Predicate &__pred)
{
    return unary_negate<_Predicate>(__pred);
}


// 20.3.5, p4
template <class _Predicate>
class binary_negate
    : public binary_function<_TYPENAME _Predicate::first_argument_type,
                             _TYPENAME _Predicate::second_argument_type, bool>
{
    _Predicate _C_pred;
public:

    _RWSTD_BINARY_FUNCTION_TYPES (_TYPENAME _Predicate::first_argument_type,
                                  _TYPENAME _Predicate::second_argument_type,
                                  bool);

    _EXPLICIT binary_negate (const _Predicate &__pred) : _C_pred (__pred) { }

    result_type operator() (const first_argument_type  &__x,
                            const second_argument_type &__y) const {
        return !_C_pred (__x, __y);
    }
};


// 20.3.5, p5
template <class _Predicate>
inline binary_negate<_Predicate> not2 (const _Predicate &__pred)
{
    return binary_negate<_Predicate>(__pred);
}


// 20.3.6 - Binders

// 20.3.6.1
template <class _Operation>
struct binder1st
    : public unary_function<_TYPENAME _Operation::second_argument_type,
                            _TYPENAME _Operation::result_type>
{
protected:
    _Operation                                op;
    _TYPENAME _Operation::first_argument_type value;
public:

    _RWSTD_UNARY_FUNCTION_TYPES (_TYPENAME _Operation::second_argument_type,
                                 _TYPENAME _Operation::result_type);

    binder1st (const _Operation                                &__oper,
               const _TYPENAME _Operation::first_argument_type &__x)
        : op (__oper), value (__x) { }

    result_type
    operator() (const argument_type &__y) const {
        return op (value, __y);
    }
    // Added in line with library issue #109:
    result_type
    operator() (argument_type &__y) const {
        return op (value, __y);
    }
};


// 20.3.6.2
template <class _Operation, class _TypeT>
inline binder1st<_Operation>
bind1st (const _Operation &__oper, const _TypeT &__x)
{
    typedef _TYPENAME _Operation::first_argument_type first_argument_type;

    return binder1st<_Operation>(__oper, first_argument_type (__x));
}


// 20.3.6.3
template <class _Operation>
class binder2nd
    : public unary_function<_TYPENAME _Operation::first_argument_type,
                            _TYPENAME _Operation::result_type>
{
protected:
    _Operation                                 op;
    _TYPENAME _Operation::second_argument_type value;
public:

    _RWSTD_UNARY_FUNCTION_TYPES (_TYPENAME _Operation::first_argument_type,
                                 _TYPENAME _Operation::result_type);

    binder2nd (const _Operation                                 &__oper,
               const _TYPENAME _Operation::second_argument_type &__y)
        : op (__oper), value (__y) { }

    result_type
    operator() (const argument_type &__x) const {
        return op (__x, value);
    }
    // Added in line with library issue #109:
    result_type
    operator() (argument_type &__x) const {
        return op (__x, value);
    }
};


// 20.3.6.4
template <class _Operation, class _TypeT>
inline binder2nd<_Operation>
bind2nd (const _Operation &__oper, const _TypeT &__x)
{
    typedef _TYPENAME _Operation::second_argument_type second_argument_type;
    return binder2nd<_Operation>(__oper, second_argument_type (__x));
}


// 20.3.7 - Adaptors for pointers to functions

// 20.3.7, p2
template <class _Arg, class _Result>
struct pointer_to_unary_function : public unary_function<_Arg, _Result>
{
    _RWSTD_UNARY_FUNCTION_TYPES (_Arg, _Result);

    _EXPLICIT pointer_to_unary_function (result_type (*__fun)(argument_type))
        : _C_fn (__fun) {}

    result_type operator() (argument_type __x) const {
        return _C_fn (__x);
    }

private:
    result_type (*_C_fn)(argument_type);
};


// 20.3.7, p3
template <class _Arg, class _Result>
inline pointer_to_unary_function<_Arg, _Result>
ptr_fun (_Result (*__fun)(_Arg))
{
    return pointer_to_unary_function<_Arg, _Result>(__fun);
}


// 20.3.7, p4
template <class _Arg1, class _Arg2, class _Result>
struct pointer_to_binary_function
    : public binary_function<_Arg1, _Arg2, _Result>
{
    _RWSTD_BINARY_FUNCTION_TYPES (_Arg1, _Arg2, _Result);

    _EXPLICIT
    pointer_to_binary_function (result_type (*__fun)(first_argument_type,
                                                    second_argument_type))
        : _C_fn (__fun) { }

    result_type operator() (first_argument_type __x,
                            second_argument_type __y) const {
        return _C_fn (__x, __y);
    }

private:
    result_type (*_C_fn)(first_argument_type, second_argument_type);
};


// 20.3.7, p5
template <class _Arg1, class _Arg2, class _Result>
inline pointer_to_binary_function<_Arg1, _Arg2, _Result>
ptr_fun (_Result (*__fun)(_Arg1, _Arg2))
{
    return pointer_to_binary_function<_Arg1, _Arg2, _Result>(__fun);
}


// 20.3.8 - Adaptors for pointers to members

// 20.3.8, p2 - adaptor for a non-const member function taking no arguments
//              operating on a pointer to a non-const object
template <class _Result, class _TypeT>
struct mem_fun_t: public unary_function<_TypeT*, _Result>
{
    _RWSTD_UNARY_FUNCTION_TYPES (_TypeT*, _Result);

    _EXPLICIT mem_fun_t (result_type (_TypeT::*__fun)()) : _C_fn (__fun) { }

    result_type operator() (argument_type __x) const {
        return (__x->*_C_fn)();
    }

private:
    result_type (_TypeT::*_C_fn)();
};


// 20.3.8, p3 - adaptor for a non-const member function taking one argument
//              operating on a pointer to a non-const object
template <class _Result, class _TypeT, class _Arg>
struct mem_fun1_t: public binary_function<_TypeT*, _Arg, _Result>
{
    _RWSTD_BINARY_FUNCTION_TYPES (_TypeT*, _Arg, _Result);

    _EXPLICIT
    mem_fun1_t (result_type (_TypeT::*__fun)(second_argument_type))
        : _C_fn (__fun) { }

    result_type operator() (first_argument_type  __x,
                            second_argument_type __y) const {
        return (__x->*_C_fn)(__y);
    }

private:
    result_type (_TypeT::*_C_fn)(second_argument_type);
};


// 20.3.8, p4
template <class _Result, class _TypeT>
inline mem_fun_t<_Result, _TypeT> mem_fun (_Result (_TypeT::*__fun)())
{
    return mem_fun_t<_Result, _TypeT>(__fun);
}


template <class _Result, class _TypeT, class _Arg>
inline mem_fun1_t<_Result, _TypeT, _Arg>
mem_fun (_Result (_TypeT::*__fun)(_Arg))
{
    return mem_fun1_t<_Result, _TypeT, _Arg>(__fun);
}


// 20.3.8, p5 - adaptor for a non-const member function taking no arguments
//              operating on a non-const object
template <class _Result, class _TypeT>
struct mem_fun_ref_t: public unary_function<_TypeT, _Result>
{
    _RWSTD_UNARY_FUNCTION_TYPES (_TypeT, _Result);

    _EXPLICIT mem_fun_ref_t (result_type (_TypeT::*__fun)()) : _C_fn (__fun) { }

    result_type operator() (argument_type &__x) const {
        return (__x.*_C_fn)();
    }

private:
    result_type (_TypeT::*_C_fn)();
};


// 20.3.8, p6 - adaptor for a non-const member function taking one argument
//              operating on a non-const object
template <class _Result, class _TypeT, class _Arg>
struct mem_fun1_ref_t : public binary_function<_TypeT, _Arg, _Result>
{
    _RWSTD_BINARY_FUNCTION_TYPES (_TypeT, _Arg, _Result);

    _EXPLICIT
    mem_fun1_ref_t (result_type (_TypeT::*__fun)(second_argument_type))
        : _C_fn (__fun) { }

    result_type operator() (first_argument_type  &__x,
                            second_argument_type  __y) const {
        return (__x.*_C_fn)(__y);
    }

private:
    result_type (_TypeT::*_C_fn)(second_argument_type);
};


// 20.3.8, p7
template <class _Result, class _TypeT>
inline mem_fun_ref_t<_Result, _TypeT>
mem_fun_ref(_Result (_TypeT::*__fun)())
{
    return mem_fun_ref_t<_Result, _TypeT>(__fun);
}


template <class _Result, class _TypeT, class _Arg>
inline mem_fun1_ref_t<_Result, _TypeT, _Arg>
mem_fun_ref(_Result (_TypeT::*__fun)(_Arg))
{
    return mem_fun1_ref_t<_Result, _TypeT, _Arg> (__fun);
}


// 20.3.8, p8 - adaptor for a const member function taking no arguments
//              operating on a const object
template <class _Result, class _TypeT>
struct const_mem_fun_t: public unary_function<_TypeT*, _Result>
{
    _RWSTD_UNARY_FUNCTION_TYPES (_TypeT*, _Result);

    _EXPLICIT const_mem_fun_t (result_type (_TypeT::*__fun)() const)
        : _C_fn (__fun) { }

    result_type operator() (argument_type __x) const {
        return (__x->*_C_fn)();
    }

private:
    result_type (_TypeT::*_C_fn)() const;
};


// 20.3.8, p9 - adaptor for a const member function taking one argument
//              operating on a const object
template <class _Result, class _TypeT, class _Arg>
struct const_mem_fun1_t: public binary_function<_TypeT*, _Arg, _Result>
{
    _RWSTD_BINARY_FUNCTION_TYPES (_TypeT*, _Arg, _Result);

    _EXPLICIT
    const_mem_fun1_t (result_type (_TypeT::*__fun)(second_argument_type) const)
        : _C_fn (__fun) { }

    result_type operator() (first_argument_type  __x,
                            second_argument_type __y) const {
        return (__x->*_C_fn)(__y);
    }

private:
    result_type (_TypeT::*_C_fn)(second_argument_type) const;
};


// 20.3.8, p10
template <class _Result, class _TypeT>
inline const_mem_fun_t<_Result, _TypeT>
mem_fun (_Result (_TypeT::*__fun)() const)
{
    return const_mem_fun_t<_Result, _TypeT>(__fun);
}


template <class _Result, class _TypeT, class _Arg>
inline const_mem_fun1_t<_Result, _TypeT, _Arg>
mem_fun (_Result (_TypeT::*__fun)(_Arg) const)
{
    return const_mem_fun1_t<_Result, _TypeT, _Arg>(__fun);
}


// 20.3.8, p11 - adaptor for a const member function taking no arguments
//               operating on a const reference to an object
template <class _Result, class _TypeT>
struct const_mem_fun_ref_t: public unary_function<_TypeT, _Result>
{
    _RWSTD_UNARY_FUNCTION_TYPES (_TypeT, _Result);

    _EXPLICIT const_mem_fun_ref_t (result_type (_TypeT::*__fun)() const)
        : _C_fn (__fun) { }

    result_type operator() (const argument_type &__x) const {
        return (__x.*_C_fn)();
    }

private:
    result_type (_TypeT::*_C_fn)() const;
};


// 20.3.8, p12 - adaptor for a const member function taking a single argument
//               operating on a const reference to an object
template <class _Result, class _TypeT, class _Arg>
class const_mem_fun1_ref_t : public binary_function<_TypeT, _Arg, _Result>
{
    _RWSTD_BINARY_FUNCTION_TYPES (_TypeT, _Arg, _Result);

    _EXPLICIT
    const_mem_fun1_ref_t
        (result_type (_TypeT::*__fun)(second_argument_type) const)
            : _C_fn (__fun) { }

    result_type operator() (const first_argument_type &__x,
                            second_argument_type       __y) const {
        return (__x.*_C_fn)(__y);
    }

private:
    result_type (_TypeT::*_C_fn)(second_argument_type) const;
};


// 20.3.8, p13
template <class _Result, class _TypeT>
inline const_mem_fun_ref_t<_Result, _TypeT>
mem_fun_ref (_Result (_TypeT::*__fun)() const)
{
    return const_mem_fun_ref_t<_Result, _TypeT>(__fun);
}


template <class _Result, class _TypeT, class _Arg>
inline const_mem_fun1_ref_t<_Result, _TypeT, _Arg>
mem_fun_ref (_Result (_TypeT::*__fun)(_Arg) const)
{
    return const_mem_fun1_ref_t<_Result, _TypeT, _Arg>(__fun);
}


_RWSTD_NAMESPACE_END   // std


_RWSTD_NAMESPACE_BEGIN (__rw)


// extension: returns the argument
template <class _TypeT>
struct identity : public _STD::unary_function<_TypeT, _TypeT>
{
    _RWSTD_UNARY_FUNCTION_TYPES (_TypeT, _TypeT);

    result_type operator() (const argument_type &__val) const {
        return __val;
    }
};


// extension: returns the result of applying the unary plus operator to arg
template <class _TypeT>
struct unary_plus : public _STD::unary_function<_TypeT, _TypeT>
{
    _RWSTD_UNARY_FUNCTION_TYPES (_TypeT, _TypeT);

    result_type operator() (const argument_type &__val) const {
        return +__val;
    }
};


// extension: returns the bitwise complement of the argument
template <class _TypeT>
struct bitwise_complement : public _STD::unary_function<_TypeT, _TypeT>
{
    _RWSTD_UNARY_FUNCTION_TYPES (_TypeT, _TypeT);

    result_type operator() (const argument_type &__val) const {
        return ~__val;
    }
};


// extension: returns the bitwise or of the two arguments
template <class _TypeT>
struct bitwise_or : public _STD::binary_function<_TypeT, _TypeT, _TypeT>
{
    _RWSTD_BINARY_FUNCTION_TYPES (_TypeT, _TypeT, _TypeT);

    result_type operator() (const first_argument_type  &__x,
                            const second_argument_type &__y) const {
        return __x | __y;
    }
};


// extension: returns the bitwise and of the two arguments
template <class _TypeT>
struct bitwise_and : public _STD::binary_function<_TypeT, _TypeT, _TypeT>
{
    _RWSTD_BINARY_FUNCTION_TYPES (_TypeT, _TypeT, _TypeT);

    result_type operator() (const first_argument_type  &__x,
                            const second_argument_type &__y) const {
        return __x & __y;
    }
};


// extension: returns the exclusive or (XOR) of the two arguments
template <class _TypeT>
struct exclusive_or : public _STD::binary_function<_TypeT, _TypeT, _TypeT>
{
    _RWSTD_BINARY_FUNCTION_TYPES (_TypeT, _TypeT, _TypeT);

    result_type operator() (const first_argument_type  &__x,
                            const second_argument_type &__y) const {
        return __x ^ __y;
    }
};


// extension: returns the left argument shifted left by the right argument
template <class _TypeT>
struct shift_left : public _STD::binary_function<_TypeT, _TypeT, _TypeT>
{
    _RWSTD_BINARY_FUNCTION_TYPES (_TypeT, _TypeT, _TypeT);

    result_type operator() (const first_argument_type  &__x,
                            const second_argument_type &__y) const {
        return __x << __y;
    }
};


// extension: returns the left argument shifted right by the right argument
template <class _TypeT>
struct shift_right : public _STD::binary_function<_TypeT, _TypeT, _TypeT>
{
    _RWSTD_BINARY_FUNCTION_TYPES (_TypeT, _TypeT, _TypeT);

    result_type operator() (const first_argument_type  &__x,
                            const second_argument_type &__y) const {
        return __x >> __y;
    }
};


_RWSTD_NAMESPACE_END   // __rw


#undef _RWSTD_UNARY_FUNCTION_TYPES
#undef _RWSTD_BINARY_FUNCTION_TYPES


#endif   // _RWSTD_FUNCTIONAL_INCLUDED

