# Luis Israel Canaviri Valdes
#C.I. 7094535
# Ejercicio 4
import multiprocessing

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
    pool = multiprocessing.Pool()

    resultado_serie1 = pool.apply_async(primera_serie, (2,))  # commienza con 2 como el primer término
    resultado_serie2 = pool.apply_async(segunda_serie)

    serie1 = resultado_serie1.get()
    serie2 = resultado_serie2.get()

    res = intercalar_series(serie1, serie2)

    print(res)