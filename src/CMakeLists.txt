set(TARGET suwt)

set(BOOST_REQUIRED_COMPONENTS
    program_options
    system
    thread
    python3
)

find_package(PythonLibs 3.0 REQUIRED)
find_package(Boost "1.35" REQUIRED ${BOOST_REQUIRED_COMPONENTS})
find_package(UHD "3.7.1" REQUIRED)
find_package(NumPy "1.10.0" REQUIRED)

file(GLOB_RECURSE SUWT_SRCS
    "*.cpp"
)

include_directories(
	.
    ${Boost_INCLUDE_DIRS}
    ${UHD_INCLUDE_DIRS}
    ${PYTHON_INCLUDE_DIRS}
    ${NUMPY_INCLUDE_DIRS}
)

add_library(${TARGET} SHARED ${SUWT_SRCS})
target_link_libraries(${TARGET} ${UHD_LIBRARIES} ${Boost_LIBRARIES} ${PYTHON_LIBRARIES} ${NUMPY_LIBRARIES})