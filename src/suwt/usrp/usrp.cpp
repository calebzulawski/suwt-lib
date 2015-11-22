#include <uhd/usrp/multi_usrp.hpp>
#include <string>
#include <complex>
#include <suwt/usrp/usrp_config.h>
#include <suwt/usrp/usrp.h>
#include <suwt/common/circular_buffer.h>
#include <suwt/python/numpy.h>
#include <boost/python.hpp>

namespace suwt {

void usrp::setBufferSize(size_t n) {
    buffer.resize(n);
}

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
    return true;
}

void usrp::receive(size_t numSamples) {
    //create a receive streamer
    uhd::stream_args_t stream_args("float","sc16");
    uhd::rx_streamer::sptr rx_stream = uhd_usrp->get_rx_stream(stream_args);

    uhd::rx_metadata_t md;

    //setup streaming
    uhd::stream_cmd_t stream_cmd(uhd::stream_cmd_t::STREAM_MODE_NUM_SAMPS_AND_DONE);
    stream_cmd.num_samps = numSamples;
    stream_cmd.stream_now = true;
    stream_cmd.time_spec = uhd::time_spec_t();
    rx_stream->issue_stream_cmd(stream_cmd);

    size_t total_rx_samples = 0;
    while (total_rx_samples < numSamples) {
        size_t num_rx_samples = rx_stream->recv(buffer.end(), buffer.contiguous(), md, 3.0);
        total_rx_samples += num_rx_samples;
    }
}

boost::python::object usrp::getSamples(size_t n) {
    return vectorToNumpyArray(buffer.read(n));
}

} /* namespace suwt */