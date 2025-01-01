
def fibonacci_def(n: Int) -> Int:
    if n <= 1:
        return n
    return fibonacci_def(n - 1) + fibonacci_def(n - 2)


fn fibonacci_fn(n: Int) -> Int:
    if n <= 1:
        return n
    return fibonacci_fn(n - 1) + fibonacci_fn(n - 2)

