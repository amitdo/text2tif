/*
https://git.enlightenment.org/core/efl.git/tree/COPYING?h=v1.16.1

Licensing

EFL comes with several licences. Different shared libraries are
covered by different licenses, and are distributed here as an
aggregation with a single build system. Listed below are the library/project
names and the license file covering it. Note that this license would
cover all of the source invovled in each project (src/lib/PROJECT,
src/modules/PROJECT, src/bin/PROJECT data/PROJECT) unless specifically
noted otherwise (eg epp in edje or lz4, libunibreak etc.), so please
refer to these imported project sources for details (but be aware that
the licensing of such libraries is compatible with the libraries that
use them and is not more restrictive).

evil:            licenses/COPYING.BSD



https://git.enlightenment.org/core/efl.git/tree/licenses/COPYING.BSD?h=v1.16.1

Copyright notice for the EFL:

Copyright (C) 2002-2015 EFL developers (see AUTHORS)

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
   2. Redistributions in binary form must reproduce the above copyright 
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.



Source:
https://git.enlightenment.org/core/efl.git/tree/src/lib/evil/evil_string.c?h=v1.16.1
*/


#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "strcasestr.h"

char *strcasestr(const char *haystack, const char *needle)
{
   size_t length_needle;
   size_t length_haystack;
   size_t i;

   if (!haystack || !needle)
     return NULL;

   length_needle = strlen(needle);
   length_haystack = strlen(haystack);
   if (length_haystack < length_needle) return NULL;
   length_haystack = length_haystack - length_needle + 1;

   for (i = 0; i < length_haystack; i++)
     {
        size_t j;

        for (j = 0; j < length_needle; j++)
          {
            unsigned char c1;
            unsigned char c2;

            c1 = haystack[i+j];
            c2 = needle[j];
            if (toupper(c1) != toupper(c2))
              goto next;
          }
        return (char *) haystack + i;
     next:
        ;
     }

   return NULL;
}
