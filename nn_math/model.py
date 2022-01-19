from tensor import Tensor
import numpy as np

class Model:
    def __init__(self):
        self._parameters = []

    def __call__(self, *args, **kwargs):
        return self.forward(args[0])

    def forward(self, x):
        return x

    @property
    def parameters(self):
        return self._parameters

    def zero_grad(self):
        for i in self._parameters:
            if i.grad is not None:
                i.grad.matrix.fill(0)




class Linear(Model):

    def __init__(self, in_features, out_features, bias=True):
        super().__init__()
        self._in_features = in_features
        self._out_features = out_features
        self._bias = bias

        data = np.random.random((in_features, out_features))

        self._w = Tensor(data, True)
        self._parameters.append(self._w)

        if self._bias:
            self._b = Tensor([1.], True)
            self._parameters.append(self._b)



    def forward(self, x):
        if self._bias:
            return x @ self._w + self._b
        else:
            return x @ self._w






