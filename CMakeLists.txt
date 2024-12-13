cmake_minimum_required(VERSION 3.16)

project(PhoneBook VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS UiTools)
find_package(Qt6 REQUIRED COMPONENTS Core)

set(PROJECT_SOURCES
        main.cpp
        phonebook.cpp
        phonebook.h
        phonebook.ui

)

find_package(Qt6 REQUIRED COMPONENTS Sql)
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(PhoneBook
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        src_h/db_h/db.h
        src_c/db_s/db.cpp

        memo
        home.h home.cpp home.ui
        src_c/user_s/userAccount.cpp
        src_h/user_h/userAccount.h
        src_h/user_h/userPhoneNumInfo.h
        src_c/user_s/userPhoneNumInfo.cpp
        src_h/profile_h/profile.h
        src_c/profile_s/profile.cpp
        profileofanother.h profileofanother.cpp profileofanother.ui
    )
else()
    if(ANDROID)
        add_library(PhoneBook SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(PhoneBook
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(PhoneBook PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(PhoneBook PRIVATE Qt6::Sql)
target_link_libraries(PhoneBook PRIVATE Qt6::UiTools)
target_link_libraries(PhoneBook PRIVATE Qt6::Core)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.PhoneBook)
endif()
set_target_properties(PhoneBook PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS PhoneBook
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(PhoneBook)
endif()
