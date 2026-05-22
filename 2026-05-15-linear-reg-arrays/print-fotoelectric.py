import numpy as np # para leer los datos y guardarlos en arreglos
import matplotlib.pyplot as plt
import sys

# leer los datos
nu, V = np.genfromtxt(sys.argv[1], unpack=True)
nu_teo, V_teo = np.genfromtxt(sys.argv[2], unpack=True)

# dibujar y guardar a un pdf
fig, ax = plt.subplots()
ax.scatter(nu, V, color='black', s=10, label="datos experimentales")
ax.plot(nu_teo, V_teo, color='purple', label="ajuste lineal")

# TODO labels
ax.set_ylabel("Voltaje")
ax.set_xlabel("Frecuencia")

# TODO : Escala log en x y en y 
#ax.set_yscale("log")
#ax.set_xscale("log")

plt.tick_params(top=True, right=True, direction = "in")


descripcion = (
    "h calculado: 6.550062e-34 J s" "\n"
    "phi calculado: 1.731235e+00 eV"
)

# Colocamos el cuadro adentro, arriba a la izquierda (X=0.05, Y=0.85)
ax.text(
    0.05, 0.85, 
    descripcion, 
    fontsize=9,
    verticalalignment='top',
    horizontalalignment='left',
    transform=ax.transAxes, # Coordenadas fijas de 0 a 1 respecto al gráfico

)

# Activamos la leyenda para que sepa cuál es el ajuste y cuáles los datos
ax.legend(loc="lower right")

# Guardar asegurando que nada se corte
fig.savefig("plot.pdf")