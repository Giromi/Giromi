
import numpy as np

class Matrix:
    def __init__(self, mat : list):
        self.matrix : np.matrix = np.matrix(mat)

    def __str__(self):
        return '\n' + str(self.matrix)

    ''' @@@ Operations @@@ '''

    def __add__(self, other):
        return Matrix(np.add(self.matrix, other.matrix).tolist())

    def __sub__(self, other):
        return Matrix(np.subtract(self.matrix, other.matrix).tolist())

    def elementwise_mul(self, other):
        return Matrix(np.multiply(self.matrix, other.matrix).tolist())  # Element-wi

    def __mul__(self, other):
        return np.dot(self.matrix, other.matrix)

    def __matmul__(self, other):
        # return Matrix(np.matmul(self.matrix, other.matrix))
        return Matrix(np.inner(self.matrix.T, other.matrix.T))

    def __mod__(self, other):
        return Matrix(np.outer(self.matrix, other.matrix).tolist())

    def __truediv__(self, other):
        return np.divide(self.matrix, other.matrix)

    def inv(self):
        return Matrix(np.linalg.inv(self.matrix).tolist())

    def inner(self, other):
        return Matrix(np.inner(self.matrix.T, other.matrix.T))
    # want to return inner product based on column vector
    # so, transpose the matrix and then return the inner product

    def T(self):
        return Matrix(self.matrix.T.tolist())

    def __call__(self, row, col):
        if row <= 0 or col <= 0:
            raise ValueError('Row and Column should be greater than 0')
        return self.matrix[row - 1, col - 1]
