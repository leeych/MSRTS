// DataStruct.cpp : ̨Ӧóڵ㡣
//

#ifndef _DATA_STRUCT_H_
#define _DATA_STRUCT_H_

#include "macro.h"

#define  MAX_CHANNEL_NAME_LEN        (64)
#define  MAX_MINE_NAME_LEN           (128)
#define  MAX_MINE_STATION_NUM        (64)
#define  MAX_MINE_CHANNEL_NUM        (128)
#define  MAX_RESPONSE_PARAM_NUM      (32)

#define  MAX_STATION_NAME_LEN        (64)
#define  MAX_STATION_COMPANY_LEN     (32)
#define  MAX_STATION_MODEL_LEN       (32)

#define  WAVE_AVALIABLE_FLAG         (0)

#define  WAVE_AUTO_PICKER_FLAG       (1<<0)
#define  WAVE_MANUAL_PICKER_FLAG     (1<<1)
#define  WAVE_THERO_PICKER_FLAG      (1<<2)

typedef unsigned char  byte;


/**  Define of the point in wgs coordinate
 */
typedef struct WgsPointTag
{
	float   latitude;
	float   longitude;
	float   elevation;   /* unit in meter,
							positive value means above sea level
							negative value means below sea leavel
						 */
	WgsPointTag(float lat, float lon, float elev):
		latitude(lat),
		longitude(lon),
		elevation(elev)
	{
	}

	WgsPointTag():
	latitude(UN_INITID_FLOAT),
		longitude(UN_INITID_FLOAT),
		elevation(UN_INITID_FLOAT)
	{
	}

}WgsPoint;

/**  Define of the point in cartesian coordinate
 *   The unit is meter
 */

typedef struct DesPointTag
{
	float x; /* northing location */
	float y; /* easting location */
	float z; /* deep location */
	DesPointTag(float dx, float dy, float dz):
		x(dx),
		y(dy),
		z(dz)
	{

	}

	DesPointTag():
	x(UN_INITID_FLOAT),
		y(UN_INITID_FLOAT),
		z(UN_INITID_FLOAT)
	{

	}
}DesPoint;

/**  Define of the point in utm coordinate
 */
typedef struct UtmPointTag
{
	float x;
	float y;
	float elevation;
	UtmPointTag(float ux, float uy, float elev):
		x(ux),
		y(uy),
		elevation(elev)
	{

	}

	UtmPointTag():
	x(UN_INITID_FLOAT),
		y(UN_INITID_FLOAT),
		elevation(UN_INITID_FLOAT)
	{

	}
}UtmPoint;

/** Define the Point struct used in system
 *
 */
typedef struct PointTag
{
	WgsPoint     wgs_point;
	DesPoint     des_point;
	UtmPoint     utm_point;
}Point;

/** Define the coordinate used in the mine
 *
 */
typedef enum CoordinateTypeTag
{
	COORDINATE_WGS = 0,
	COORDINATE_DES,
	COORDINATE_UTM,
}CoordinateType;

/** Define the mine struct
 *
 */
typedef struct MineInfoTag
{
	int               id;              /* mine id */
	CoordinateType    coordinate_type; /* coordinate used in the mine */
	char              name[MAX_MINE_NAME_LEN]; /* mine name*/
	WgsPoint          orginal;         /* mine position */
	int               station_num;     /* station mine in the mine*/
	int               station_ids[MAX_MINE_STATION_NUM]; /* station id in the mine*/
}MineInfo;

/** Define the complex struct
 *
 */

typedef struct ComplexTag
{
	float    real;
	float    imaginary;
	ComplexTag(float real_part, float imaginary_part):
		real(real_part),
		imaginary(imaginary_part)
	{

	}

	ComplexTag():
	real(UN_INITID_FLOAT),
		imaginary(UN_INITID_FLOAT)
	{

	}

}Complex;

/** Define the binary time struct
 *
 */
typedef struct BTimeTag
{
	short     year;
	byte      month;
	byte      day;
	short     jday;     /*day in current year*/
	byte      hour;
	byte      minute;
	byte      second;
	byte      padding;  /*not used, always 0*/
	short     tenth_ms; /*count in tenth milli-seconds*/
}BTime;

/** Define the response information
 *
 */
typedef struct ResponseInfoTag
{
	int        zero_num;     /*zero point num*/
	Complex    zeros[MAX_RESPONSE_PARAM_NUM];

	int        pole_num;    /* pole point num*/
	Complex    poles[MAX_RESPONSE_PARAM_NUM];

	float      gain;        /* multiplier*/
}ResponseInfo;

typedef enum ChannelCompenentTag
{
	COMPONENT_NORTHING = 0,
	COMPONENT_EASTING,
	COMPONENT_DEEP,
	COMPONENT_REVERSED,
	COMPONENT_NUM
}ChannelComponent;

/** Define the channel information
 *
 */
typedef struct ChannelInfoTag
{
	int   id;            /* channel id*/
	char  name[MAX_CHANNEL_NAME_LEN]; /* channel name */
	int   station_id;    /* station id of current channel*/
	Point  position;     /* channel position*/
	float azimuth;
	float dip;

	float   max_clock_drift;
	float   sample_rate;

	ResponseInfo response_info;

	bool  triggered;    /* the channel is used for trigger */
	byte  component;    /* channel component
						   0   northing
						   1   easting
						   2   deep
						   3   reserved
						*/
	byte  sample_data_type; /* sample data type
							   0  int
							   1  short
							   2  ieee float
							   3  ibm float
							   4  reserved
							*/
	byte  byte_order;      /* byte order
							  0 little endian
							  1 big    endian
						   */
}ChannelInfo;

/** Define the station information
 *
 */
typedef struct StationInfoTag
{
	int     id;     /* station id */
	char    name[MAX_STATION_NAME_LEN];  /* station name */
	int     mine_id;
	char    company[MAX_STATION_COMPANY_LEN]; /* company name */
	char    model[MAX_STATION_MODEL_LEN];     /* station model*/

	Point   position;                         /* station position */

	int     type;          /* station type
							  0  speed
							  1  acceleration
							  2  displacement
							  4  reversed
						   */

	int     flags;        /*  station flags
							 bit0  whether used for location
							 bit1  whether used for calculate hypo center
							 bit2  whether used for calculate moment tensor
						  */

	int     channel_num;  /* channel num in current station */
	int     channel_ids[COMPONENT_NUM]; /* channel's ids */
}StationInfo;

/** Define the waveform picker information
 *
 */
typedef struct PickerInfoTag
{
	int   start_position;    /* the picker start position */
	int   end_position;      /* the picker end position */
	float azimuth;
	float dip;
	float azimuth_error;
	float dip_error;
	float weight;           /* picker weight */
	byte  polarity;
	byte  polarity_quality;
	byte  quality;
	byte  padding;          /* padding byte, always 0*/

	PickerInfoTag():
	start_position(UN_INITID_INT),
	end_position(UN_INITID_INT),
	azimuth(UN_INITID_FLOAT),
	dip(UN_INITID_FLOAT),
	azimuth_error(UN_INITID_FLOAT),
	dip_error(UN_INITID_FLOAT),
	weight(UN_INITID_FLOAT),
	padding(0)
	{

	}

	PickerInfoTag(int start, int end, float azimuth_value, float dip_value,
		float azimuth_error_value, float dip_error_value,
		float weight_value,
		byte plrt, byte plrt_q, byte q):
	start_position(start),
	end_position(end),
	azimuth(azimuth_value),
	dip(dip_value),
	azimuth_error(azimuth_error_value),
	dip_error(dip_error_value),
	weight(weight_value),
	polarity(plrt),
	polarity_quality(plrt_q),
	quality(q),
	padding(0)
	{

	}

}PickerInfo;

/** Define the raw wave information
 *
 */
typedef struct WaveRawDataTag
{
	int       id;           /* raw wave id */
	int       channel_id;   /* channel id */

	int       flags;        /* wave flags
							   0   wave un-processed
							   1   wave is compressed
							*/


	BTime     start_time;  /* wave start time */
	BTime     end_time;    /* wave end time */

	float     sample_rate;
	int       sample_num;

	float*    data;        /* wave data */
}WaveRawData;

/** Define the data of processed wave information
 *
 */

typedef struct WaveProcDataTag
{
	int            id;            /* wave processed data id */
	int            wave_id;       /* raw wave id */
	int            channel_id;    /* channel id */
	float          p_residual;    /* unit in microseconds*/
	float          s_residual;    /* unit in microseconds*/
	float          noise;
	float          f_max_amp;    /* frequency in max amp*/
	float          p_max_amp;
	float          s_max_amp;
	float          sp_amp;

	int            processor;    /* processor id */
	int            flags;        /* wave processed data flag
									bit0  whether wave is rejected
								 */
	int         quality_flags;  /* quality flag
								   bit0   waveform auto picked
								   bit1   waveform manual picked
								   bit2   waveform calculate theoritical picker information
								*/
	PickerInfo  p_auto_picker;
	PickerInfo  p_manual_picker;
	PickerInfo  p_theoretical_picker;
	PickerInfo  s_auto_picker;
	PickerInfo  s_manual_picker;
	PickerInfo  s_theoretical_picker;
}WaveProcData;

/** Define the data of processed wave information
 *
 */
typedef struct StationProcDataTag
{
	int            station_id;            /* station id */
	int            location_algorithm;    /* location algorithm
											 0
											 1
											 2
										  */
	float          distance;              /* distance from hypo center to station*/
	int            flags;                 /*  station process data flag
											  bit[0]  whether accepted
										  */
	BTime          trigger_time;          /* station trigger time */
	BTime          end_time;              /* station event end time */
}StationProcData;

/** Define the hypo center information
 *
 */
typedef struct HypocenterInfoTag
{
	int       id;
	int       event_id;
	BTime     origin_time;
	Point     position;
	float     duration;

	float     azimuth_largest;
	float     dip_largest;
	float     size_largest;

	float     azimuth_intermidate;
	float     dip_intermidate;
	float     size_intermidate;

	float     horizontal_error;
	float     vertical_error;

	float     p_rms_travel_time_residual;
	float     s_rms_travel_time_residual;

	float     azimuth_gap;

	float     p_corner_frequency;
	float     s_corner_frequency;
	float     radius;
	float     rupture_time;
	float     mw;
	float     ml;
	float     mb;
	float     ms;
	float     max_displacement;
	float     max_slip_velocity;

	float     stress_drop;
	float     apparent_stress;

	float     strike;
	float     dip;
	float     rake;
	float     iso;
	float     dc;
	float     clvd;
	float     m0;
	int       npt;
	int       nst;
	float     energy;
	float     moment_tensor[3][3];
}HypocenterInfo;

/** Define event information
 *
 */

typedef struct EventInfoTag
{
	int                 id;      /* event id*/
	int                 type;    /* event type
								   0  noise
								   1  micro seismic
								   2  burst
								   4  reversed
								 */

	BTime               trigger_time; /* event trigger time */
	BTime               last_change_time; /* event last change time */

	HypocenterInfo      hypo_info;

	int                 wave_num;   /* event raw wave num */
	int                 wave_proc_datas[MAX_MINE_CHANNEL_NUM];  /* wave processed data ids */

	int                 station_proc_data_num; /* event station num */

	StationProcData     station_proc_datas[MAX_MINE_STATION_NUM]; /* event station processed data ids */
}EventInfo;


#define  MAKE_WGS_POINT(lat, lon, elev)    WgsPointTag(lat, lon, elev)
#define  MAKE_DES_POINT(x, y, z)           DesPointTag(x, y, z)
#define  MAKE_UTM_POINT(x, y, elev)        UtmPoint(x, y, elev)

#define  MAKE_COMPLEX(real, imaginary)     ComplexTag(real, imaginary)


#endif /* _DATA_STRUCT_H_ */


