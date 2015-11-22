#ifndef _SUWT_USRP_
#define _SUWT_USRP_

#include <uhd/usrp/multi_usrp.hpp>
#include <vector>
#include <complex>
#include <suwt/usrp/usrp_config.h>
#include <suwt/usrp/types.h>
#include <suwt/common/circular_buffer.h>
#include <boost/python.hpp>

namespace suwt {


class usrp {
public:
	void setBufferSize(size_t n);
	void make(std::string address);
	bool configure(usrp_config &c);
	void receive(size_t numSamples);
	boost::python::object getSamples(size_t n);

private:
	circular_buffer buffer {4096};
	uhd::usrp::multi_usrp::sptr uhd_usrp;
	usrp_config config;
};

}

#endif /* _SUWT_USRP_ */