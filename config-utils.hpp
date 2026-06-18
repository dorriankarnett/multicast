#pragma once

#include <QPushButton>
#include <QComboBox>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QGroupBox>
#include <QIcon>
#include <QString>
#include <QToolButton>
#include "obs.h"

class ConfigUtils {
public:
	// UI generation
	static QPushButton *generateButton(QString buttonText);
	static QGroupBox *generateSettingsGroupBox(QString headingText);
	static QToolButton *generateMenuButton(QString title, QIcon icon);
	static QString dialogStyle();
	static QString panelStyle(const QString &accentColor = QString());
	static QString primaryButtonStyle();
	static QString secondaryButtonStyle();
	static QString dangerButtonStyle();
	static QString sidebarStyle();
	static QString serviceTileStyle();
	
	static QIcon generateEmojiQIcon(QString emoji);

	static void updateButtonStyles(QPushButton *defaultButton, QPushButton *customButton, int activeIndex);

	static QIcon getPlatformIconFromEndpoint(QString endpoint);
	static QString getPlatformAccentColor(QString endpoint);
};
