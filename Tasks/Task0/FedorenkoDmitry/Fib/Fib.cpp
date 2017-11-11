int getFib (int n)
{
    int a0(0), a1(1), fib;
    if (n == 0)
    {
        fib = 0;
    }
    else
    {
        if (n == 1)
        {
            fib = 1;
        }
        else
        {
            if (n < 0)
            {
                for (int i = -1; i >= n; i--)
                {
                    fib = a1 - a0;
                    a1 = a0;
                    a0 = fib;
                }
            }
            else
            {
                for (int i = 2; i <= n; i++)
                {
                    fib = a0 + a1;
                    a0 = a1;
                    a1 = fib;
                }
            }
        }
    }
    return fib;
}

