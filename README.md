# Mindera Challenge

This challenge is [one of the three](https://minderacraft.workable.com/jobs/490096) available as part of [Mindera](https://mindera.com/)'s Graduate Program. The challenge solved is more related to backend tasks.

# Description
The full description given is available [online in a Google Docs file](https://docs.google.com/document/d/1voZP8HOmUMy19CKTOq8mZcZRW8bF2lfAT8uqIouZ400/edit) or as [PDF in this repository](AdjacentCellsChallenge.pdf). The files pointed in the PDF file are also available in the [grids directory](grids/), but first uncompressed them to the same folder before you execute the program.

Basically, count the number of islands whose size is bigger than 1. Land is represented as `1` and _water_ as `0`. It is not made the analogy to islands, but adjacent cells. However, if you use the islands keyword you will get better search results.

# Specs
 - Programming language: C++ 14
 - Compiler: g++
 - How to compile?
    - type `make` on your terminal at the root directory
 - How to execute?
    - type `./build/main` on your terminal at the root directory

# How is it solved?

It is used 2 different independent algorithms:
 - [Flood Fill](src/FloodFill.h)
    - Based on the [Flood Fill algorithm](https://en.wikipedia.org/wiki/Flood_fill)
    - Worst performance
 - [Smart Fill](src/SmartFill.h)
    - Use of _buckets_ which group islands with the same id
    - I will not detail much about it, but you can see the logic [here](https://github.com/antonio-ramadas/mindera-challenge/blob/master/src/SmartFill.cpp#L17)
    - Better performance
 - Smart Fill Low Memory
    - Can be considered an improvement of Smart Fill
    - I did not implement this (a.k.a., left as exercise to the reader :) )
    - Basically, instead of reading the entire grid to memory, just read 1 line (_row_) at the time and keep only the most recent 2 (to understand this you need to understand the logic of Smart Fill).
    - Best performance

Please note that when I mentioned performance I combine the tradeoffs of time and space complexities. Depending on the mindset, this interpretation could be wrong.

## Variants
 - [Flood Fill](https://en.wikipedia.org/wiki/Flood_fill)
 - [Number of Islands](https://leetcode.com/problems/number-of-islands/description/)
 - [Surrounded Regions](https://leetcode.com/problems/surrounded-regions/description/)
 - [Max Area of Island](https://leetcode.com/problems/max-area-of-island/description/)
 - And many more...

 # Warning
 
 The repository size is small except for the [grids directory](grids/) which is almost 90MB. I did not use an external storage service, because I want this repository to stand the test of time.

# TO DO
 - [ ] Improve descriptions of the algorithms
 - [ ] Refactor [Smart Fill](https://github.com/antonio-ramadas/mindera-challenge/blob/master/src/SmartFill.cpp#L5)
 - [ ] Implement Smart Fill Low Memory
 - [ ] Improve README.md
 - [ ] Include benchmarks
 - [ ] Include tests
