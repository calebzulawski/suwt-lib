set(TARGET libsuwtlib.so)

set(BOOST_REQUIRED_COMPONENTS
    program_options
    system
    thread
)

find_package(Boost "1.35" REQUIRED ${BOOST_REQUIRED_COMPONENTS})
find_package(UHD "3.7.1" REQUIRED)

file(GLOB_RECURSE SUWT_SRCS
    "*.h"
    "*.cpp"
)

include_directories(
    ${Boost_INCLUDE_DIRS}
    ${UHD_INCLUDE_DIRS}
)

add_library(${TARGET} SHARED ${SUWT_SRCS})
target_link_libraries(${TARGET} ${UHD_LIBRARIES} ${Boost_LIBRARIES})