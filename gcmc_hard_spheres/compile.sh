#!/bin/bash
g++ -c common_params.cpp -std=c++11 -g
g++ -c logging.cpp -std=c++11 -g
g++ -c read.cpp -std=c++11 -g
g++ -c mc_moves.cpp -std=c++11 -g
g++ -c interaction.cpp -std=c++11 -g
g++ -c sampling.cpp -std=c++11 -g
g++ -c gcmc.cpp -std=c++11 -g
g++ -c state.cpp -std=c++11 -g
g++ -c main.cpp -std=c++11 -g
g++ common_params.o logging.o read.o mc_moves.o interaction.o sampling.o gcmc.o state.o main.o -o mchs.out -g

if [[ -d dist ]]; then
    rm -r dist
fi
mkdir dist
mv mchs.out dist/
mv make_plots.py dist/
mv run.sh dist/
mv sample_input.in dist/input.in
