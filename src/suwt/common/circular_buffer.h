#ifndef _SUWT_CIRCULAR_BUFFER_
#define _SUWT_CIRCULAR_BUFFER_

#include <vector>
#include <cstddef>
#include <boost/python.hpp>

namespace suwt {

class circular_buffer {
public:
	circular_buffer(size_t n);
	void   resize(size_t n);
	void   push(size_t n);
	void   pop(size_t n, std::vector<float> &v);
	float* begin();
	float* end();
	size_t contiguous();
	size_t lenSamples();
	std::vector<float> read(size_t n);
private:
	circular_buffer();
	size_t capacity;
	size_t start;
	size_t len;
	std::vector<float> buf;
};

} // namespace suwt

#endif /* _SUWT_CIRCULAR_BUFFER_ */