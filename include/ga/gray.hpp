#ifndef _GRAY_HPP_INCLUDED_SDOFIJ4O8USAFLKDJOTPIUSFDLKJASLFKDJCVSUIJH4LISFDOIUTOUISDFLKJSDFKLJDSDJKLFHSJKLFOIURLKJSSFIDJH
#define _GRAY_HPP_INCLUDED_SDOFIJ4O8USAFLKDJOTPIUSFDLKJASLFKDJCVSUIJH4LISFDOIUTOUISDFLKJSDFKLJDSDJKLFHSJKLFOIURLKJSSFIDJH

#include <ga/ga_config.hpp>

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

        value_type
        operator()( const value_type v ) const 
        {
            auto ans = v;
            ans ^= ( ans >> 1  );
            ans ^= ( ans >> 2  );
            ans ^= ( ans >> 4  );
            ans ^= ( ans >> 8  );
            ans ^= ( ans >> 16 );
            ans ^= ( ans >> 32 );
            return ans;
        }
        
    };

}//namespace ga

#endif//_GRAY_HPP_INCLUDED_SDOFIJ4O8USAFLKDJOTPIUSFDLKJASLFKDJCVSUIJH4LISFDOIUTOUISDFLKJSDFKLJDSDJKLFHSJKLFOIURLKJSSFIDJH


