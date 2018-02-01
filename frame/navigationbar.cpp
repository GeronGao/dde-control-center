#include "navigationbar.h"

#include <QVBoxLayout>
#include <QDebug>
#include <QSignalMapper>

static const QStringList ModuleList = { "accounts",
                                        "display",
                                        "defapp",
                                        "personalization",
                                        "network",
                                        "bluetooth",
                                        "sound",
                                        "datetime",
                                        "power",
                                        "mouse",
                                        "keyboard",
                                        "wacom",
                                        "update",
                                        "systeminfo",
                                      };

NavigationBar::NavigationBar(QWidget *parent)
    : QWidget(parent)

{
    QVBoxLayout *buttonsLayout = new QVBoxLayout;
    buttonsLayout->setContentsMargins(0, 0, 0, 0);
    buttonsLayout->setSpacing(20);

    QVBoxLayout *centralLayout = new QVBoxLayout;
    centralLayout->addStretch();
    centralLayout->addLayout(buttonsLayout);
    centralLayout->addStretch();
    centralLayout->setContentsMargins(0, 0, 0, 0);
    centralLayout->setSpacing(20);

    setLayout(centralLayout);

    // init buttons
    for (const auto &module : ModuleList)
    {
        DImageButton *b = new DImageButton;
        b->setCheckedPic(QString(":/%1/themes/dark/icons/nav_%1.png").arg(module));
        b->setNormalPic(QString(":/%1/themes/dark/icons/nav_%1_normal.svg").arg(module));
        b->setCheckable(true);

        buttonsLayout->addWidget(b);
        m_navigationButtons.insert(module, b);

        connect(b, &DImageButton::clicked, this, &NavigationBar::onNavigationButtonClicked);
    }

    // init first button to checked
    m_navigationButtons[ModuleList.first()]->clicked();
}

void NavigationBar::setModuleVisible(const QString &module, bool visible)
{
    if (m_navigationButtons.contains(module))
        m_navigationButtons[module]->setVisible(visible);
}

void NavigationBar::setModuleChecked(const QString &module)
{
    DImageButton* b = m_navigationButtons[module];

    Q_ASSERT(b);

    setModuleChecked(b);
}

void NavigationBar::onNavigationButtonClicked()
{
    DImageButton *b = static_cast<DImageButton *>(sender());
    Q_ASSERT(b);

    setModuleChecked(b);

    emit requestModule(m_navigationButtons.key(b));
}

void NavigationBar::setModuleChecked(DImageButton *button)
{
    if (m_checkedButton == button)
        return button->setChecked(true);

    if (!m_checkedButton.isNull())
        m_checkedButton->setChecked(false);

    m_checkedButton = button;
    m_checkedButton->setChecked(true);
}