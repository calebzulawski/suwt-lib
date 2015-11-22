#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION

#include <suwt/python/numpy.h>
#include <Python.h>
#include <numpy/arrayobject.h>
#include <boost/python.hpp>

namespace suwt {

boost::python::object vectorToNumpyArray(const std::vector<float> &v) {
    npy_intp size = v.size();

    float *data = size ? const_cast<float*>(v.data()) : nullptr;
    PyObject * pyObj = PyArray_SimpleNewFromData(1, &size, NPY_CFLOAT, data);
    boost::python::handle<> handle ( pyObj );
    boost::python::numeric::array arr(static_cast<boost::python::numeric::array>(handle));

    return arr.copy();	
}
	
} // namespace suwt