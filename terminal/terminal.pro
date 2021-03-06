
HEADERS += \
    CORE.h \
    Employee.h \
    MenuEntry.h \
    Menu.h \
    DialPage.h \
    MenuModel.h \
    MenuView.h \
    MenuSubpageOne.h \
    MenuSubpageTwo.h \
    MenuPage.h \
    LastPage.h \
    GUI.h \
    DBConnectPage.h

SOURCES += \
    CORE.cpp \
    main.cpp \
    Employee.cpp \
    MenuEntry.cpp \
    Menu.cpp \
    DialPage.cpp \
    MenuModel.cpp \
    MenuView.cpp \
    MenuSubpageOne.cpp \
    MenuSubpageTwo.cpp \
    MenuPage.cpp \
    LastPage.cpp \
    GUI.cpp \
    DBConnectPage.cpp

QT += sql

FORMS += \
    DialPage.ui \
    MenuSubpageOne.ui \
    MenuSubpageTwo.ui \
    MenuPage.ui \
    LastPage.ui \
    GUI.ui \
    DBConnectPage.ui
