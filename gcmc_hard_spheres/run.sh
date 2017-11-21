#!/bin/bash
echo "Running from initial input file"
./mchs.out < input_init.in
echo "Running again"
./mchs.out < input.in
echo "Plotting"
python make_plots.py
mkdir out
mv gcmc.hist out/
mv gcmc.log out/
cp input.in out/
for i in *.[Pp][Nn][Gg]; do
    mv $i out/
done
cp particles.state out/
mv rdf.dat out/
echo "Done"


