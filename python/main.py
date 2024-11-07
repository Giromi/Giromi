from Matrix import Matrix, np


def np_test():
  A = np.array([[1, 2], [3, 4]])
  B = np.array([[5, 6], [7, 8]])

  print(A, B, A * B, sep='\n')
  # Output:
  # [[ 5 12]
  #  [21 32]]
  print()

  print(A, B, A @ B, sep='\n')
  # Output:
  # [[19 22]
  #  [43 50]]

def matrix_test():
    # <class 'numpy.matrix'>
    a = Matrix([[4, 1], [1, 2]])
    # param type hints to prevent under case
    # b = Matrix(np.array([[6], [5]])) 
    b = Matrix([[6], [5]])

    print('\nMatrix a :', a)
    print('\nMatrix b :', b)
    print('\nMatrix elementwise_mul :', a.elementwise_mul(b))

    print('\nColumn Vector :', b)
    print('\nRow Vector :', b.T())

    res = a.inv() @ b
    print('\nThe answer :', type(res), res)

    c = Matrix([[1], [2]])
    d = Matrix([[3], [4]])

    '''
    print('\nMatrix mul :', c * d, sep='\n') 
    => error due to shape mismatch
    '''

    print('\nMatrix mul :', c.T() * d) # Same
    print('\nMatrix matmul :', c @ d) # Same
    print('\nMatrix inner :', c.inner(d)) # Same

    c_nd = c.matrix
    d_nd = d.matrix

    print('\nndarray mul :', c_nd.T @ d_nd)

    # print('\nMatrix inv :', c.inv(), sep='\n')

    print('\nMatrix c Transpose :', c.T())
    print('\nMatrix d Transpose :', d.T())

    # print('\nMatrix inner :', c.T().inner(d.T()), sep='\n')

    p = Matrix([[1], [0], [0]])
    q = Matrix([[0], [1], [0]])
    r = Matrix([[0], [0], [1]])


    print(p(1, 1))  # Output: 6

    print('\nMatrix Outer :', p % q)
    print('\nMatrix Outer :', q % p)
    print('\nMatrix Outer :', q % r)
    print('\nMatrix Outer :', r % p)

    # print('\nMatrix Outer :', p.T() % q.T(), sep='\n')
    # print('\nMatrix Outer :', q.T() % r.T() , sep='\n')
    # print('\nMatrix Outer :', r.T() % p.T() , sep='\n')

def main():
    # np_test()
    matrix_test()


if __name__ == "__main__":
    main()
