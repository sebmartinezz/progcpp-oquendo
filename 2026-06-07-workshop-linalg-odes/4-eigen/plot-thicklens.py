import numpy as np # para leer los datos y guardarlos en arreglos
import matplotlib.pyplot as plt
import sys

# leer los datos
n, oof, det = np.genfromtxt(sys.argv[1], unpack=True)

# dibujar y guardar a un pdf
fig, ax = plt.subplots()
ax.plot(n, oof, label="oof") #n en x, oof en y
ax.plot(n, det, label="det")
ax.legend() #que aparezcan los labels


# TODO labels
ax.set_ylabel("")
ax.set_xlabel("")


# TODO : Escala log en x y en y 
#ax.set_yscale("log")
#ax.set_xscale("log")


plt.tick_params(top=True, right=True, direction = "in")
# Imprimir la figura
fig.savefig("plot.pdf")