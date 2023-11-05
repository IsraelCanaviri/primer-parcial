# Luis Israel Canaviri Valdes
#C.I. 7094535
# Ejercicio 6

from mpi4py import MPI

def primera_serie(n):
    serie1 = [n]
    for i in range(1, 10000):
        n += 2 * i + 1
        serie1.append(n)
    return serie1

def segunda_serie():
    empiezo = 2
    fin = 20000  
    serie2 = list(range(empiezo, fin + 2, 2))
    return serie2

def intercalar_series(serie1, serie2):
    completando_serie = [val for pair in zip(serie1, serie2) for val in pair]
    return completando_serie

if __name__ == "__main__":
    comm = MPI.COMM_WORLD
    rank = comm.Get_rank()

    if rank == 0:
        resultado_serie1 = primera_serie(2)
        resultado_serie2 = segunda_serie()
    else:
        resultado_serie1 = None
        resultado_serie2 = None

    serie1 = comm.bcast(resultado_serie1, root=0)
    serie2 = comm.bcast(resultado_serie2, root=0)

    local_res = intercalar_series(serie1, serie2)

    gathered_res = comm.gather(local_res, root=0)

    if rank == 0:
        final_result = [val for sublist in gathered_res for val in sublist]
        print(final_result)