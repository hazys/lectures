import numpy as np
import scipy as sp
import operations
import utils

def extend_tenzor_by_ones(tensor):
    data = np.copy(tensor._data)
    if tensor._data.ndim > 1:
        ext = np.ones(data.shape[:-1])[..., np.newaxis]
        data = np.concatenate((data, ext), axis=-1)
        return Tensor(data, tensor._calc_grad)
    else:
        data = np.append(data, 1)
        return Tensor(data, tensor._calc_grad)


def ones(shape, calc_grad=False):
    res = np.ones(shape)
    return Tensor(res, calc_grad)

def zeros(shape, calc_grad=False):
    res = np.zeros(shape)
    return Tensor(res, calc_grad)





class Tensor:

    def __init__(self, data, calc_grad=False):
        self._data = np.array(data)

        self._old_shape = None
        if self._data.ndim == 0:
            self._old_shape = self._data.shape
            self._data = self._data[None, None]
        elif self._data.ndim == 1:
            self._old_shape = self._data.shape
            self._data = self._data[..., None]

        self._calc_grad = calc_grad
        self._operation = operations.VariableOperation(self)
        self._grad = None


    # getters
    @property
    def data(self):
        if self._old_shape is not None:
            return self._data.reshape(self._old_shape)
        else:
            return self._data


    @property
    def matrix(self):
        return self._data


    def update(self, matrix):
        self._data = matrix


    @property
    def calc_grad(self):
        return self._calc_grad


    @property
    def grad(self):
        if self._grad is not None:
            if self._old_shape is not None:
                return Tensor(self._grad._data.reshape(self._old_shape), calc_grad=self._calc_grad)
            else:
                return self._grad
        else:
            return None


    @property
    def grad_matrix(self):
        return self._grad


    @grad_matrix.setter
    def grad_matrix(self, grad):
        self._grad = grad


    @property
    def T(self):
        return self.t()

    def __repr__(self):
        return str(self.data)

    def forward(self):
        return self._operation.forward()

    def backward(self, tensor=None):
        if self.calc_grad:
            self._operation.backward(tensor)

    def __prepare_operation(self, operation, other_grad=False):
        data = operation.forward()
        #ten = Tensor(data, self.calc_grad or other_grad)
        data._operation = operation
        return data

    def t(self):
        op = operations.TransposeOperation(self)
        return self.__prepare_operation(op)


    def sum(self):
        op = operations.SumOperation(self)
        return self.__prepare_operation(op)

    def softmax(self):
        op = operations.SoftMaxOperation(self)
        return self.__prepare_operation(op)

    def hardmax(self):
        op = operations.HardMaxOperation(self)
        return self.__prepare_operation(op)

    def sqr(self):
        op = operations.SqrOperation(self)
        return self.__prepare_operation(op)

    def sqrt(self):
        op = operations.SqrtOperation(self)
        return self.__prepare_operation(op)

    def exp(self):
        op = operations.ExpOperation(self)
        return self.__prepare_operation(op)

    def sigmoid(self):
        op = operations.SigmoidOperation(self)
        return self.__prepare_operation(op)


    def __getitem__(self, item):
        op = operations.IndexOperation(self, item)
        return self.__prepare_operation(op)


    def min(self, other):
        op = operations.MinOperation(self, other)
        return self.__prepare_operation(op)


    def max(self, other):
        op = operations.MaxOperation(self, other)
        return self.__prepare_operation(op)


    def __add__(self, other):
        op = operations.AddOperation(self, other)
        return self.__prepare_operation(op)


    def __sub__(self, other):
        op = operations.SubOperation(self, other)
        return self.__prepare_operation(op)


    def __mul__(self, other):
        op = operations.MulOperation(self, other)
        return self.__prepare_operation(op)


    def __truediv__(self, other):
        op = operations.DivOperation(self, other)
        return self.__prepare_operation(op)


    def __matmul__(self, other):
        op = operations.MatMulOperation(self, other)
        return self.__prepare_operation(op)


