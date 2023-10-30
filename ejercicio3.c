
from mpi4py import MPI

def main():
    comm = MPI.COMM_WORLD
    rank = comm.Get_rank()
    size = comm.Get_size()

    frase = "tres tristes tigres trigaban trigo por culpa del bolivar"
    palabras = frase.split()

    total_palabras = len(palabras)
    
    # Se dividen las palabras en dos secciones 
    seccion_p= []
    seccion_i = []
    
    for i in range(total_palabras):
        if i % 2 == 0:
            seccion_p.append(palabras[i])
        else:
            seccion_i.append(palabras[i])

    # Se divide el trabajo entre los hilos MPI
    if rank == 0:
        print("Palabras primera parte:", seccion_p)
    elif rank == 1:
        print("Palabras segunda parte:", seccion_i)

if __name__ == "__main__":
    main()
