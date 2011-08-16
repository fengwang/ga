#ifndef _CHROMOSOME_HPP_INCLUDED_SDOFI4OIUSFDLKJSFLKJCVMDKLJFSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSFSLKJSALKFJSKLJFDJDOIO
#define _CHROMOSOME_HPP_INCLUDED_SDOFI4OIUSFDLKJSFLKJCVMDKLJFSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSFSLKJSALKFJSKLJFDJDOIO

#include <gene.hpp>
#include <vector>
#include <cstddef>

namespace ga
{

    struct chromosome
    {
        typedef gene                        value_type;
        typedef std::vector<value_type>     array_type;
        typedef array_type::iterator        iterator;
        typedef array_type::const_iterator  const iterator;
        typedef std::size_t                 size_type;

        chromosome(const size_type n=1) 
        { ch_.resize(n); }

        void resize(const size_type n)
        { ch_.resize(n); }

        size_type size() const 
        { return ch_.size(); }

        value_type operator[](const size_type n) const
        { return ch_[n]; }

        value_type& operator[](const size_type n)
        { return ch_[n]; }

        iterator begin() 
        { return ch_.begin(); }
        
        const_iterator begin() const
        { return ch_.begin(); }

        iterator end() 
        { return ch_.end(); }
        
        const_iterator end() const
        { return ch_.end(); }
 
        real_type fitness() const
        { return fitness_; }

        real_type& fitness()
        { return fitness_; }

        array_type  ch_;
        real_type   fitness_;
    };


    bool operator < ( const chromosome& lhs, const chromosome& rhs )
    { return lhs.fitness() < rhs.fitness(); }

    bool operator <= ( const chromosome& lhs, const chromosome& rhs )
    { return lhs.fitness() <= rhs.fitness(); }

    bool operator > ( const chromosome& lhs, const chromosome& rhs )
    { return lhs.fitness() > rhs.fitness(); }

    bool operator >= ( const chromosome& lhs, const chromosome& rhs )
    { return lhs.fitness() >= rhs.fitness(); }

}//namespace ga

#endif//_CHROMOSOME_HPP_INCLUDED_SDOFI4OIUSFDLKJSFLKJCVMDKLJFSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSFSLKJSALKFJSKLJFDJDOIO

