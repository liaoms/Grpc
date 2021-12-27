QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# creator pdb debug file
QMAKE_LFLAGS_RELEASE += /MAP
QMAKE_CFLAGS_RELEASE += /Zi
QMAKE_LFLAGS_RELEASE += /debug /opt:ref

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        proto/Algorithm_FileProcess.grpc.pb.cc \
        proto/Algorithm_FileProcess.pb.cc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DEFINES += _WIN32_WINNT = 0x0600

INCLUDEPATH += \
$$PWD/grpc/include \
$$PWD/proto

LIBS += $$PWD/grpc\lib\release\*.lib

#LIBS += \
#-L$$PWD/grpc\lib\release -llibprotobuf \
#-lgrpc++_reflection \
#-llibcrypto64MD \
#-llibssl64MD    \
#-lgrpc      \
#-lgrpc++    \
#-lgpr       \
#-lzlibstatic      \
#-lcares     \
#-lre2       \
#-labsl_statusor \
##-labsl_hash \
##-labsl_bad_variant_access   \
##-labsl_city \
##-labsl_raw_hash_set \
##-labsl_hashtablez_sampler   \
##-labsl_exponential_biased   \
##-lgpr   \
#-labsl_status   \
#-labsl_cord \
#-labsl_bad_optional_access  \
#-labsl_synchronization  \
#-labsl_stacktrace   \
#-labsl_symbolize    \
##-labsl_debugging_internal   \
##-labsl_demangle_internal    \
#-labsl_graphcycles_internal \
#-labsl_time \
##-labsl_civil_time   \
#-labsl_time_zone    \
#-labsl_malloc_internal  \
#-labsl_str_format_internal  \
#-labsl_strings  \
#-labsl_strings_internal \
#-labsl_int128   \
#-labsl_throw_delegate   \
#-labsl_base \
#-labsl_raw_logging_internal \
##-labsl_log_severity \
#-labsl_spinlock_wait    \
#-laddress_sorting   \
#-lupb



LIBS += \
-lWs2_32 \
