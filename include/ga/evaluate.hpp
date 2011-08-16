#ifndef _EVALUATE_HPP_INCLUDED_SFOIJ3489USDFKLJALFKJCSSSSSSSI4SFDDFJKHLAKJ02309USLIJ1I2USDFLKJCVNDFJKHSLKJFSOIEROIU34KLSL
#define _EVALUATE_HPP_INCLUDED_SFOIJ3489USDFKLJALFKJCSSSSSSSI4SFDDFJKHLAKJ02309USLIJ1I2USDFLKJCVNDFJKHSLKJFSOIEROIU34KLSL

#include <population.hpp>
#include <chromosome.hpp>
#include <ga_config.hpp>
#include <vector>

namespace ga
{
    struct evaluate
    {
        template<typename F>
        void operator()( const F& f, chromosome& ch ) const 
        {
            std::vector<real_type> x; 
            for ( auto g : ch )
                x.push_back(g.value());
            ch.fitness() = f(x);
        }

        template<typename F>
        void operator()( const F& f, population& p ) const
        {
            for ( auto ch : p )
                evaluate()(f, ch);
        }
    };

}//namespace ga

#endif//_EVALUATE_HPP_INCLUDED_SFOIJ3489USDFKLJALFKJCSSSSSSSI4SFDDFJKHLAKJ02309USLIJ1I2USDFLKJCVNDFJKHSLKJFSOIEROIU34KLSL


