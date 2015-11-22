#ifndef _SUWT_NUMPY_
#define _SUWT_NUMPY_

#include <boost/python.hpp>

namespace suwt {

boost::python::object vectorToNumpyArray(const std::vector<float> &v);
	
} // namespace suwt

#endif /* _SUWT_NUMPY_ */