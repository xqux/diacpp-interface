# diacpp-interface
set(diacpp-interface_FOUND ON)

set(diacpp-interface_DIR ${CMAKE_CURRENT_LIST_DIR})

set(diacpp-interface_INCLUDE_DIR "${diacpp-interface_DIR}/include")
set(diacpp-interface_INCLUDE_DIRS ${diacpp-interface_INCLUDE_DIR})

# Create the static library
add_library(diacpp-interface STATIC IMPORTED)

# Set files to use when compiling
set_property(TARGET diacpp-interface
	PROPERTY
	INTERFACE_INCLUDE_DIRECTORIES ${diacpp-interface_INCLUDE_DIRS}
)
