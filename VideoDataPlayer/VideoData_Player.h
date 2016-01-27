#ifndef VIDEODATAPLAYER_H
#define VIDEODATAPLAYER_H

#include<string>

#include <QtWidgets/QWidget>
#include "MyVideoPlayer.h"
#include "DataPlot_Widget.h"


class VideoDataPlayer : public QWidget
{
	Q_OBJECT

public:
	VideoDataPlayer(QWidget *parent = 0);
	~VideoDataPlayer();

	void openfile(std::string path,std::string id);  //���ݺ���Ƶ���ڵ�·��������id�ҵ������ļ�����Ƶ�ļ�
	
private:
	void setupUI(int num_fish);
	
	void AddPlotDataWidget(DataPlot_Widget* plotdata)
	{
		dataCruves.push_back(plotdata);
	}
	std::vector<DataPlot_Widget*> dataCruves;  
	
	MyVideoPlayer*   ui_videoplayer;         // ��Ƶ���ſؼ�
	DataPlot_Widget* ui_plotdata_1;          // ������ʾ�ؼ�
	DataPlot_Widget* ui_plotdata_2;

	QLabel* ui_currentData;
	QLabel* ui_title;

	void set_title(QString monitorID, QString videoID, QString time_begin, QString time_end);

	int num_fish;
	
	QString _file_name;
};

#endif // VIDEODATAPLAYER_H
