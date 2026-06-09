import numpy as np # para leer los datos y guardarlos en arreglos
import matplotlib.pyplot as plt
import sys

# leer los datos
t, pos, vel = np.genfromtxt(sys.argv[1], unpack=True)

# dibujar y guardar a un pdf
fig, ax = plt.subplots()
ax.plot(t, pos, label="oof") #t en x, pos en y
ax.plot(t, vel, label="det")
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