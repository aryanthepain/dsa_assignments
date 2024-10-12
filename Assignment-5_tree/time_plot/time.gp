set terminal pngcairo size 1000,1000
set output 'bst_plot.png'

set title 'BST Performance Comparison'
set ylabel 'Time (in micro sec) -->'
set xlabel 'n --->'
set grid

set datafile separator ','
set key outside

set logscale y

plot 'time.csv' using 1:2 with linespoints title 'My BST', \
     'time.csv' using 1:3 with linespoints title 'STL map'