#ifndef VPNAPPLET_H
#define VPNAPPLET_H

#include <QWidget>
#include <QLabel>
#include "vpnappletitem.h"
#include "dbus/dbusnetwork.h"

#include <libdui/dboxwidget.h>
#include <libdui/dswitchbutton.h>
#include <libdui/dheaderline.h>
#include <libdui/dseparatorhorizontal.h>
#include <libdui/dlistwidget.h>

DUI_USE_NAMESPACE

class VpnApplet : public DVBoxWidget
{
    Q_OBJECT
public:
    explicit VpnApplet(DBusNetwork *dbusNetwork, QWidget *parent = 0);
    ~VpnApplet();

signals:
    void appletSizeChanged();

private:
    void initStyleSheet();
    void initTitleLine();
    void initVpnListContent();
    void addItemToList(const VpnAppletItem::VpnData &vpnData);
    void removeItemFromList(const QString &uuid);
    void onConnectionsChanged();
    void onVpnEnableChanged();

private:
    QString m_uuid;
    QStringList m_uuidList;
    DBusNetwork *m_dbusNetwork;
    QLabel *m_titleLabel;
    DListWidget *m_listWidget;
    DSwitchButton *m_vpnSwitcher;
};

#endif // VPNAPPLET_H