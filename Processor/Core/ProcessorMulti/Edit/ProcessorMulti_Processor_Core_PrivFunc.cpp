//You need to program this file.

#include "../NoEdit/ProcessorMulti_Processor_Core_PrivFunc.h"
#include <cmath>

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	ProcessorMulti_Processor_Core_Params * params=(ProcessorMulti_Processor_Core_Params *)paramsPtr;
	ProcessorMulti_Processor_Core_Vars * vars=(ProcessorMulti_Processor_Core_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
	
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	ProcessorMulti_Processor_Core_Params * params=(ProcessorMulti_Processor_Core_Params *)paramsPtr;
	ProcessorMulti_Processor_Core_Vars * vars=(ProcessorMulti_Processor_Core_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
	
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	ProcessorMulti_Processor_Core_Params * params=(ProcessorMulti_Processor_Core_Params *)paramsPtr;
	ProcessorMulti_Processor_Core_Vars * vars=(ProcessorMulti_Processor_Core_Vars *)varsPtr;
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

void DECOFUNC(initializeOutputData)(void * paramsPtr, void * varsPtr, boost::shared_ptr<void> & outputDataPtr)
{
	ProcessorMulti_Processor_Core_Params * params=(ProcessorMulti_Processor_Core_Params *)paramsPtr;
	ProcessorMulti_Processor_Core_Vars * vars=(ProcessorMulti_Processor_Core_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new SourceDrainMono_Sensor_EncoderIMU_Order_InputData());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

void DECOFUNC(getMultiInputDataSize)(void * paramsPtr, void * varsPtr, QList<int> & inputDataSize)
{
	ProcessorMulti_Processor_Core_Params * params=(ProcessorMulti_Processor_Core_Params *)paramsPtr;
	ProcessorMulti_Processor_Core_Vars * vars=(ProcessorMulti_Processor_Core_Vars *)varsPtr;
	inputDataSize=QList<int>();
	/*======Please Program above======*/
	/*
	Function: get input data size to be grabbed from buffer.
	Rules:
	inputDataSize=0: grab and remove all data from buffer.
	inputDataSize>0: grab inputDataSize latest data from buffer.
	inputDataSize<0: grab and remove inputDataSize ancient data from buffer.
	E.g.
	inputDataSize=QList<int>()<<0<<1<<-1...;
	*/
}

static enum{
    FORWARD = 0,
    BACKWARD,
    TURN
} CAR_STATE;

//Input Port #0: Buffer_Size = 10, Params_Type = SourceDrainMono_Sensor_EncoderIMU_Params, Data_Type = SourceDrainMono_Sensor_EncoderIMU_Data
//Input Port #1: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_URG_Params, Data_Type = SensorTimer_Sensor_URG_Data
//Input Port #2: Buffer_Size = 10, Params_Type = SensorTimer_Sensor_xtion_Params, Data_Type = SensorTimer_Sensor_xtion_Data
bool DECOFUNC(processMultiInputData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > inputParams, QVector<QVector<void *> > inputData, void * outputData, QList<int> & outputPortIndex)
{
	ProcessorMulti_Processor_Core_Params * params=(ProcessorMulti_Processor_Core_Params *)paramsPtr;
	ProcessorMulti_Processor_Core_Vars * vars=(ProcessorMulti_Processor_Core_Vars *)varsPtr;
	QVector<SourceDrainMono_Sensor_EncoderIMU_Params *> inputparams_0; copyQVector(inputparams_0,inputParams[0]);
	QVector<SensorTimer_Sensor_URG_Params *> inputparams_1; copyQVector(inputparams_1,inputParams[1]);
	QVector<SensorTimer_Sensor_xtion_Params *> inputparams_2; copyQVector(inputparams_2,inputParams[2]);
	QVector<SourceDrainMono_Sensor_EncoderIMU_Data *> inputdata_0; copyQVector(inputdata_0,inputData[0]);
	QVector<SensorTimer_Sensor_URG_Data *> inputdata_1; copyQVector(inputdata_1,inputData[1]);
	QVector<SensorTimer_Sensor_xtion_Data *> inputdata_2; copyQVector(inputdata_2,inputData[2]);
	SourceDrainMono_Sensor_EncoderIMU_Order_InputData * outputdata=(SourceDrainMono_Sensor_EncoderIMU_Order_InputData *)outputData;
	outputPortIndex=QList<int>();
	if(inputdata_0.size()==0){return 0;}
	if(inputdata_1.size()==0){return 0;}
	if(inputdata_2.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Step 1: process inputdata_index, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/

    //inputdata_0                                             // EncoderIMU
    //inputdata_1                                             // URG
    //inputdata_2                                             // Xtion (RGB && depth)
    //cv::imshow("color", inputdata_2.front()->cvColorImg);   // Show RGB image
    //cv::imshow("depth", inputdata_2.front()->cvDepthImg);   // Show depth image

    SensorTimer_Sensor_URG_Data *urg = inputdata_1.front();

    double ori = inputdata_0.front()->orientation;
    double unit = inputparams_1.front()->unit;


    short steer = 0;           // [-400, 400]
    short speed = 100;           // [-180, 180]


    // Draw the picture
    static int x_size = 1500, y_size = 800;
    static int step = 0;
    static cv::Mat yaw_image = cv::Mat::zeros(y_size, x_size, CV_8UC3);
    if (step == 0) {
        cv::line(yaw_image, cv::Point(0, y_size / 2), cv::Point(x_size, y_size/ 2), cv::Scalar(255, 255, 255), 1, CV_AA);
    }

    // Parameter
    static const double Kc = 70, Tt = 20000000000, Td = 10;
    static const double FORWARD_STEER = 60;
    static const double FORWARD_SPEED = 120;
    static const double SAFE_DIS = 0.55 , DANGER_DIS = 0.45;
    static const double AVOID_DIS = 0.65;

    // Variables
    static bool is_init = false;
    static double yt, rt, last_et, integ_et, ori_init;

    static int state = FORWARD;

    static double last_steer;

    double side_dis[2];
    side_dis[0] = side_dis[1] = 0;
    for (int i = 0; i < 120; i++) {
        side_dis[0] += urg->data[i] / unit;
        side_dis[1] += urg->data[urg->datasize - i - 1] / unit;
    }
    side_dis[0] /= 120.0;
    side_dis[1] /= 120.0;
    //printf("%.4f %.4f\n", side_dis[0], side_dis[1]);

    double avoid_steer = 0;
    if (side_dis[0] < AVOID_DIS) {
        avoid_steer = -60;
    } else if (side_dis[1] < AVOID_DIS) {
        avoid_steer = 60;
    }

    //qDebug() << side_dis[0] << " " << side_dis[1] <<endl;
    //qDebug() << avoid_steer <<endl;

    double front_dis = 0, front_dis_num = 0;
    int L = urg->datasize / 2 - 30, R = urg->datasize / 2 + 30;
    for (int i = L; i < R; i++) {
        double dis = urg->data[i] / unit;
        //front_dis += dis;
        if (urg->data[i] == 0) continue;
        if (dis < DANGER_DIS) {
            front_dis += dis;
            front_dis_num += 1;
        }
        //double angle = (i - urg->datasize / 2) * (180.0 / urg->datasize) / 180 * M_PI;

        /*
        if (dis < DANGER_DIS) {
           Should_pause = true;
            //printf("Should pause %3f\n", dis);
        } else {
            //printf("Not pause %3f\n", dis);
        }*/
    }
    if (front_dis_num < 1 && front_dis_num > 20) {
        front_dis = 100000;
    } else {
        front_dis /= front_dis_num;
    }

    if (state == FORWARD) {
        bool Should_pause = false;
        if (front_dis < DANGER_DIS)
            Should_pause = true;
        if (Should_pause) {
            puts("Should pause");
            speed = -150;
            steer = last_steer * 1.2;
            state = BACKWARD;

        } else {
            speed = FORWARD_SPEED;
            if (!is_init) {
                rt = ori, last_et = 0, integ_et = 0;
                ori_init = ori;
                is_init = true;
            }
            yt = ori;
            double et = rt - yt, diff_et = et - last_et;
            double ut = Kc * (et + 1 / Tt * integ_et + Td * diff_et);
            integ_et += et;
            rt = yt;
            steer = ut;
            ++step;
            if (step % 2 == 0)
            {
                static double HIGH = 300;
                int y, x = step;
                if ( ori - ori_init > M_PI )
                    y = HIGH * (ori - ori_init - 2 * M_PI) + y_size / 2;
                else if ( ori - ori_init < -M_PI )
                    y = HIGH * (ori - ori_init + 2 * M_PI) + y_size / 2;
                else
                    y = HIGH * (ori - ori_init) + y_size / 2;
                cv::circle(yaw_image, cv::Point(x, y), 1, cv::Scalar(255, 0, 0), 0, CV_AA);
                y = 300 * ut + y_size / 2;
                cv::circle(yaw_image, cv::Point(x, y), 1, cv::Scalar(0, 255, 0), 0, CV_AA);
            }
            imshow("yaw", yaw_image);
            steer += avoid_steer;
        }
    } else if (state == BACKWARD) {
        state = FORWARD;
        /*
        if (front_dis > SAFE_DIS) {
            state = FORWARD;
            speed = FORWARD_SPEED;
            steer = last_steer / 1.2;
            is_init = false;
        } else {
            speed = -150;
        }
        /*
        bool Should_pause = false;
        int L = urg->datasize / 2 - 60, R = urg->datasize / 2 + 60;
        for (int i = L; i < R; i++) {
            double dis = urg->data[i] / unit;
            if (urg->data[i] == 0) continue;
            //double angle = (i - urg->datasize / 2) * (180.0 / urg->datasize) / 180 * M_PI;
            if (dis < 0.25) {
               Should_pause = true;
                //printf("Should pause %3f\n", dis);
            } else {
                //printf("Not pause %3f\n", dis);
            }
        }*/
        //state = FORWARD;
    } else if (state == TURN) {

    }

    last_steer = steer;
    steer += FORWARD_STEER;


    // Show RGB image && compass

    //double ori = - ((double)steer / 400.0) * (M_PI / 2.0);

    cv::Mat img;
    inputdata_2.front()->cvColorImg.copyTo(img);
	cv::flip(img, img, 1);
    cv::Point compass = cv::Point(100, 100);
    cv::circle(img, compass, 80, cv::Scalar(0,255,0), 1, CV_AA);
    cv::line(img, compass,
             cv::Point(compass.x - sin(ori) * 80,
                       compass.y - cos(ori) * 80),
             cv::Scalar(0,255,0), 3, CV_AA);

   cv::imshow("color", img);


    qDebug()<<steer<<'\t'<<speed;
    //--------------------------------------------
    int maxSpeed = 180;
    if (speed > maxSpeed) speed = maxSpeed;
    if (speed < -maxSpeed) speed = -maxSpeed;
    char dataput[20];
    dataput[0] = 0xF8;
    dataput[1] = 4;
    *(short*)&dataput[2] = (short)steer;
    *(short*)&dataput[4] = (short)speed;
    dataput[6] = 0x8F;
    outputdata->datagram = QByteArray(dataput, 7);
	return 1;
}

