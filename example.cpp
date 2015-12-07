#include <iostream>         // cout
#include <map>              // std::map

#include "festvox.h"        // festvox

int main()
{
    std::map<std::string, std::string> texts =
    {
            { "voice_don_diphone",          "hello world" },
            { "voice_kal_diphone",          "hello world" },
            { "voice_german_de2_os",        "hallo welt" },
            { "voice_msu_ru_nsh_clunits",   "привет мир" },
            /*
            { "?",  "Bonjour le monde" },
            { "?",  "Hola Mundo" },
            { "?",  "Ciao mondo" },
            */
    };

    festvox::Festvox g;

    std::string error;

    for( auto & s : texts )
    {
        bool b = g.say( s.second, "test_" + s.first + ".wav", s.first, error );

        if( b == false )
            std::cout << "ERROR: failed to generate text for lang '" << s.first
            << "', error " << error << std::endl;
        else
            std::cout << "OK: generated for '" << s.first << "'" << std::endl;
    }

    return 0;
}
