#include <boost/python.hpp>
#include <suwt/usrp/usrp_config.h>
#include <suwt/usrp/usrp.h>
#include <suwt/python/numpy.h>

using namespace boost::python;
using namespace suwt;



BOOST_PYTHON_MODULE(libsuwt)
{
	init_numpy();

	enum_<sample_t>("sample_type")
		.value("double", DOUBLE)
		.value("float",  FLOAT)
		.value("short",  SHORT)
	;

	enum_<wire_fmt_t>("wire_format")
		.value("sc8",  SC8)
		.value("sc16", SC16)
	;

	class_<usrp_config>("config")
		.def_readwrite("sample_type",        &usrp_config::sample_type)
		.def_readwrite("samples_per_buffer", &usrp_config::samples_per_buffer)
		.def_readwrite("sample_rate",        &usrp_config::sample_rate)
		.def_readwrite("center_freq",        &usrp_config::sample_rate)
		.def_readwrite("gain",               &usrp_config::gain)
		.def_readwrite("antenna",            &usrp_config::antenna)
		.def_readwrite("frontend_bandwidth", &usrp_config::frontend_bandwidth)
		.def_readwrite("reference",          &usrp_config::reference)
		.def_readwrite("wire_format",        &usrp_config::wire_format)
	;

	class_<usrp>("usrp")
		.def("setBufferSize", &usrp::setBufferSize)
		.def("make",          &usrp::make)
		.def("configure",     &usrp::configure)
		.def("receive",       &usrp::receive)
		.def("getSamples",    &usrp::getSamples)
	;
}