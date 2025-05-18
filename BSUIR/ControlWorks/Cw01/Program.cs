using System.Globalization;

namespace Cw01;

internal static class Program
{
    private static void Main()
    {
        Console.Write("Enter the number of equations (matrix size): ");
        var n = int.Parse(Console.ReadLine()!);

        var a = new double[n, n];
        var b = new double[n];
        var x = new double[n];
        var prevX = new double[n];

        Console.WriteLine("Enter the coefficients of the matrix A:");
        for (var i = 0; i < n; i++)
        {
            Console.Write($"String {i + 1}: ");
            var input = Console.ReadLine()!.Split();
            for (var j = 0; j < n; j++)
                a[i, j] = ParseDouble(input[j]);
        }

        Console.Write("Enter the vector of free terms b: ");
        var bInput = Console.ReadLine()!.Split();
        for (var i = 0; i < n; i++)
            b[i] = ParseDouble(bInput[i]);

        Console.Write("Enter the accuracy (e.g., 0.001): ");
        var epsilon = ParseDouble(Console.ReadLine()!);

        bool converged;
        var iterations = 0;
        do
        {
            converged = true;
            iterations++;
            for (var i = 0; i < n; i++)
            {
                prevX[i] = x[i];
                var sum = b[i];

                for (var j = 0; j < n; j++)
                {
                    if (j != i)
                        sum -= a[i, j] * x[j];
                }

                x[i] = sum / a[i, i];
                if (Math.Abs(x[i] - prevX[i]) > epsilon)
                    converged = false;
            }
        } while (!converged);

        Console.WriteLine($"\nThe solution was found for {iterations} iterations:");
        for (var i = 0; i < n; i++)
            Console.WriteLine($"x[{i + 1}] = {x[i]:F6}");
    }

    private static double ParseDouble(string s)
    {
        s = s.Replace(",", ".");
        return double.Parse(s, CultureInfo.InvariantCulture);
    }
}