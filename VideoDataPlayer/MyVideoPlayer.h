#pragma once

#include "D:\Qt\Qt5.5.1\5.5\msvc2013\include\QtWidgets\qwidget.h"

#include <QtGui/QMovie>

#include<QtMultimediaWidgets\qvideowidget.h>
#include<QtMultimedia\qmediaplayer.h>

class QSlider;
class QAbstractButton;
class QLabel;
class QComboBox;


// ��Ƶ��������

class MyVideoPlayer : public QWidget
{
	Q_OBJECT

public:
	MyVideoPlayer(QWidget *parent);
	~MyVideoPlayer();

public:
	//bool Open_File(const QString &filename);
	bool Open_File();

public slots:

	void mediaStateChanged(QMediaPlayer::State state);
	void mediapositionChanged(qint64 position);  // ��Ƶ�ı�  -���������ı�
	void setPosition(int position);              // �������ı� -����Ƶ�ı�
	
	void durationChanged(qint64 duration);
	void updateRate();
	void play();
	
private:
	QMediaPlayer    _mediaPlayer;     // qt���ò�����
	QVideoWidget    *_videoWidget;    // ��ʾ��Ƶ�ؼ�

	QAbstractButton *_playButton;     // ���Ű�ť
	QSlider         *_positionSlider; // ������
	QComboBox       *_rateBox;        // ��������ѡ��

	QLabel *_currentTime_info;        // ��ǰ�Ѳ���ʱ�� label
	QLabel *_totalTime_info;          // ��Ƶ��ʱ�� label

	void update_currentTime(qint64 currentInfo);
	void update_totalTime(qint64 duration);
};

