#ifndef PLOTDATA_H
#define PLOTDATA_H

#pragma execution_character_set("utf-8")

#include<fstream>

#include <qstring.h>
#include <QtCore\qdebug.h>
#include <QtCore\qvector.h>
#include <QtWidgets\QWidget>
#include <QtWidgets\qpushbutton.h>

#include"qcustomplot.h"

// ���������Ƶ��ʾ����һ���ã�������Ƶ֡��Ӧ�����ݵ���ʾ               //��Ҫ���ڹۿ��طŻط���Ƶ����������
// ��ȡһ�������ļ���
// ������������ͼ����ʽ��ʾ��������ɫ��
// �ṩ��ɫ�����ߣ���ʾʵʱ����
class plotData : public QWidget
{
	Q_OBJECT
 public:
	 plotData(QWidget *parent = 0, QTimer *timer=0);
	~plotData();
	
	bool openfile(QString filename);
	
	void timeouttodo();
	void goto_x(double positon_x);

 public slots:
	void openfile();

 private:
	int length;  //���ݳ���
	int i;       //��ǰ����λ��

	std::ifstream datafile; //�ļ�����.txt��

	QVector<double> x;      //x����

	QVector<double> qspeed;
	QVector<double> qwp;
	
	QCustomPlot* ui_qcustomplot;
	QTimer *_t;
	QPen pen;
	QPushButton *button;
};

#endif // PLOTDATA_H
