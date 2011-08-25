#ifndef _EVALUATE_HPP_INCLUDED_SFOIJ3489USDFKLJALFKJCSSSSSSSI4SFDDFJKHLAKJ02309USLIJ1I2USDFLKJCVNDFJKHSLKJFSOIEROIU34KLSL
#define _EVALUATE_HPP_INCLUDED_SFOIJ3489USDFKLJALFKJCSSSSSSSI4SFDDFJKHLAKJ02309USLIJ1I2USDFLKJCVNDFJKHSLKJFSOIEROIU34KLSL

#include <ga/population.hpp>

#include <cassert>
#include <vector>
#include <iterator>

namespace ga
{

    struct evaluate
    {
        /*
        typedef T                                                   decode_value_type;
        typedef std::function<decode_value_type(const chromosome&)> decode_function_type;
        typedef std::function<real_type(decode_value_type)>         evaluation_function_type;
        decode_function_type        df_;
        evaluation_function_type    ef_;
        */
        //
        //  input:
        //              df      ----    convert chromosome to target value type( such as vector, array ... )
        //              ef      ----    receive a target value type parameter, return evaluation result( a real type)
        //
        template<typename Dec_Fun, typename Eva_Fun>
        void operator()( population& p, const Dec_Fun& df, const Eva_Fun& ef ) const
        {
            for ( auto ch : p )
                ch.fitness() = ef(df(ch));
        }
    };

    struct chromosome_to_vector
    {
        std::vector<real_type>
        operator()( const chromosome& ch ) const 
        {
            std::vector<real_type> ans;
            std::for_each( ch.begin(), ch.end(), [&ans](gene& g){ ans.push_back( g() ); } );
            return ans;
        }
    };

    struct chromosome_to_real
    {
        real_type
        operator()( const chromosome& ch ) const 
        {
            assert( 1 == ch.size() );
            return (ch[0])();
        }
    };


}//namespace ga

#endif//_EVALUATE_HPP_INCLUDED_SFOIJ3489USDFKLJALFKJCSSSSSSSI4SFDDFJKHLAKJ02309USLIJ1I2USDFLKJCVNDFJKHSLKJFSOIEROIU34KLSL


