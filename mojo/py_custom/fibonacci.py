import time

def fibonacci(n: int) -> int:
    if n <= 1:
        return n
    return fibonacci(n - 1) + fibonacci(n - 2)



if __name__ == '__main__':
    start = time.time()
    result = fibonacci(35)
    end = time.time()
    print('fibonacci_py (python def)')
    print("result\t\t: {}".format(result))
    print("Execution Time\t: {} seconds".format(end - start))


