from multiprocessing import Pool
import multiprocessing as mp
def calculo_pi(procesador,limite, procesadores):
  cpi=0
  for i in range(procesador, limite, procesadores):
    if(i!=0):
      cpi=cpi + 1/(i**4)
  return cpi

if __name__=='__main__':
  limite=10000
  entradas=[(i,limite, mp.cpu_count()) for i in range(mp.cpu_count())]
  pool= Pool()
  resultado=pool.starmap(calculo_pi, entradas)
  print(entradas, resultado, pow(sum(resultado)*90,1/4))