/*

CPP wrapper over Festvox binary

Copyright (C) 2015 Sergey Kolevatov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

// $Revision: 2922 $ $Date:: 2015-12-07 #$ $Author: serge $


#include "festvox.h"             // self

#include <sstream>            // std::ostringstream
//#include <iostream>           // std::cout    // DEBUG
#include <cstdlib>            // system

namespace festvox
{


bool Festvox::say( const std::string & text, const std::string & filename, const std::string & lang, std::string & error )
{
    if( lang.empty() )
    {
        error = "lang is not defined";
        return false;
    }

    std::ostringstream s;

    s <<
        "#/bin/bash \n" <<
        "echo '" << text << "' | text2wave -eval '(" << lang << ")' -o " << filename;

    //std::cout << "executing: " << s.str() << std::endl;   // DEBUG

    int ret = system( s.str().c_str() );

    if( WEXITSTATUS(ret) == 0 )
    {
        return true;
    }
    else if( WEXITSTATUS(ret) == 127 )
    {
        error = "cannot find text2wave";
        return false;
    }
    else if( WEXITSTATUS(ret) == 1 )
    {
        error = "invalid parameters";
        return false;
    }

    error = "unknown";
    return false;
}


}   // namespace
