project(qtnetsample)
cmake_minimum_required(VERSION 2.8.12)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)
include(FeatureSummary)

set(REQUIRED_QT_VERSION 5.0)
find_package(Qt5 ${REQUIRED_QT_VERSION} CONFIG REQUIRED Core Network)

add_executable(qtnetsample main.cpp ${holidays_wsdl_SRCS})
target_link_libraries(qtnetsample Qt5::Core Qt5::Network)
install(TARGETS qtnetsample RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}")
install(FILES launcher
    DESTINATION "${CMAKE_INSTALL_BINDIR}"
    PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                GROUP_EXECUTE GROUP_READ
                WORLD_EXECUTE WORLD_READ
)

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)
