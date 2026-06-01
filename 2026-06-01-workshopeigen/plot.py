import numpy as np # para leer los datos y guardarlos en arreglos
import matplotlib.pyplot as plt
import sys

# leer los datos
k, m1, m2, lmbd1, lmbd2 = np.genfromtxt(sys.argv[1], unpack=True)

for i in range(len(lmbd1)):
    if lmbd1[i] > lmbd2[i]:
        # Intercambiar valores
        lmbd1[i], lmbd2[i] = lmbd2[i], lmbd1[i]

# dibujar y guardar a un pdf
fig, ax = plt.subplots()
ax.plot(m1, lmbd1, label = "first eigen value") #m1 en x, lmbd2 en y
ax.plot(m1, lmbd2, label = "second eigen value")
ax.legend() #que aparezcan los labels


# TODO labels
ax.set_ylabel("eigen value (rad^2/s^2)")
ax.set_xlabel("m1 (kg)")


# TODO : Escala log en x y en y 
ax.set_yscale("log")
ax.set_xscale("log")


plt.tick_params(top=True, right=True, direction = "in", which='both')
# Imprimir la figura
fig.savefig("plot.pdf")