static int Fib [30];

int getFib (int n)
{
    Fib[0] = 1;
    Fib[1] = 1;
    if ((n == 0) or (n == 1))
        return n;
    else
        for (int i = 2; i < n; i++)
        {
            Fib[i] = Fib[i-2] + Fib[i-1];
        }
    return Fib[n-1];
}

