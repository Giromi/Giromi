
from fibonacci import fibonacci_def, fibonacci_fn
from time import sleep, perf_counter, perf_counter_ns
from python import Python
#
def check_time_def(test_func, n):
    start = perf_counter()
    result = test_func(n)
    end = perf_counter()
    # print(result)
    print("result\t\t\t: {}".format(result))
    print("Execution Time (Python)\t: {} seconds".format(end - start))

def main():
    Python.add_to_path('./')
    fibonacci_py = Python.import_module('fibonacci').fibonacci
    
    n  = 35  # 비교를 위해 충분히 큰 숫자


    start = perf_counter()
    result = fibonacci_py(n)
    end = perf_counter()
    print('fibonacci_py (python def)')
    print("result\t\t: {}".format(str(result)))
    print("Execution Time\t: {} seconds".format(end - start))

    
    start = perf_counter()
    result = fibonacci_def(n)
    end = perf_counter()
    print('\nfibonacci_def (mojo def)')
    print("result\t\t: {}".format(str(result)))
    print("Execution Time\t: {} seconds".format(end - start))
    #
    start = perf_counter()
    result = fibonacci_fn(n)
    end = perf_counter()
    print('\nfibonacci_fn (mojo fn)')
    print("result\t\t: {}".format(str(result)))
    print("Execution Time\t: {} seconds".format(end - start))

