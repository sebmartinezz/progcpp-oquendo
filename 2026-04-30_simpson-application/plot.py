import numpy as np # para leer los datos y guardarlos en arreglos
import matplotlib.pyplot as plt
import sys

# leer los datos
h, e_trap, e_simp, e_r_trap, e_r_simp = np.genfromtxt(sys.argv[1], unpack=True)

# dibujar y guardar a un pdf
fig, ax = plt.subplots()
ax.plot(h, e_trap, label="trapezoidal")
ax.plot(h, e_simp, label="simpson")
ax.plot(h, e_r_trap, label="richardson trapezoidal")
ax.plot(h, e_r_simp, label="richardson simpson")
ax.legend() #que aparezcan los labels


# TODO labels
ax.set_ylabel("diferencia relativa (log)")
ax.set_xlabel("tamaño de paso (log)")


# TODO : Escala log en x y en y 
ax.set_yscale("log")
ax.set_xscale("log")


plt.tick_params(top=True, right=True, direction = "in")
# Imprimir la figura
fig.savefig("plot.pdf")