# KI18N Translation Domain for this library
add_definitions(-DTRANSLATION_DOMAIN=\"kcm_autostart\")

set(kcm_autostart_PART_SRCS
   autostartitem.cpp
   addscriptdialog.cpp
   advanceddialog.cpp
   autostartmodel.cpp
   autostart.cpp )

ki18n_wrap_ui(kcm_autostart_PART_SRCS autostartconfig.ui )

add_library(kcm_autostart MODULE ${kcm_autostart_PART_SRCS})

target_link_libraries(kcm_autostart KF5::KCMUtils KF5::I18n KF5::KIOCore KF5::KIOWidgets)

########### install files ###############

install(TARGETS kcm_autostart  DESTINATION ${KDE_INSTALL_PLUGINDIR} )
install( FILES autostart.desktop   DESTINATION  ${KDE_INSTALL_KSERVICES5DIR} )
