#ifndef _XOVER_HPP_INCLUDED_SDFILJLKJTINTOTHESONSDEOI8SDDFLKJVKJSDFKHWOIJFDLKJAOUIBLSLKDJSLKJXVLKLSKLKSDFJSDFJKLSDFJKLSDJ
#define _XOVER_HPP_INCLUDED_SDFILJLKJTINTOTHESONSDEOI8SDDFLKJVKJSDFKHWOIJFDLKJAOUIBLSLKDJSLKJXVLKLSKLKSDFJSDFJKLSDFJKLSDJ

#include <ga_config.hpp>
#include <gene.hpp>
#include <chromosome.hpp>
#include <population.hpp>

namespace ga
{

    struct uniform_xover
    {
        void operator()( integer_type& i1, integer_type& i2 ) const 
        {
            const integer_type upper_mask = 0xAAAAAAAAAAAAAAAAULL;
            const integer_type lower_mask = 0x5555555555555555ULL;
            const integer_type upper_i1 = upper_mask & i1;
            const integer_type upper_i2 = upper_mask & i2;
            const integer_type lower_i1 = lower_mask & i1;
            const integer_type lower_i2 = lower_mask & i2;
            i1 = upper_i1 | lower_i2;
            i2 = upper_i2 | lower_i1;
        }
    };

    struct xover
    {
        //xover two genes following algorithm F
        template<typename F>
        void operator()(conf F&f, gene& g1, gene& g2) const
        {
            g1.encode();
            g2.encode();
            auto c1 = gene_to_gray()(g1.code());
            auto c2 = gene_to_gray()(g2.code());
            f(c1, c2);
            auto c11 = gray_to_gene(c1);
            auto c22 = gray_to_gene(c2);
            g1.code() = c11;
            g2.code() = c22;
            g1.decode();
            g2.decode();
        }

        //xover all genes in two chromosomes
        template<typename F>
        void operator()( const F& f, chromosome& ch1, chromosome& ch2 ) const 
        {
            assert( ch1.size() == ch2.size() );
            auto n = ch1.size();
            for ( std::size_t i = 0; i < n ; ++i )
                xover()(f, ch1[i], ch2[i]);
        }

        //xover all chromosomes in two populations
        template<typename F>
        void operator()( const F& f, population& p1, population& p2 ) const 
        {
            assert( p1.size() == p2.size() );
            auto n = p1.size();
            for ( std::size_t i = 0; i < n ; ++i )
                xover()(f, p1[i], p2[i]);
        }
    };





}//namespace ga

#endif//_XOVER_HPP_INCLUDED_SDFILJLKJTINTOTHESONSDEOI8SDDFLKJVKJSDFKHWOIJFDLKJAOUIBLSLKDJSLKJXVLKLSKLKSDFJSDFJKLSDFJKLSDJ



