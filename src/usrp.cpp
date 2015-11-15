#include <uhd/usrp/multi_usrp.hpp>
#include <string>
#include "usrp_config.h"
#include "usrp.h"

namespace suwt {

void usrp::make(std::string address) {
	uhd_usrp = uhd::usrp::multi_usrp::multi_usrp::make(address);
}

bool usrp::configure(usrp_config &c) {
	config = c;
	uhd_usrp->set_clock_source(c.reference);
	uhd_usrp->set_rx_rate(c.sample_rate);
	uhd::tune_request_t tune_request(c.center_freq);
	uhd_usrp->set_rx_freq(tune_request);
	uhd_usrp->set_rx_gain(c.gain);
	uhd_usrp->set_rx_bandwidth(c.frontend_bandwidth);
	uhd_usrp->set_rx_antenna(c.antenna);
}

}