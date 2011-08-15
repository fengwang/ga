#ifndef _GRAY_HPP_INCLUDED_SDOFIJ4O8USAFLKDJOTPIUSFDLKJASLFKDJCVSUIJH4LISFDOIUTOUISDFLKJSDFKLJDSDJKLFHSJKLFOIURLKJSSFIDJH
#define _GRAY_HPP_INCLUDED_SDOFIJ4O8USAFLKDJOTPIUSFDLKJASLFKDJCVSUIJH4LISFDOIUTOUISDFLKJSDFKLJDSDJKLFHSJKLFOIURLKJSSFIDJH

#include <ga/ga_config.hpp>

#include <cstddef>

namespace ga
{
    
    /*
     * Gray encoding and decoding numeric algorithms
     */

    //encoding
    struct gene_to_gray
    {   //integer_type defined in ga/ga_config.hpp
        typedef integer_type value_type;

        value_type 
        operator()( const value_type v ) const
        {
            return v ^ ( v >> 1 );
        }
    };

    //decoding
    struct gray_to_gene
    {   //integer_type defined in ga/ga_config.hpp
        typedef integer_type value_type;
        typedef std::size_t size_type;

        value_type
        operator()( const value_type v ) const 
        {
            value_type ans = v;
            size_type ishift = 1;
            const size_type ibits = sizeof(v) << 3;

            for(;;)
            {
                const value_type idiv = ans >> ishift;
                ans ^= idiv;
                if ( (ishift<<=1) && ((idiv<=1)||(ibits==ishift)) ) 
                    return ans;
            }
        }
        
    };

}//namespace ga

#endif//_GRAY_HPP_INCLUDED_SDOFIJ4O8USAFLKDJOTPIUSFDLKJASLFKDJCVSUIJH4LISFDOIUTOUISDFLKJSDFKLJDSDJKLFHSJKLFOIURLKJSSFIDJH


