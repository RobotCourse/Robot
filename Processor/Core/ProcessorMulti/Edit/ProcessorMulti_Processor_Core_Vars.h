//You need to modify this file.

#ifndef PROCESSORMULTI_PROCESSOR_CORE_VARS_H
#define PROCESSORMULTI_PROCESSOR_CORE_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Processor_Core_Vars ProcessorMulti_Processor_Core_Vars
	\ingroup ProcessorMulti_Processor_Core
	\brief ProcessorMulti_Processor_Core_Vars defines the Vars in ProcessorMulti_Processor_Core.
*/

/*! \addtogroup ProcessorMulti_Processor_Core_Vars
	@{
*/

/*! \file ProcessorMulti_Processor_Core_Vars.h
	 Defines the Vars of ProcessorMulti_Processor_Core
*/

//*******************Please add other headers below*******************


#include "ProcessorMulti_Processor_Core_ParamsData.h"

//The Vars is defined as below
/*! \class ProcessorMulti_Processor_Core_Vars 
	\brief The Vars of ProcessorMulti_Processor_Core.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Processor_Core_Vars 
{
public:
	/*! \fn ProcessorMulti_Processor_Core_Vars()
		\brief The constructor of ProcessorMulti_Processor_Core_Vars. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Processor_Core_Vars() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Processor_Core_Vars()
		\brief The destructor of ProcessorMulti_Processor_Core_Vars. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Processor_Core_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    //定义初始位置坐标，使之与轨迹图坐标对齐，参见配置文件config.xml设置
       double initx;
       double inity;
       double initori;
       //上一帧数据
       double lastx;
       double lasty;
       double lastori;
       short lastpulsenum;//用来判断溢出
       QTime qlasttimestamp;
       bool isInit;//判断是否为首帧数据
       double initOriValue;//航向角初始值
       const double PI=3.1415926535;

};

/*! @}*/ 

#endif
