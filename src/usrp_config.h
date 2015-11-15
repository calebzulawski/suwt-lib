#ifndef _SUWT_USRP_CONFIG_
#define _SUWT_USRP_CONFIG_

#include <string>

#include "types.h"

namespace suwt {
	
struct usrp_config {
	usrp_config();

	sample_t    sample_type;
	size_t      samples_per_buffer;
	double      sample_rate;
	double      center_freq;
	double      gain;
	std::string antenna;
	double      frontend_bandwidth;
	std::string reference;
	wire_fmt_t  wire_format;

};

usrp_config::usrp_config() :
	sample_type        (SHORT),
	samples_per_buffer (10000),
	sample_rate        (1e6),
	center_freq        (0),
	gain               (0),
	antenna            (""),
	frontend_bandwidth (0),
	reference          ("internal"),
	wire_format        (SC16)
{}

} //namespace suwt

#endif /* _SUWT_USRP_CONFIG_ */