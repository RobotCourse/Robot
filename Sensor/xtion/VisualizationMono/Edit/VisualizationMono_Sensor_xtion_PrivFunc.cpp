//You need to program this file.

#include "../NoEdit/VisualizationMono_Sensor_xtion_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMono_Sensor_xtion_Params * params=(VisualizationMono_Sensor_xtion_Params *)paramsPtr;
	VisualizationMono_Sensor_xtion_Vars * vars=(VisualizationMono_Sensor_xtion_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    vars->color->setText("Open");
    vars->depth->setText("Open");
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMono_Sensor_xtion_Params * params=(VisualizationMono_Sensor_xtion_Params *)paramsPtr;
	VisualizationMono_Sensor_xtion_Vars * vars=(VisualizationMono_Sensor_xtion_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->color->setText("Closed");
    vars->depth->setText("Closed");
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMono_Sensor_xtion_Params * params=(VisualizationMono_Sensor_xtion_Params *)paramsPtr;
	VisualizationMono_Sensor_xtion_Vars * vars=(VisualizationMono_Sensor_xtion_Vars *)varsPtr;
	internalTrigger=NULL;
	internalTriggerSignal=QString();
	/*======Occasionally Program above======*/
	/*
	Function: get internal trigger [defined in vars] for node.
	You need to program here when you need internal trigger (internalTrigger + internalTriggerSignal) for node.
	E.g.
	internalTrigger=&(vars->trigger);
	internalTriggerSignal=QString(SIGNAL(triggerSignal()));
	*/
}

void DECOFUNC(getMonoDrainDataSize)(void * paramsPtr, void * varsPtr, int & drainDataSize)
{
	VisualizationMono_Sensor_xtion_Params * params=(VisualizationMono_Sensor_xtion_Params *)paramsPtr;
	VisualizationMono_Sensor_xtion_Vars * vars=(VisualizationMono_Sensor_xtion_Vars *)varsPtr;
	drainDataSize=0;
	/*======Please Program above======*/
	/*
	Function: get drain data size to be grabbed from buffer.
	Rules:
	drainDataSize=0: grab and remove all data from buffer.
	drainDataSize>0: grab drainDataSize latest data from buffer.
	drainDataSize<0: grab and remove drainDataSize ancient data from buffer.
	*/
}

//Input Port #0: Buffer_Size = 1, Params_Type = SensorTimer_Sensor_xtion_Params, Data_Type = SensorTimer_Sensor_xtion_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	VisualizationMono_Sensor_xtion_Params * params=(VisualizationMono_Sensor_xtion_Params *)paramsPtr;
	VisualizationMono_Sensor_xtion_Vars * vars=(VisualizationMono_Sensor_xtion_Vars *)varsPtr;
	QVector<SensorTimer_Sensor_xtion_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<SensorTimer_Sensor_xtion_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
    cv::Mat cvColorImg = draindata.front()->cvColorImg;
    cv::Mat cvColorImg2Show = cvColorImg.clone();
    cv::cvtColor(cvColorImg2Show, cvColorImg2Show, CV_BGR2RGB);
    cv::flip(cvColorImg2Show, cvColorImg2Show, 1);
    QImage qColorImg((const uchar*)cvColorImg2Show.data, cvColorImg2Show.cols, cvColorImg2Show.rows,
                     cvColorImg2Show.step, QImage::Format_RGB888);
    vars->color->setPixmap(QPixmap::fromImage(qColorImg));

    cv::Mat cvDepthImg = draindata.front()->cvDepthImg;
    cv::Mat cvDepthImg2Show = cvDepthImg.clone();
    cvDepthImg2Show.convertTo(cvDepthImg2Show, CV_8U, 255.0 / 4096.0);
    cv::cvtColor(cvDepthImg2Show, cvDepthImg2Show, CV_GRAY2BGR);

    for (int i = 0; i < 15; i ++) {
    // 在深度图像中显示出各个骨骼点
        cv::Point point = draindata.front()->jointPos2D[i];
        if (point.x > 0 && point.y > 0 && point.x < cvDepthImg2Show.cols && point.y < cvDepthImg2Show.rows)
            cv::circle(cvDepthImg2Show, point, 6, cv::Scalar(255,0,0), -1);
    }

    // 画出连线
    cv::line(cvDepthImg2Show, draindata.front()->jointPos2D[0], draindata.front()->jointPos2D[1], cv::Scalar(0,0,128), 2);
    cv::line(cvDepthImg2Show, draindata.front()->jointPos2D[1], draindata.front()->jointPos2D[2], cv::Scalar(0,0,128), 2);
    cv::line(cvDepthImg2Show, draindata.front()->jointPos2D[2], draindata.front()->jointPos2D[4], cv::Scalar(0,0,128), 2);
    cv::line(cvDepthImg2Show, draindata.front()->jointPos2D[4], draindata.front()->jointPos2D[6], cv::Scalar(0,0,128), 2);
    cv::line(cvDepthImg2Show, draindata.front()->jointPos2D[1], draindata.front()->jointPos2D[3], cv::Scalar(0,0,128), 2);
    cv::line(cvDepthImg2Show, draindata.front()->jointPos2D[3], draindata.front()->jointPos2D[5], cv::Scalar(0,0,128), 2);
    cv::line(cvDepthImg2Show, draindata.front()->jointPos2D[5], draindata.front()->jointPos2D[7], cv::Scalar(0,0,128), 2);
    cv::line(cvDepthImg2Show, draindata.front()->jointPos2D[2], draindata.front()->jointPos2D[8], cv::Scalar(0,0,128), 2);
    cv::line(cvDepthImg2Show, draindata.front()->jointPos2D[3], draindata.front()->jointPos2D[8], cv::Scalar(0,0,128), 2);
    cv::line(cvDepthImg2Show, draindata.front()->jointPos2D[8], draindata.front()->jointPos2D[9], cv::Scalar(0,0,128), 2);
    cv::line(cvDepthImg2Show, draindata.front()->jointPos2D[9], draindata.front()->jointPos2D[11], cv::Scalar(0,0,128), 2);
    cv::line(cvDepthImg2Show, draindata.front()->jointPos2D[11], draindata.front()->jointPos2D[13], cv::Scalar(0,0,128), 2);
    cv::line(cvDepthImg2Show, draindata.front()->jointPos2D[8], draindata.front()->jointPos2D[10], cv::Scalar(0,0,128), 2);
    cv::line(cvDepthImg2Show, draindata.front()->jointPos2D[10], draindata.front()->jointPos2D[12], cv::Scalar(0,0,128), 2);
    cv::line(cvDepthImg2Show, draindata.front()->jointPos2D[12], draindata.front()->jointPos2D[14], cv::Scalar(0,0,128), 2);


    cv::flip(cvDepthImg2Show, cvDepthImg2Show, 1);
    if (draindata.front()->isPersonVisable)
        cv::putText(cvDepthImg2Show, "Visiable", cv::Point(100,20), cv::FONT_HERSHEY_PLAIN, 1.5, cv::Scalar(255,0,0), 2);
    else
        cv::putText(cvDepthImg2Show, "Unvisiable!", cv::Point(100,20), cv::FONT_HERSHEY_PLAIN, 1.5, cv::Scalar(255,0,0), 2);
    QImage qDepthImg((const uchar*)cvDepthImg2Show.data, cvDepthImg2Show.cols, cvDepthImg2Show.rows,
                     cvDepthImg2Show.step, QImage::Format_RGB888);
    vars->depth->setPixmap(QPixmap::fromImage(qDepthImg));
    return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMono_Sensor_xtion_Params * params=(VisualizationMono_Sensor_xtion_Params *)paramsPtr;
	VisualizationMono_Sensor_xtion_Vars * vars=(VisualizationMono_Sensor_xtion_Vars *)varsPtr;
    widgets=QList<QWidget *>() << vars->color << vars->depth;
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

