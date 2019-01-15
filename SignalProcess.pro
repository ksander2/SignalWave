TEMPLATE = subdirs

SUBDIRS += \
    SignalWave \
    Processing

SignalWave.depends = Processing
