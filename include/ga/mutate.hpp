#ifndef _MUTATE_HPP_INCLUDED_SFODIJ438UISDFKLCVKLSJSLFKJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
#define _MUTATE_HPP_INCLUDED_SFODIJ438UISDFKLCVKLSJSLFKJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ

#include <ga/ga_config.hpp>
#include <ga/population.hpp>
#include <ga/gray.hpp>
#include <vg.hpp>

#include <cstddef>

namespace vg
{

    struct mutate
    {
       real_type r_;
       mutate( const real_type r ) : r_(r) {}

       void operator()( population& p ) const 
       {
           const auto n = sizeof(integer_type) << 3;
           vg::variate_generator<real_type> vg1(0, 1);
           vg::variate_generator<integer_type> vg2(1, n-1);

            for ( auto ch : p )         //for all chromosomes in the population
                for ( auto g : ch )     //for all genes in the chromosome
                    if ( vg1() < r )    //case mutate
                    {
                        g.encode();     //real -> integer
                        auto c = gene_to_gray()(g.code()); // c -> gray
                        c ^= ( 1 << vg2() ); //reverse a random bit
                        g.code() = gray_to_gene()(c);      // gray -> code
                        g.decode();     //integer -> real
                    }
       }
    
    };

}//namespace vg

#endif//_MUTATE_HPP_INCLUDED_SFODIJ438UISDFKLCVKLSJSLFKJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ

