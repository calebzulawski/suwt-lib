#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION

#include <vector>
#include <suwt/common/circular_buffer.h>

namespace suwt {

circular_buffer::circular_buffer(size_t n) :
	capacity (n),
	buf (std::vector<float>(n))
{};

// resizes but invalidates data
void circular_buffer::resize(size_t n) {
	capacity = n;
	start = 0;
	len = 0;
	buf.resize(n);
} 

void circular_buffer::push(size_t n) {
	len = std::min(capacity, len + n);
}

void circular_buffer::pop(size_t n, std::vector<float> &v) {
	n = std::min(n, len);
	size_t n_first = std::min(n, contiguous());
	v.insert(v.end(), buf.begin() + start, buf.begin() + n_first);
	start = (start + n_first) % capacity;
	len -= n_first;
	n -= n_first;
	if (n > 0) pop(n, v);
}

float* circular_buffer::begin() {
	return &buf[start];
}

float* circular_buffer::end() {
	return &buf[(start + len) % capacity];
}

size_t circular_buffer::contiguous() {
	return std::min(capacity - len, capacity - ((start + len) % capacity) - 1);
}

size_t circular_buffer::lenSamples() {
	return len/2;
}

std::vector<float> circular_buffer::read(size_t n) {
	std::vector<float> v = {1, 0, 2, 1, 3, 2};
	return v;
}


}
