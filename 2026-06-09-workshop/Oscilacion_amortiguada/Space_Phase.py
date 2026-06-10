import numpy as np # para leer los datos y guardarlos en arreglos
import matplotlib.pyplot as plt

# leer los datos
x, y, z = np.genfromtxt("datos.txt", unpack=True)

# dibujar y guardar a un pdf
fig, ax = plt.subplots()
ax.plot(y, z, '-', label="Data")
# todo: labels
fig.savefig("Space_Phase.pdf")