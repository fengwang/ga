#ifndef _POPULATION_HPP_INCLUDED_OSDFIJ489UFSDLKJSKLJALKJCVSIUOIU498FSDLIEROIULKJFSDLSKFJSLKFJNXVSJKHSDFOIU4ISDF984IUFOIU
#define _POPULATION_HPP_INCLUDED_OSDFIJ489UFSDLKJSKLJALKJCVSIUOIU498FSDLIEROIULKJFSDLSKFJSLKFJNXVSJKHSDFOIU4ISDF984IUFOIU

#include <ga/ga_config.hpp>
#include <ga/chromosome.hpp>
#include <vg.hpp>
#include <vector>
#include <cstddef>

namespace ga
{

    struct population
    {
        typedef chromosome                  value_type;
        typedef std::vector<value_type>     array_type;
        typedef array_type::iterator        iterator;
        typedef array_type::const_iterator  const_iterator;
        typedef std::size_t                 size_type;

        iterator begin() 
        { return p_.begin(); }

        const_iterator begin() const 
        { return p_.begin(); }

        iterator end() 
        { return p_.end(); }

        const_iterator end() const 
        { return p_.end(); }

        population( const size_type n=0 )
        { p_.resize( n ); }

        void push_back( const value_type v )
        { p_.push_back(v); }

        value_type 
        operator[]( const size_type n ) const
        { return p_[n]; }

        value_type&
        operator[]( const size_type n ) 
        { return p_[n]; }

        void set_chromosome_length( const size_type n )
        { 
            for ( auto ch : p_ )
                ch.resize(n);
        }

        //set ith gene lower boundary and upperboundary
        void set_gene_boundary( const size_type i=0, const real_type l=0, const real_type u=1 )
        {
            assert( i < p_[0].size() );
            assert( l < u );
            for ( auto ch : p_ )
            {
                ch[i].lower() = l;
                ch[i].upper() = u;
            }
        }

        void initialize()
        {
            const auto m = p_[0].size();
            const auto n = p_.size();
            for ( size_type i = 0; i < m; ++i )
            {
                const auto l = p_[0][i].lower();
                const auto u = p_[0][i].upper();
                vg::variate_generator<real_type> uniform_vg( l, u );
                for ( size_type j = 0; j < n; ++j )
                {
                    p_[j][i].value() = uniform_vg();
                    p_[j][i].encode();
                }
            }
        }

        array_type p_;
    };

}//namespace ga

#endif//_POPULATION_HPP_INCLUDED_OSDFIJ489UFSDLKJSKLJALKJCVSIUOIU498FSDLIEROIULKJFSDLSKFJSLKFJNXVSJKHSDFOIU4ISDF984IUFOIU

