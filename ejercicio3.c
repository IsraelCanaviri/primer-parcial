pip install mpi4py
from mpi4py import MPI

def main():
    comm = MPI.COMM_WORLD
    rank = comm.Get_rank()
    size = comm.Get_size()

    frase = "tres tristes tigres trigaban trigo por culpa del bolivar"
    palabras = frase.split()

    total_palabras = len(palabras)
    
    # Se dividen las palabras en dos secciones (pares e impares)
    seccion_pares = []
    seccion_impares = []
    
    for i in range(total_palabras):
        if i % 2 == 0:
            seccion_pares.append(palabras[i])
        else:
            seccion_impares.append(palabras[i])

    # Se divide el trabajo entre los hilos MPI
    if rank == 0:
        print("Palabras en posiciones pares:", seccion_pares)
    elif rank == 1:
        print("Palabras en posiciones impares:", seccion_impares)

if __name__ == "__main__":
    main()