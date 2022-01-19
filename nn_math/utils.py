import numpy as np
import itertools

def shape_greater(shape1, shape2):
    if len(shape1) == len(shape2):
        if shape1 > shape2:
            return True
        else:
            return False
    elif len(shape1) > len(shape2):
        return True
    else:
        return False


def shape_less(shape1, shape2):
    if len(shape1) == len(shape2):
        if shape1 < shape2:
            return True
        else:
            return False
    elif len(shape1) < len(shape2):
        return True
    else:
        return False

def grad_transpose(np_tensor):
    if np_tensor.ndim == 0:
        return np.array([[np_tensor]])
    elif np_tensor.ndim == 1:
        return np.expand_dims(np_tensor)
    elif np_tensor.ndim == 2:
        return np_tensor.T
    else:
        return np.swapaxes(np_tensor, -1, -2)


def grad_zip_variable(np_tensor, np_same_as):
    shape_in = np_tensor.shape
    shape_out = np_same_as.shape

    if shape_in == shape_out:
        return np_tensor
    else:
        res = []
        for i, (si, so) in enumerate(itertools.zip_longest(shape_in[::-1], shape_out[::-1])):
            if si != so:
                res.append(-i - 1)
        return np.sum(np_tensor, axis=tuple(res)).reshape(np_same_as.shape)


def grad_extend(np_tensor, np_same_as):
    return np.broadcast_arrays(np_tensor, np_same_as)[0]


def grad_reshape(np_tensor, np_same_as):
    shape1 = np_tensor.shape
    shape2 = np_same_as.shape
    if shape1 == shape2:
        return np_tensor
    elif shape_greater(shape1, shape2):
        return grad_zip_variable(np_tensor, np_same_as)
    else:
        return grad_extend(np_tensor, np_same_as)
