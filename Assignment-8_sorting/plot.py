import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
data = pd.read_csv("sort_times.csv")


# Define markers for each algorithm
markers = ['o', 's', 'D', '^', 'v', '>', '<', 'p']

# Plot the data
plt.figure(figsize=(10, 6))

# Plot each algorithm with different markers
for i, column in enumerate(data.columns[1:]):
    plt.plot(data['Size'], data[column], label=column, marker=markers[i])

# Set logarithmic scale
plt.xscale('log')
plt.yscale('log')

# Add labels and title
plt.xlabel('Size of Array')
plt.ylabel('Time (microseconds)')
plt.title('Sorting Algorithms Performance')
plt.legend()
plt.grid(True, which="both", ls="--")
plt.tight_layout()

# Show the plot
plt.show()
