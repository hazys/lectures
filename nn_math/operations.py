import numpy as np
import scipy as sp
import tensor
import utils
import itertools
from utils import *







class Operation:

    def __init__(self):
        self._res = None

    def forward(self):
        pass

    def backward(self, np_tensor):
        pass


class VariableOperation(Operation):

    def __init__(self, x):
        super().__init__()
        self._x = x

    def forward(self):
        self._res = tensor.Tensor(self._x.matrix, self._x.calc_grad)
        return self._res

    def backward(self, np_tensor):
        if self._x.calc_grad:
            if self._x.grad_matrix is None:
                if np_tensor is None:
                    self._x.grad_matrix = tensor.Tensor(np.ones_like(self._x.matrix))
                else:
                    self._x.grad_matrix = tensor.Tensor(grad_reshape(np_tensor, self._x.matrix))
            else:
                if np_tensor is None:
                    self._x.grad_matrix = tensor.Tensor(grad_reshape(np.ones_like(self._x.matrix) + self._x.matrix, self._x.matrix))
                else:
                    self._x.grad_matrix = tensor.Tensor(grad_reshape(self._x.grad_matrix.matrix + np_tensor, self._x.matrix))



class TransposeOperation(Operation):

    def __init__(self, x):
        super().__init__()
        self._x = x

    def forward(self):
        self._res = tensor.Tensor(self._x.matrix.T, self._x.calc_grad)
        return self._res

    def backward(self, np_tensor):
        if self._x.calc_grad:
            if np_tensor is None:
                self._x.backward(np.ones_like(self._x.matrix))
            else:
                self._x.backward(np_tensor.T)





class SumOperation(Operation):

    def __init__(self, x):
        super().__init__()
        self._x = x

    def forward(self):
        self._res = tensor.Tensor((np.sum(self._x.matrix),), self._x.calc_grad)
        return self._res

    def backward(self, np_tensor):
        if self._x.calc_grad:
            tensor = np.ones_like(self._x.matrix)
            if np_tensor is None:
                self._x.backward(np_tensor)
            else:
                # ToDo ???
                self._x.backward(grad_reshape(np_tensor, self._x.matrix))
                #self._x.backward(grad_reshape(np_tensor, self._x.matrix))




class SoftMaxOperation(Operation):
    # ToDo !!!!!!!!!1

    def __init__(self, x):
        super().__init__()
        self._x = x

    def forward(self):
        exp = self._x.exp()
        sum = exp.sum()
        self._res = exp / sum
        return tensor.Tensor(self._res.matrix, self._res.calc_grad)

    def backward(self, np_tensor):
        if self._x.calc_grad:
            self._res.backward(np_tensor)
            #tensor = np.ones_like(self._x.matrix)
            #if np_tensor is None:
            #    self._x.backward(tensor)
            #else:
            #    self._x.backward(np_tensor @ tensor)



class HardMaxOperation(Operation):
    # ToDo !!!!!!!!!1

    def __init__(self, x):
        super().__init__()
        self._x = x

    def forward(self):
        sum = self._x.sum()
        self._res = self._x / sum
        return self._x / sum

    def backward(self, np_tensor):
        if self._x.calc_grad:
            self._res.backward(np_tensor)

            #tensor = np.ones_like(self._x.matrix)
            #if np_tensor is None:
            #    self._x.backward(tensor)
            #else:
            #    self._x.backward(np_tensor @ tensor)


class SqrOperation(Operation):

    def __init__(self, x):
        super().__init__()
        self._x = x

    def forward(self):
        self._res = tensor.Tensor(self._x.matrix * self._x.matrix, self._x.calc_grad)
        return self._res

    def backward(self, np_tensor):
        if self._x.calc_grad:
            data = 2 * self._x.matrix
            if np_tensor is None:
                self._x.backward(data)
            else:
                self._x.backward(np_tensor * data)





class SqrtOperation(Operation):

    def __init__(self, x):
        super().__init__()
        self._x = x

    def forward(self):
        self._res = tensor.Tensor(np.sqrt(self._x.matrix), self._x.calc_grad)
        return self._res

    def backward(self, np_tensor):
        if self._x.calc_grad:
            data = 0.5 / np.sqrt(self._x.matrix)
            if np_tensor is None:
                self._x.backward(data)
            else:
                self._x.backward(np_tensor * data)



class ExpOperation(Operation):

    def __init__(self, x):
        super().__init__()
        self._x = x

    def forward(self):
        self._res = tensor.Tensor(np.exp(self._x.matrix), self._x.calc_grad)
        return self._res

    def backward(self, np_tensor):
        if self._x.calc_grad:
            data = np.exp(self._x.matrix)
            if np_tensor is None:
                self._x.backward(data)
            else:
                self._x.backward(np_tensor * data)



class SigmoidOperation(Operation):

    def __init__(self, x):
        super().__init__()
        self._x = x

    def forward(self):
        ex = np.exp(self._x.matrix)
        self._res = tensor.Tensor(ex / (ex + 1), self._x.calc_grad)
        return self._res

    def backward(self, np_tensor):
        if self._x.calc_grad:
            data = self._res.matrix * (1 - self._res.matrix)
            if np_tensor is None:
                self._x.backward(data)
            else:
                self._x.backward(np_tensor * data)



class MinOperation(Operation):
    def __init__(self, x, y):
        super().__init__()
        self._x = x
        self._y = y

    def forward(self):
        self._res = tensor.Tensor(np.minimum(self._x.matrix, self._y.matrix), self._x.calc_grad or self._y.calc_grad)
        return self._res

    def backward(self, np_tensor):
        if self._x.calc_grad:
            if np_tensor is None:
                one = np.ones_like(self._res.matrix)
                res = np.zeros_like(self._res.matrix)
                idx = self._x.matrix <= self._y.matrix
                res[idx] = one[idx]
                self._x.backward(grad_reshape(res, self._x.matrix))
            else:
                res = np.zeros_like(np_tensor)
                idx = self._x.matrix <= self._y.matrix
                res[idx] = np_tensor[idx]
                self._x.backward(grad_reshape(res, self._x.matrix))
        if self._y.calc_grad:
            if np_tensor is None:
                one = np.ones_like(self._res.matrix)
                res = np.zeros_like(self._res.matrix)
                idx = self._x.matrix > self._y.matrix
                res[idx] = one[idx]
                self._y.backward(grad_reshape(res, self._y.matrix))
            else:
                res = np.zeros_like(np_tensor)
                idx = self._x.matrix > self._y.matrix
                res[idx] = np_tensor[idx]
                self._y.backward(grad_reshape(res, self._y.matrix))


class MaxOperation(Operation):
    def __init__(self, x, y):
        super().__init__()
        self._x = x
        self._y = y

    def forward(self):
        self._res = tensor.Tensor(np.maximum(self._x.matrix, self._y.matrix), self._x.calc_grad or self._y.calc_grad)
        return self._res

    def backward(self, np_tensor):
        if self._x.calc_grad:
            if np_tensor is None:
                one = np.ones_like(self._res.matrix)
                res = np.zeros_like(self._res.matrix)
                idx = self._x.matrix >= self._y.matrix
                res[idx] = one[idx]
                self._x.backward(grad_reshape(res, self._x.matrix))
            else:
                res = np.zeros_like(np_tensor)
                idx = self._x.matrix >= self._y.matrix
                res[idx] = np_tensor[idx]
                self._x.backward(grad_reshape(res, self._x.matrix))
        if self._y.calc_grad:
            if np_tensor is None:
                one = np.ones_like(self._res.matrix)
                res = np.zeros_like(self._res.matrix)
                idx = self._x.matrix < self._y.matrix
                res[idx] = one[idx]
                self._y.backward(grad_reshape(res, self._y.matrix))
            else:
                res = np.zeros_like(np_tensor)
                idx = self._x.matrix < self._y.matrix
                res[idx] = np_tensor[idx]
                self._y.backward(grad_reshape(res, self._y.matrix))


class AddOperation(Operation):
    def __init__(self, x, y):
        super().__init__()
        self._x = x
        self._y = y

    def forward(self):
        self._res = tensor.Tensor(self._x.matrix + self._y.matrix, self._x.calc_grad or self._y.calc_grad)
        return self._res

    def backward(self, np_tensor):
        if self._x.calc_grad:
            if np_tensor is None:
                self._x.backward(np.ones_like(self._res.matrix))
            else:
                self._x.backward(grad_reshape(np_tensor, self._x.matrix))
        if self._y.calc_grad:
            if np_tensor is None:
                self._y.backward(np.ones_like(self._res.matrix))
            else:
                self._y.backward(grad_reshape(np_tensor, self._y.matrix))


class SubOperation(Operation):
    def __init__(self, x, y):
        super().__init__()
        self._x = x
        self._y = y

    def forward(self):
        self._res = tensor.Tensor(self._x.matrix - self._y.matrix, self._x.calc_grad or self._y.calc_grad)
        return self._res


    def backward(self, np_tensor):
        if self._x.calc_grad:
            if np_tensor is None:
                self._x.backward(np.ones_like(self._res.matrix))
            else:
                self._x.backward(grad_reshape(np_tensor, self._x.matrix))
        if self._y.calc_grad:
            if np_tensor is None:
                self._y.backward(- np.ones_like(self._res.matrix))
            else:
                self._y.backward(grad_reshape(- np_tensor, self._y.matrix))


class MulOperation(Operation):
    def __init__(self, x, y):
        super().__init__()
        self._x = x
        self._y = y

    def forward(self):
        self._res = tensor.Tensor(self._x.matrix * self._y.matrix, self._x.calc_grad or self._y.calc_grad)
        return self._res


    def backward(self, np_tensor):
        if self._x.calc_grad:
            if np_tensor is None:
                self._x.backward(grad_reshape(self._y.matrix, self._x.matrix))
            else:
                self._x.backward(grad_reshape(np_tensor * self._y.matrix, self._x.matrix))
        if self._y.calc_grad:
            if np_tensor is None:
                self._y.backward(grad_reshape(self._x.matrix, self._y.matrix))
            else:
                self._y.backward(grad_reshape(np_tensor * self._x.matrix, self._y.matrix))


class DivOperation(Operation):
    def __init__(self, x, y):
        super().__init__()
        self._x = x
        self._y = y

    def forward(self):
        self._res = tensor.Tensor(self._x.matrix / self._y.matrix, self._x.calc_grad or self._y.calc_grad)
        return self._res


    def backward(self, np_tensor):
        if self._x.calc_grad:
            if np_tensor is None:
                self._x.backward(grad_reshape(1 / self._y.matrix, self._x.matrix))
            else:
                self._x.backward(grad_reshape(np_tensor / self._y.matrix, self._x.matrix))
        if self._y.calc_grad:
            if np_tensor is None:
                self._y.backward(grad_reshape(- self._x.matrix / (self._y.matrix * self._y.matrix), self._y.matrix))
            else:
                self._y.backward(grad_reshape(np_tensor * (-self._x.matrix / (self._y.matrix * self._y.matrix)), self._y.matrix))


class MatMulOperation(Operation):

    def __init__(self, x, y):
        super().__init__()
        self._x = x
        self._y = y

    def forward(self):
        self._res = tensor.Tensor(self._x.matrix @ self._y.matrix, self._x.calc_grad or self._y.calc_grad)
        return self._res

    def backward(self, np_tensor):
        if self._x.calc_grad:
            if np_tensor is None:
                self._x.backward(grad_reshape(grad_transpose(self._y.matrix), self._x.matrix))
            else:
                self._x.backward(grad_reshape(np_tensor @ grad_transpose(self._y.matrix), self._x.matrix))
        if self._y.calc_grad:
            if np_tensor is None:
                self._y.backward(grad_reshape(grad_transpose(self._x.matrix), self._y.matrix))
            else:
                self._y.backward(grad_reshape(grad_transpose(self._x.matrix) @ np_tensor, self._y.matrix))


class IndexOperation(Operation):
    def __init__(self, x, index):
        super().__init__()
        self._x = x
        self._index = index

    def forward(self):
        zero = np.zeros_like(self._x.matrix)
        data = self._x.matrix[self._index]
        zero[self._index] = data
        self._res = tensor.Tensor(zero)
        return tensor.Tensor(data, self._x.calc_grad)

    def backward(self, np_tensor):
        if self._x.calc_grad:
            # ToDo check
            if np_tensor is None:
                ex_tensor = np.zeros_like(self._x.matrix)
                ex_tensor[self._index] = np.ones_like(self._res.matrix)[self._index]
                self._x.backward(ex_tensor)
            else:
                ex_tensor = np.zeros_like(self._x.matrix)
                #!!!
                #ex_tensor[self._index] = np_tensor.squeeze()
                # ToDo ???
                ex_tensor[self._index] = np_tensor #.squeeze()
                self._x.backward(ex_tensor)


