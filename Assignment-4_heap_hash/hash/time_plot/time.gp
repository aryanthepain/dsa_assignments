set terminal pngcairo size 1000,1000
set output 'hash_search_plot.png'

set title 'Hash Performance Comparison'
set ylabel 'Time (in micro sec) -->'
set xlabel 'n --->'
set grid

set datafile separator ','
set key outside

# set logscale y
# not necessary for this plot

plot 'time.csv' using 1:2 with linespoints title 'My hash', \
     'time.csv' using 1:3 with linespoints title 'STL hash'