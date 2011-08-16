#ifndef _SELECT_HPP_INCLUDED_FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
#define _SELECT_HPP_INCLUDED_FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF

#include <population.hpp>

namespace ga
{
    struct select
    {
        template<typename F>
        void operator()( const F& f, const population& p_src, population& p_dst ) const
        {
            const auto candidate = f(p_src);
            p_dst.join(candidate);
        }
    };


}//namespace ga

#endif//_SELECT_HPP_INCLUDED_FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF

