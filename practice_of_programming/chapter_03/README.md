# Notes

This chapter contains a number of implentation of the Markov chain algorithm
for generating pseudo-random text.

> set _w1_ and _w2_ to the first two words in the text
> print _w1_ and _w2_
> loop:
>   randomly choose _w3_, one of the successors of prefix _w1_ _w2_ in the text
>   print _w3_
>   replace _w1_ and _w2_ by _w2_ and _w3_
>   repeat loop

The local implementation is written only in C and matches the book text outside
of naming conventions and style.

_In order to really make the algorithm shine, the source text must be fairly
long. Something like a whole book or long chapters work._