#pragma once

#include <QtWidgets\qwidget.h>

#include <QtGui/QMovie>

#include<QtMultimediaWidgets\qvideowidget.h>
#include<QtMultimedia\qmediaplayer.h>

class QSlider;
class QAbstractButton;
class QLabel;
class QComboBox;


// ��Ƶ��������, ������Ƶ�Ĳ���
// ӵ�� �ؼ�����������ʱ�䣬���Ű�ť
// �����ṩ �źŲ� ����һ�룬ת���ڼ���
class MyVideoPlayer : public QWidget
{
	Q_OBJECT

public:
	MyVideoPlayer(QWidget *parent=0);
	~MyVideoPlayer();

public slots:
	QString Open_File(const QString &filename);
	QString Open_File();
	
	void play();                         // �ı䲥��״̬����ͣ->���ţ�����->��ͣ��

signals:

	void next_position();                // �źţ���Ƶ����һʱ�̣��룩
	void goto_position_x(double x);      // �źţ�ת����Ƶ�ĵ�x��
	
//����Ϊ����ӿ�
	
private slots:

	void mediaStateChanged(QMediaPlayer::State state);
	void mediapositionChanged(qint64 position);        // ��Ƶ�ı�  -���������ı�
	void setPosition(int position);           // �������ı� -����Ƶ�ı�
	
	void durationChanged(qint64 duration);
	void updateRate();
	
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

