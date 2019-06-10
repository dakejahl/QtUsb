#ifndef QUSBDEVICE_P_H
#define QUSBDEVICE_P_H

#include "qusbdevice.h"
#include <private/qobject_p.h>
#include <QThread>

#ifdef Q_OS_UNIX
#include <libusb.h>
#else
#include <libusb/libusb.h>
#endif

QT_BEGIN_NAMESPACE

class QUsbEventsThread : public QThread
{
public:
    void run();

    libusb_context *m_ctx;
};

class QUsbTransferPrivate;

class QUsbDevicePrivate : public QObjectPrivate
{
    Q_DECLARE_PUBLIC(QUsbDevice)
    friend QUsbTransferPrivate;

public:
    QUsbDevicePrivate();
    ~QUsbDevicePrivate();

    void printUsbError(int error_code) const;

    libusb_device **m_devs;
    libusb_device_handle *m_devHandle;
    libusb_context *m_ctx;

    QUsbEventsThread *m_events;
};

QT_END_NAMESPACE

#endif
