set terminal pngcairo size 1000,1000
set output 'queue_vs_stl.png'

set title 'Queue Performance Comparison'
set ylabel 'Time (in micro sec) -->'
set xlabel 'n --->'
set grid

set datafile separator ','
set key outside

# set logscale y
#not necessary for this plot

plot 'time.csv' using 1:2 with linespoints title 'My queue', \
     'time.csv' using 1:3 with linespoints title 'STL queue'