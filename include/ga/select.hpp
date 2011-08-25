#ifndef _SELECT_HPP_INCLUDED_FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
#define _SELECT_HPP_INCLUDED_FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF

#include <ga/population.hpp>
#include <vg.hpp>

#include <algorithm>
#include <cmath>
#include <cstddef>

namespace ga
{

    struct roulette_wheel_selection
    {
        void operator()( population& src, population& dst ) const
        {
            real_type fit_sum = 0;
            std::for_each( src.begin(), src.end(), [&fit_sum]( chromosome& ch ) { fit_sum += ch.fitness(); } );
            std::size_t n = src.size();
            vg::variate_generator<real_type> vg;
            for ( std::size_t i = 0; i < n; ++i )
            {
                const auto r = vg() * fit_sum;
                real_type s = 0;
                for ( auto itor = src.begin(); itor != src.end(); ++itor )
                {
                    s += (*itor).fitness();
                    if ( s > r )
                    {
                        dst.push_back(*itor);
                        break;
                    }//if
                }//itor loop
            }//i loop
        }//operator()
    };//struct roulette_wheel_selection

    struct rank_selection
    {
        void operator()( population& src, population& dst ) const
        {
            std::sort( src.begin(), src.end() ); 
            real_type rank = 2.0;
            //std::for_each( src.begin(), src.end(), [&rank]( chromosome& ch ) { ch.fitness() = rank++; } );
            std::for_each( src.begin(), src.end(), [&rank]( chromosome& ch ) { ch.fitness() = std::log(rank++); } );
            roulette_wheel_selection()(src, dst);
        }
    };


}//namespace ga

#endif//_SELECT_HPP_INCLUDED_FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF

