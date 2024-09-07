set terminal pngcairo size 1000,1000
set output 'stack_vs_stl.png'

set title 'Stack Performance Comparison'
set ylabel 'Time (in micro sec) -->'
set xlabel 'n --->'
set grid

set datafile separator ','
set key outside

# set logscale y
# not necessary for this plot

plot 'time.csv' using 1:2 with linespoints title 'My stack', \
     'time.csv' using 1:3 with linespoints title 'STL stack'