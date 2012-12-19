# ADT 101 #

A collection of simple implementations of fundamental algorithms and data structures in C99.
The code here will favor readability over performance or genericity.

## C Data Types and Genericity ##

C has proven, time and again, to be a horrible tool for generic programming. "Generic" behavior is usually achieved in C through values of type `(void *)` and `(char *)`. The latter can be dereferenced without fear of trapping (since C99's third Technical Corrigendum). This allows for copying and transferring data whose type is unknown, as long as the size of the type is informed. The use of `(void *)` is more well-known.

Still, the syntax required to achieve this type of behavior would hinder readability. There is also the problem of which duration to use (between C99's *automatic*, *allocated* and *static* - C11 introduced *thread*). This choice has deep effects over any API, because any decision will be followed by heavy requirements and restrictions, which, if not followed, result in undefined behavior. 

## Why C, then? ##

It is still very popular, both in the industry and academia. Many universities teach algorithms and data structures in C, and this is my attempt to contribute while reviewing. Also, I've been wanting to play with the language, but decided that I don't have the time needed to ensure a meaningful C project's correctness.

## Compilation ##

I use [GCC] (http://gcc.gnu.org/). To compile code from this collection, the required flag is `-std=c99`. I also recommend using `-Wall`, `-Wextra` and `-pedantic`. So, to compile the source file `main.c`, I use `gcc -stc=c99 -Wall -Wextra -pedantic main.c -o main`.
