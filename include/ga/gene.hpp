#ifndef _GENE_HPP_INCLUDED_SDOFJI43O8USAFDSFDIUO4KLJVCSFDIOU4OI3UKLFJDJKSDFJKLFSDJKLSDFJKLSDFJKLSDFWERIOUWERIODKLSDFLKSLK
#define _GENE_HPP_INCLUDED_SDOFJI43O8USAFDSFDIUO4KLJVCSFDIOU4OI3UKLFJDJKSDFJKLFSDJKLSDFJKLSDFJKLSDFWERIOUWERIODKLSDFLKSLK

#include <ga/ga_config.hpp>

#include <limits>
#include <cassert>

namespace ga
{
    
    struct gene
    {
        typedef real_type                           value_type;
        typedef integer_type                        coding_type;
        typedef std::numeric_limits<coding_type>    limits_type;
        typedef gene                                self_type;
    
        gene( const value_type l, const value_type u ) : l_(l), u_(u) 
        { assert( l < u ); }

        gene( const self_type& other ) : v_(other.v_), l_(other.l_), u_(other.u_)
        {}

        self_type& operator = ( const value_type v ) 
        {
            assert( v > l_ );
            assert( v < u_ );
            v_ = v;  
            return *this; 
        }

        operator value_type() const
        { return v_; }

        value_type value() const
        { return v_; }

        coding_type export_coding() const 
        {
            const value_type min_c = limits_type::min();
            const value_type max_c = limits_type::max();
            const value_type ratio = ( v_ - l_ ) / ( u_ - l_ );
            const value_type ans   = ratio * ( max_c - min_c ) + min_c;
            return ans;
        }

        void import_coding( const coding_type n ) 
        {
            const value_type min_c = limits_type::min();
            const value_type max_c = limits_type::max();
            const value_type c = n;
            const value_type ratio = ( c - min_c ) / ( max_c - min_c );
            v_ = ratio * ( u_ - l_ ) + l_;
        }

        real_type v_;
        real_type l_;
        real_type u_;
    };



};

#endif//_GENE_HPP_INCLUDED_SDOFJI43O8USAFDSFDIUO4KLJVCSFDIOU4OI3UKLFJDJKSDFJKLFSDJKLSDFJKLSDFJKLSDFWERIOUWERIODKLSDFLKSLK




