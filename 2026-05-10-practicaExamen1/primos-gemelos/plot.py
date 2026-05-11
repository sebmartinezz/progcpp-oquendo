import numpy as np # para leer los datos y guardarlos en arreglos
import matplotlib.pyplot as plt
import sys

# leer los datos
n, norma = np.genfromtxt(sys.argv[1], unpack=True)

# dibujar y guardar a un pdf
fig, ax = plt.subplots()
ax.plot(n, norma, label="norma de la pareja")
#ax.plot(Y, teo, label="teoric integral")
ax.legend() #que aparezcan los labels


# TODO labels
ax.set_ylabel("norma")
ax.set_xlabel("n-ésima pareja")


# TODO : Escala log en x y en y 
#ax.set_yscale("log")
#ax.set_xscale("log")


plt.tick_params(top=True, right=True, direction = "in")
# Imprimir la figura
fig.savefig("plot.pdf")