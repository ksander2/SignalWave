TEMPLATE = subdirs

SUBDIRS += \
    SignalWave \
    Processing \
    SignalTest \
    SignalWaveQuick

SignalWave.depends = Processing
SignalTest.depends = Processing
