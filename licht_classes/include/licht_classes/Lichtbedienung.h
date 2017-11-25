#ifndef LICHTBEDIENUNG_H
#define LICHTBEDIENUNG_H
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include "ros/ros.h"
//#include <licht_controls/Lichtyaw.h>
#include "/home/ubuntu/catkin_ws/devel/include/licht_controls/Lichtyaw.h"
#include "/home/ubuntu/catkin_ws/devel/include/licht_controls/data18.h"
#include "/home/ubuntu/catkin_ws/devel/include/licht_controls/Lichtstate.h"

class Lichtradio;
class Lichtgestalt;
typedef std::vector<Lichtgestalt*> LichtgestaltList;
typedef std::vector<Lichtradio*> LichtradioList;

class Lichtradio
{
public:
	Lichtradio(uint32_t addr_l, const char device_name[30]);
	~Lichtradio();
	int SerialOpen(const int baud);
	uint32_t AddDestination(Lichtgestalt * lichtgestalt);
	//returns index of the destination
	void sendPacket(uint8_t * data, uint8_t len);
	
	uint32_t listSize(void);
	void readBuf(std::vector<licht_controls::Lichtyaw> &v_yaw, std::vector<licht_controls::Lichtstate> &v_state, std::vector<licht_controls::data18> &v_data18);

	uint32_t findIndex(uint32_t addr_l);
//private:
	uint32_t _addr_l;
	char _device_name[30];
	int _fd;
	LichtgestaltList _LichtList;
	uint8_t _rcvBuf[1024];
};



#endif
