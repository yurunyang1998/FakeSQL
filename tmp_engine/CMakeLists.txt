
find_package(libbson-1.0)

message ("-- libbson found version \"${BSON_VERSION}\"")
message ("-- libbson include path \"${BSON_INCLUDE_DIRS}\"")
message ("-- libbson libraries \"${BSON_LIBRARIES}\"")
set(SRCLIST main.cc)

add_executable(storages_engine ${SRCLIST})

target_include_directories (storages_engine PRIVATE ${BSON_INCLUDE_DIRS})
target_link_libraries (storages_engine PRIVATE ${BSON_LIBRARIES})
target_compile_definitions (storages_engine PRIVATE ${BSON_DEFINITIONS})


