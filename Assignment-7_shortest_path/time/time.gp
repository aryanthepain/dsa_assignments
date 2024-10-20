set terminal pngcairo size 1000,1000
set output 'graph_times_plot.png'

set title 'Graph Algorithm Performance Comparison'

set ylabel 'Time (in micro sec) -->'
set xlabel 'Graph Size (n) --->'

set grid
set datafile separator ','
set key outside

set logscale y

plot 'graph_times.csv' using 1:2 with linespoints title 'Dijkstra', \
     'graph_times.csv' using 1:3 with linespoints title 'Bellman-Ford', \
     'graph_times.csv' using 1:4 with linespoints title 'Floyd-Warshall'
