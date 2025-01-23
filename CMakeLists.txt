cmake_minimum_required(VERSION 3.16)

project(PhoneBook VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)   # uic(User Interface Compiler, uic reads and XML format user interface definition(.ui)files.)

set(CMAKE_AUTOMOC ON)   # moc(Meta-Object compiler, is the program that handles Qt's C++ extensions)
                        # moc(The moc tool reads a C++ header file. If it finds one or more class declartions that contain the Q_OBJECT macro,
                        #    (it produces a C++ source file containing the meta-object code for thos classes)

set(CMAKE_AUTORCC ON)   # rcc(resource compiler, is used to embed resources into a Qt app during the build process)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)      #
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets) #
find_package(Qt6 REQUIRED COMPONENTS UiTools)                   #
find_package(Qt6 REQUIRED COMPONENTS Core)                      #
find_package(Qt6 REQUIRED COMPONENTS Network)                   #네트웤


set(PROJECT_SOURCES
        main.cpp
        phonebook.h
        phonebook.cpp
        exception.cpp
        ui/welcome/phonebook.ui

)

find_package(Qt6 REQUIRED COMPONENTS Sql)
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(PhoneBook
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        header/db/db.h
        source/db/db.cpp

        ui/home/home.h ui/home/home.cpp ui/home/home.ui
        ui/window_of_anotherProfile/profileofanother.h ui/window_of_anotherProfile/profileofanother.cpp ui/window_of_anotherProfile/profileofanother.ui

        source/user/userAccount.cpp
        header/user/userAccount.h
        header/user/userPhoneNumInfo.h
        source/user/userPhoneNumInfo.cpp
        header/profile/profile.h
        source/profile/profile.cpp

        header/account/login.h
        header/account/findPassword.h
        header/account/signUp.h
        source/account/login.cpp
        source/account/findPassword.cpp
        source/account/signUp.cpp
        properties.h
        header/account/logout.h
        source/account/logout.cpp
        header/db/homeDb.h
        source/db/homeDb.cpp
        resource/chat_menu.txt


        ui/chat/chatbox.h ui/chat/chatbox.cpp ui/chat/chatbox.ui
        ui/chat/chatMessage.cpp
        ui/chat/chatMessage.h
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
target_link_libraries(PhoneBook PRIVATE Qt6::Network)

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
