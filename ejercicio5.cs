

using System;
using System.Threading;

class Program
{
    static int[] primeraSerie(int n)
    {
        int[] serie1 = new int[10000];
        serie1[0] = n;

        for (int i = 1; i < 10000; i++)
        {
            n += 2 * i + 1;
            serie1[i] = n;
        }

        return serie1;
    }

    static int[] segundaSerie()
    {
        int empiezo = 2;
        int fin = 20000;
        int[] serie2 = new int[(fin - empiezo) / 2 + 1];

        for (int i = 0; i < serie2.Length; i++)
        {
            serie2[i] = empiezo + 2 * i;
        }

        return serie2;
    }

    static int[] intercalarSeries(int[] serie1, int[] serie2)
    {
        int[] completandoSerie = new int[serie1.Length + serie2.Length];
        int index = 0;

        for (int i = 0; i < serie1.Length && i < serie2.Length; i++)
        {
            completandoSerie[index++] = serie1[i];
            completandoSerie[index++] = serie2[i];
        }

        return completandoSerie;
    }

    static void Main()
    {
        int[] serie1 = new int[10000];
        int[] serie2 = new int[10000];
        int[] res = new int[20000];

        Thread t1 = new Thread(() =>
        {
            serie1 = primeraSerie(2);
        });

        Thread t2 = new Thread(() =>
        {
            serie2 = segundaSerie();
        });

        t1.Start();
        t2.Start();

        t1.Join();
        t2.Join();

        res = intercalarSeries(serie1, serie2);

        foreach (int val in res)
        {
            Console.Write(val + " ");
        }
    }
}