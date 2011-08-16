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
    
        gene( const value_type l=real_type(0), const value_type u=real_type(1) ) : v_(l_), l_(l), u_(u), c_(0) 
        { assert( l < u ); }

        gene( const self_type& other ) : v_(other.v_), l_(other.l_), u_(other.u_), c_(other.c_)
        {}

        //real -> integer :: v_ -> c_
        void encode() 
        {
            const value_type min_c = limits_type::min();
            const value_type max_c = limits_type::max();
            const value_type ratio = ( v_ - l_ ) / ( u_ - l_ );
            c_   = ratio * ( max_c - min_c ) + min_c;
        }

        //integer -> real :: c_ -> v_
        void decode() 
        {
            const value_type min_c = limits_type::min();
            const value_type max_c = limits_type::max();
            const value_type ratio = ( c_ - min_c ) / ( max_c - min_c );
            v_ = ratio * ( u_ - l_ ) + l_;
        }

        real_type value() const 
        { return v_; }

        real_type& value()
        { return v_; }

        real_type operator()() const 
        { return v_; }

        real_type& operator()()
        { return v_; }

        real_type lower() const 
        { return l_; }

        real_type& lower()
        { return l_; }

        real_type upper() const 
        { return u_; }

        real_type& upper()
        { return u_; }

        coding_type code() const
        { return c_; }

        coding_type& code()
        { return c_; }

        real_type       v_;         //real value of the gene
        real_type       l_;         //lower boundary of the gene value
        real_type       u_;         //upper boundary of the gene value
        coding_type     c_;         //binary format gene value
    };



};

#endif//_GENE_HPP_INCLUDED_SDOFJI43O8USAFDSFDIUO4KLJVCSFDIOU4OI3UKLFJDJKSDFJKLFSDJKLSDFJKLSDFJKLSDFWERIOUWERIODKLSDFLKSLK




