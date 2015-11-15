#ifndef _SUWT_USRP_
#define _SUWT_USRP_

#include <uhd/usrp/multi_usrp.hpp>
#include "usrp_config.h"
#include "types.h"

namespace suwt {

class usrp {
	void make(std::string address);
	bool configure(usrp_config &c);
private:
	uhd::usrp::multi_usrp::sptr uhd_usrp;
	usrp_config config;
};

}

#endif /* _SUWT_USRP_ */