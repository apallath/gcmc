#!/bin/bash
g++ -c common_params.cpp -std=c++11
g++ -c logging.cpp -std=c++11
g++ -c read.cpp -std=c++11
g++ -c mc_moves.cpp -std=c++11
g++ -c interaction.cpp -std=c++11
g++ -c gcmc.cpp -std=c++11
g++ -c main.cpp -std=c++11
g++ common_params.o logging.o read.o mc_moves.o interaction.o gcmc.o main.o -o mchs.out
