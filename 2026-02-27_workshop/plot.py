import numpy as np
import matplotlib.pyplot as plt

x, y = np.genfrontxt("datossq.txt", unpack=True)
fig, ax=plt.subplot()
ax.plot(x, y, "-*", label="Data")
fig.savefig("plot.pdf")