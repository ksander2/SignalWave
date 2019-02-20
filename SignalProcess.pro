TEMPLATE = subdirs

SUBDIRS += \
    SignalWave \
    Processing \
    SignalTest

SignalWave.depends = Processing
SignalTest.depends = Processing
