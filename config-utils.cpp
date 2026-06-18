#include "config-utils.hpp"

#include <QPushButton>
#include <QString>
#include <QFormLayout>
#include <QGroupBox>
#include <QComboBox>
#include <QAbstractButton>
#include <QWidget>
#include <QIcon>
#include <QToolButton>
#include <QPainter>
#include <QPixmap>
#include <QFont>

#include "obs.h"
#include "obs-module.h"
#include "obs-frontend-api.h"
#include <util/dstr.h>

// Generate buttons for default/custom stuff
QPushButton *ConfigUtils::generateButton(QString buttonText)
{
	auto styles = QString::fromUtf8("QPushButton[unselected=\"true\"] { background: pink; }");

	auto button = new QPushButton(buttonText);
	button->setStyleSheet(styles);

	return button;
}

// Generate settings groupbox
QGroupBox *ConfigUtils::generateSettingsGroupBox(QString headingText)
{
	auto group = headingText == nullptr ? new QGroupBox : new QGroupBox(headingText);
	//	group->setProperty("altColor", QVariant(true));

	return group;
}

// Generate menu button
QToolButton *ConfigUtils::generateMenuButton(QString title, QIcon icon)
{
	auto button = new QToolButton;

	button->setText(title);
	button->setIcon(icon);
	button->setIconSize(QSize(32, 32));
	button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	button->setStyleSheet(serviceTileStyle());

	return button;
}

QString ConfigUtils::dialogStyle()
{
	return QString::fromUtf8(
		"QDialog { background-color: #16181F; color: #F3F5F8; }"
		"QLabel { color: #F3F5F8; }"
		"QScrollArea, QWidget { color: #F3F5F8; }"
		"QLineEdit, QComboBox, QSpinBox, QDoubleSpinBox, QPlainTextEdit, QTextEdit {"
		" background-color: #232938; border: 1px solid #31384B; border-radius: 8px; padding: 6px 10px; color: #F3F5F8; }"
		"QLineEdit:focus, QComboBox:focus, QSpinBox:focus, QDoubleSpinBox:focus, QPlainTextEdit:focus, QTextEdit:focus { border: 1px solid #E68A2E; }"
		"QPushButton { background-color: #2A3142; color: #F3F5F8; border: 1px solid #394156; border-radius: 8px; padding: 8px 14px; }"
		"QPushButton:hover { background-color: #31394D; }"
		"QTabBar::tab { background: #232938; color: #F3F5F8; border: 1px solid #394156; padding: 10px 14px; }"
		"QTabBar::tab:selected { background: #2E3649; border-bottom-color: #2E3649; }");
}

QString ConfigUtils::panelStyle(const QString &accentColor)
{
	const auto borderColor = accentColor.isEmpty() ? QString::fromUtf8("#31384B") : accentColor;
	return QString::fromUtf8("background-color: #1D212B; border: 1px solid %1; border-radius: 14px;")
		.arg(borderColor);
}

QString ConfigUtils::primaryButtonStyle()
{
	return QString::fromUtf8(
		"QPushButton { background-color: #E68A2E; color: #151821; border: 1px solid #E68A2E; border-radius: 8px; padding: 8px 14px; font-weight: bold; }"
		"QPushButton:hover { background-color: #F09A3F; border-color: #F09A3F; }");
}

QString ConfigUtils::secondaryButtonStyle()
{
	return QString::fromUtf8(
		"QPushButton { background-color: #2A3142; color: #F3F5F8; border: 1px solid #394156; border-radius: 8px; padding: 8px 14px; font-weight: bold; }"
		"QPushButton:hover { background-color: #31394D; border-color: #4A546D; }");
}

QString ConfigUtils::dangerButtonStyle()
{
	return QString::fromUtf8(
		"QPushButton { background-color: #2A2428; color: #FFD7D7; border: 1px solid #6A4147; border-radius: 8px; padding: 8px 14px; font-weight: bold; }"
		"QPushButton:hover { background-color: #382A30; border-color: #8D505A; }");
}

QString ConfigUtils::sidebarStyle()
{
	return QString::fromUtf8(
		"QListWidget { background-color: #1D212B; border: 1px solid #31384B; border-radius: 14px; padding: 10px 8px; outline: none; }"
		"QListWidget::item { background-color: transparent; border-radius: 10px; padding: 10px 12px; margin: 2px 0px; }"
		"QListWidget::item:selected { background-color: #2C3650; border-left: 3px solid #E68A2E; padding-left: 9px; }"
		"QListWidget::item:hover:!selected { background-color: #252B39; }");
}

QString ConfigUtils::serviceTileStyle()
{
	return QString::fromUtf8(
		"QToolButton { min-width: 126px; max-width: 126px; min-height: 92px; max-height: 92px; "
		"background-color: #232938; border: 1px solid #31384B; border-radius: 14px; padding: 10px 8px 8px 8px; font-weight: bold; }"
		"QToolButton:hover { background-color: #2A3142; border-color: #E68A2E; }");
}

// Generate QIcon from emoji
QIcon ConfigUtils::generateEmojiQIcon(QString emoji)
{
	QPixmap pixmap(32, 32);
	pixmap.fill(Qt::transparent);

	QPainter painter(&pixmap);
	QFont font = painter.font();
	font.setPixelSize(32);
	painter.setFont(font);
	painter.drawText(pixmap.rect(), Qt::AlignCenter, emoji);

	return QIcon(pixmap);
}

// For setting the active property stuff on buttons
void ConfigUtils::updateButtonStyles(QPushButton *defaultButton, QPushButton *customButton, int activeIndex)
{
	defaultButton->setProperty("unselected", activeIndex != 0 ? true : false);
	customButton->setProperty("unselected", activeIndex != 1 ? true : false);
}

// Platform icons deciphered from endpoints
QIcon ConfigUtils::getPlatformIconFromEndpoint(QString endpoint)
{

	if (endpoint.contains(QString::fromUtf8("ingest.global-contribute.live-video.net")) ||
	    endpoint.contains(QString::fromUtf8(".contribute.live-video.net")) ||
	    endpoint.contains(QString::fromUtf8(".twitch.tv"))) { // twitch
		return QIcon(":/multicast/media/twitch.png");
	} else if (endpoint.contains(QString::fromUtf8(".youtube.com"))) { // youtube
		return QIcon(":/multicast/media/youtube.png");
	} else if (endpoint.contains(QString::fromUtf8("fa723fc1b171.global-contribute.live-video.net"))) { // kick
		return QIcon(":/multicast/media/kick.png");
	} else if (endpoint.contains(QString::fromUtf8(".tiktokcdn"))) { // tiktok
		return QIcon(":/multicast/media/tiktok.png");
	} else if (endpoint.contains(QString::fromUtf8(".pscp.tv"))) { // twitter
		return QIcon(":/multicast/media/twitter.png");
	} else if (endpoint.contains(QString::fromUtf8("livepush.trovo.live"))) { // trovo
		return QIcon(":/multicast/media/trovo.png");
	} else if (endpoint.contains(QString::fromUtf8(".facebook.com")) ||
		   endpoint.contains(QString::fromUtf8(".fbcdn.net"))) { // facebook
		return QIcon(":/multicast/media/facebook.png");
	} else { // unknown
		return QIcon(":/multicast/media/unknown.png");
	}
}

QString ConfigUtils::getPlatformAccentColor(QString endpoint)
{
	if (endpoint.contains(QString::fromUtf8("ingest.global-contribute.live-video.net")) ||
	    endpoint.contains(QString::fromUtf8(".contribute.live-video.net")) ||
	    endpoint.contains(QString::fromUtf8(".twitch.tv"))) {
		return QString::fromUtf8("#9147FF");
	} else if (endpoint.contains(QString::fromUtf8(".youtube.com"))) {
		return QString::fromUtf8("#FF3B30");
	} else if (endpoint.contains(QString::fromUtf8("fa723fc1b171.global-contribute.live-video.net"))) {
		return QString::fromUtf8("#53FC18");
	} else if (endpoint.contains(QString::fromUtf8(".tiktokcdn"))) {
		return QString::fromUtf8("#25F4EE");
	} else if (endpoint.contains(QString::fromUtf8(".pscp.tv"))) {
		return QString::fromUtf8("#7AA2FF");
	} else if (endpoint.contains(QString::fromUtf8("livepush.trovo.live"))) {
		return QString::fromUtf8("#3FD26A");
	} else if (endpoint.contains(QString::fromUtf8(".facebook.com")) ||
		   endpoint.contains(QString::fromUtf8(".fbcdn.net"))) {
		return QString::fromUtf8("#1877F2");
	}

	return QString::fromUtf8("#E68A2E");
}
