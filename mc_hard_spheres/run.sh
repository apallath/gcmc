#!/bin/bash
echo "Press Ctrl+C to quit"
./mchs.out < input.in
gnuplot -e 'plot "gcmc.hist" with linespoints; pause -1' 
