//Luis Israel Canaviri Valdes
//C.I. 7094535
// Ejercicio 7
using System;
using System.Collections.Generic;
using System.Threading;
using System.Linq; 

class Program{
    static double calculo_Pi(int procesador, int limite, int procesadores){
        double cpi = 0;
        for (int i = procesador; i < limite; i += procesadores){
            if (i != 0){
                cpi = cpi + 1.0 / (i * i * i * i);
            }
        }
        return cpi;
    }

    static void Main(){
        int limite = 100; 
        int procesadores = Environment.ProcessorCount;

        List<Thread> threads = new List<Thread>();
        List<double> resultados = new List<double>();

        for (int i = 0; i < procesadores; i++){
            int procesador = i;
            Thread thread = new Thread(() =>
            {
                double res = calculo_Pi(procesador, limite, procesadores);
                lock (resultados)
                {
                    resultados.Add(res);
                }
            });

            threads.Add(thread);
            thread.Start();
        }

        foreach (Thread thread in threads){
            thread.Join();
        }
        double suma = resultados.Sum();
        double piEstimado = Math.Pow(suma * 90.0, 0.25);
        Console.WriteLine($"El valor de pi estimado: {piEstimado}");
    }
}
