import numpy as np # para leer los datos y guardarlos en arreglos
import matplotlib.pyplot as plt
import sys

# leer los datos
N, t = np.genfromtxt(sys.argv[1], unpack=True)

# dibujar y guardar a un pdf
fig, ax = plt.subplots()
ax.plot(N, t) #N en x, t en y

#ax.legend() #que aparezcan los labels


# TODO labels
ax.set_ylabel("Tiempo de compilación / t(50)")
ax.set_xlabel("Tamaño de la matriz")


# TODO : Escala log en x y en y 
#ax.set_yscale("log")
#ax.set_xscale("log")


plt.tick_params(top=True, right=True, direction = "in")
# Imprimir la figura
fig.savefig("plot.pdf")