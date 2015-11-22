#include <suwt/python/numpy.h>
#include <suwt/python/numpy_headers.h>
#include <boost/python.hpp>
#include <algorithm>

namespace suwt {

// import_array contains a non-void return, so we wrap it in a void*
void* init_numpy() {
	import_array();
}

boost::python::object vectorToNumpyArray(const std::vector<float> &v) {
    npy_intp size = v.size();

    float *data = size ? const_cast<float*>(v.data()) : nullptr;
    PyObject * pyObj = PyArray_SimpleNew(1, &size, NPY_FLOAT);
    if (size) std::copy(data, data+size, (float*)PyArray_DATA((PyArrayObject*)pyObj));
    boost::python::handle<> handle ( pyObj );
	boost::python::object o(handle);
    return o;
}
	
} // namespace suwt